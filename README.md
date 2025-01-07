# Snake and Ladder Game Simulation with Pathfinding (BFS)

## Overview
This project implements a console-based Snake and Ladder game in C++ where two players roll dice and move on a board. The game also uses a **Breadth-First Search (BFS)** algorithm to find the shortest path from the start to the finish, considering snakes and ladders. The project includes **input validation** to ensure valid dice rolls and handles invalid user input gracefully.

## Features
- **Game Simulation:** Two players take turns rolling a dice, navigating through a snake-and-ladder board.
- **Pathfinding Algorithm (BFS):** Calculates the shortest path to the finish using BFS, while considering snakes and ladders.
- **Input Validation:** Ensures dice rolls are between 1 and 6 and handles invalid input.
- **Interactive Console-based Game:** The game continues until a player reaches the destination.

## How it Works
1. **Graph Representation:** The board is represented as a graph where each node corresponds to a position on the board. The edges represent possible moves based on the dice rolls (1 to 6).
2. **BFS Algorithm:** BFS is used to find the shortest path from the start (position 0) to the destination (position 36), considering the effects of snakes and ladders.
3. **Ladders and Snakes:** Ladders move players forward, and snakes move players backward on the board.
4. **Player Turns:** Players alternate taking dice rolls, and the first player to reach position 36 wins.

## Game Flow
1. The game starts with both players at position 0.
2. Each player rolls the dice (between 1 and 6), and their position is updated accordingly.
3. The game continues until one of the players reaches position 36, at which point the game ends with that player winning.

## Installation
1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/yourusername/snake-and-ladder-game.git

   
