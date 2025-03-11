# Overview of the Fruit Game
- The game board is a 10x10 grid where:
  - EMPTY cells are represented by spaces.
  - FRUIT cells are represented by "o" symbols.
  - The BASKET is represented by "|_|".
- The player moves the basket left (a/A), right (d/D), or stays in place (s/S). They can also quit the game with (x/X).

## Key Functions and Logic
### 1. initBoard()
- Initializes the board by setting all cells to EMPTY.
- Places the basket at the bottom center of the board.

### 2. printBoard()
- Draws the game board using ASCII characters.
- Iterates through each cell and prints the appropriate symbol for EMPTY, FRUIT, or BASKET.

### 3. inputAction()
- Prompts the user to enter a movement key (a, s, d, or x).
- Validates the input to ensure it's one of the accepted characters.

### 4. updateBasket()
- Finds the basket’s position by scanning the bottom row.
- Moves the basket left or right based on the user’s action.

### 5. updateFruits()
- Handles the movement and scoring for fruits.
- Checks if fruits in the second-to-last row (the row above the basket) have been caught or dropped:
  - If a fruit lands directly above the basket, the score increases.
  - If a fruit lands on the ground without being caught, the score decreases.
- Moves all other fruits down by one row.
- Randomly generates new fruits in the top row with a 1-in-3 chance.
