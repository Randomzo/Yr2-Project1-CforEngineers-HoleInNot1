# Yr2-Project1-CforEngineers-HoleInNot1
"A C-based mini-golf game demonstrating ball physics, friction, and interactive terrain. Developed for educational purposes under DCU guidelines, with dependencies excluded."
# Mini-Golf Game Project

This repository contains the Mini-Golf Game, a project developed for the EEN1021 (EE219) Assignment 2025. The game simulates the physics of a golf ball moving through various terrains, incorporating elements such as friction, collision detection, and randomized ball motion.

This project was developed as part of my learning experience in **programming and game physics**, where I applied theoretical concepts to create an interactive and animated game. 

---

## Project Description

The Mini-Golf Game demonstrates:
- **Physics-based simulation**: The ball's movement is influenced by friction coefficients for different terrains, including grass and rivers.
- **Interactive gameplay**: Players control the ball by taking strokes, with randomized speed and direction.
- **Collision detection**: This ensures the ball stays within the course's bounds or bounces back when hitting edges.
- **Game elements**:
  - A hole where the player aims to land the ball.
  - Terrain obstacles, including a river that alters the ball's behaviour.

The game aims to sink the ball into the hole with the fewest strokes while dealing with the terrain and random motion. 

---

## Development Notes

### Key Features:
1. **Terrain Interaction**:
   - Grass and river terrains affect the ball's motion differently, thanks to predefined friction coefficients.

2. **Randomized Ball Movement**:
   - Each stroke generates a random speed and angle for the ball's movement, adding unpredictability to the game.

3. **Scoring System**:
   - Tracks the number of strokes taken by the player.
   - Declares victory when the ball lands in the hole.

4. **Animation and Effects**:
   - Smooth animations for ball movement.
   - Fun messages, such as "Just Kick It!" and "I am a striker!" during gameplay.

---

## Challenges and Optimizations

### Challenges:
- Performance issues with canvas size and rendering.
  - To address this, I reduced the canvas dimensions and adjusted visual elements like the ball and hole size.

- Complex logic for friction, collisions, and ball movement.
  - Simplified the calculations while maintaining the game's core mechanics.

### Limitations:
- The game design is simplified to avoid memory issues and long render times.
- The GeoDraw library, which is required for graphics, is **not included in this repository** as per DCU's guidelines.

---
