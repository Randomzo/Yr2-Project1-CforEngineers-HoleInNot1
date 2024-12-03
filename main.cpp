//This is a program to show an animation worth 70%
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Ball parameters and course setup
double ballpx = 37.5, ballpy = 37.5;  // Ball initial position (tee box)
double vX = 0, vY = 0;               // Ball velocity
int strokes = 0;                      // Stroke counter

// Constants for friction, walls, terrain, and river
const double Gfriction = 0.9;         // Grass friction
const double Rfriction = 0.85;        // River friction
double friction = Gfriction;

//canvas and hole size
const int canvasWidth = 350;
const int canvasHeight = 315;
const double holeRadiusBall = 12;
const double holePosX = 210;
const double holePosY = 175;
const int riverStartX = 140;
const int riverWidth = 35;

// Setup functions
void setupCourse1() {
    gd_resetCanvasSize(canvasWidth, canvasHeight);  // Set canvas size
    gd_setCanvasColor(DARK_GREEN);                  // Set background to green (grass)
    gd_clear();                                     // Clear the canvas
}

void drawRiver() {
    gd_setFillColor(BLUE);  // blue
    gd_quadFilled(riverStartX, 0, riverStartX + riverWidth, 0,
                  riverStartX + riverWidth, canvasHeight, riverStartX, canvasHeight);  // river
}

void drawHole1() {
    gd_setFillColor(BLACK);
    gd_circleFilled(holePosX, holePosY, holeRadiusBall);  // hole
}

void applyFriction() {
    vX *= friction;
    vY *= friction;
}

void drawBall() {
    // Drawing the ball
    gd_setPenColor(BLACK);
    gd_setPenWidth(5);
    gd_circle(ballpx, ballpy, 5);
    gd_setFillColor(WHITE);
    gd_circleFilled(ballpx, ballpy, 5);

    // Display stroke counter
    gd_setTextAlignment(LEFT);
    gd_setTextColor(WHITE);
    gd_setTextSize(10);
    char strokeText[50];
    sprintf(strokeText, "Strokes: %d", strokes);
    gd_text(strokeText, 5, 10);
}

int isBallInHole() {
    double distance = sqrt(pow(ballpx - holePosX, 2) + pow(ballpy - holePosY, 2));
    return (distance <= holeRadiusBall -2);  //
}

void edgeMap() {
    if (ballpx <= 0 || ballpx >= canvasWidth) {
        vX = -vX * 2;  // Bounce off X walls
    }
    if (ballpy <= 0 || ballpy >= canvasHeight) {
        vY = -vY * 2;  // Bounce off Y walls
    }
}

void strokeBall() {
    double angle = (rand() % 360) * (PI / 180.0);  // Random angle in radians
    double speed = (rand() % 10) + 1;              // Random speed between 1 and 10
    vX = speed * cos(angle);
    vY = speed * sin(angle);
    strokes++;  // Increment stroke counter
}

double getFriction(double x, double y) {
    if (x >= riverStartX && x <= riverStartX + riverWidth) {
        return Rfriction;  // River
    }
    return Gfriction;  // Grass
}

void JustKI(int show) {
    if (show) {
        gd_setTextAlignment(CENTER);  // Set up text properties
        gd_setTextColor(WHITE);
        gd_setTextSize(30);
        gd_text("!!!Just Kick it!!!", ballpx, ballpy - 15);  // above ball
    }
}


void showStrikerMessage(int show) {
    if (show) {
        gd_setTextAlignment(CENTER);
        gd_setTextColor(MAGENTA);  // yellow
        gd_setTextSize(20);  // Set a large text size
        gd_text("I am a !!!!????striker????!!!!", canvasWidth / 2, canvasHeight / 2 - 50);
    }
}

void moveBall() {
    int justKickFlag = 0;  // Flag to control "Just Kick It" message display
    int justKickTimer = 0; // Timer to control how long the message is shown

    int strikerFlag = 0;  // Flag to control "I am a striker" message display
    int strikerTimer = 0; // Timer to control how long the message is shown

    // Loop as long as the ball has velocity or the ball isn't in the hole
    while ((fabs(vX) > 0.1 || fabs(vY) > 0.1) && !isBallInHole()) {
        gd_clear();
        drawHole1();
        drawRiver();

        // Update ball position with smaller increments (increased distance by 50% instead of 100%)
        ballpx += vX * 1.25;
        ballpy += vY * 1.25;

        // Apply friction based on position
        friction = getFriction(ballpx, ballpy);
        applyFriction();

        // Handle collisions with the edges of the map
        edgeMap();


        drawBall();

        // Check if strokes are a multiple of 5 and display "Just Kick It"
        if (strokes % 5 == 0 && strokes > 0) {
            justKickFlag = 1;  // Enable the "Just Kick It" flag
            justKickTimer = 30;  // Display the message for 30 iterations (around 1 second)
        }

        // Show "Just Kick It" message if the flag is enabled
        if (justKickFlag) {
            JustKI(1);  // Show message
            justKickTimer--;  // Decrease timer

            // Disable the flag when the timer ends
            if (justKickTimer <= 0) {
                justKickFlag = 0;
            }
        } else {
            JustKI(0);  // Do not show message
        }

        // Check if strokes are a multiple of 10 and display "I am a striker"
        if (strokes % 10 == 0 && strokes > 0) {
            strikerFlag = 1;  // Enable the striker flag
            strikerTimer = 30;  // Display the message for 30 iterations (around 1 second)
        }

        // Show the striker message if the flag is enabled
        if (strikerFlag) {
            showStrikerMessage(1);  // Show striker message
            strikerTimer--;  // Decrease timer

            // Disable the flag when the timer ends
            if (strikerTimer <= 0) {
                strikerFlag = 0;
            }
        } else {
            showStrikerMessage(0);  // Do not show message
        }

        gd_pause(30);  // Animation delay 30frames per second roughly

        // Break out of loop if ball is in the hole
        if (isBallInHole()) {
            break;
        }
    }

    // Save the canvas after moving the ball
    gd_save("gCourse1.html");
}


void animatedball() {
    setupCourse1();
    drawHole1();
    drawRiver();

    while (!isBallInHole()) {
        strokeBall();
        moveBall();
    }


    gd_clear();
    drawHole1();
    drawRiver();
    drawBall();

    gd_setTextAlignment(CENTER);
    gd_setTextColor(WHITE);
    gd_setTextSize(15);
    char result[50];
    sprintf(result, "You won with your goal! Total strokes: %d", strokes);
    gd_text(result, canvasWidth / 2, canvasHeight / 2);
    gd_save("gCourse1.html");

    printf("You won with your goal! Total strokes: %d\n", strokes);
}

int main() {
    setupCourse1();
    animatedball();
    return 0;
}
