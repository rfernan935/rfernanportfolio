/******************************************************************************

Rebecca Fernandez's Fruits and Basket Video Game

Contacts
Email: rfernan2@ramapo.edu
LinkedIn: www.linkedin.com/in/rebeccafernandez935

*******************************************************************************/
#include <iostream>

using namespace std;

// symbolic constants
    const unsigned short FRUIT = 1, BASKET = 2, EMPTY = 0;
    const unsigned short ROWS = 10, COLS = 10;
    
// prototypes
void initBoard( unsigned short board[][COLS],
                unsigned short numRows, unsigned short numCols );
void printBoard( const unsigned short board[][ COLS ],
            unsigned short numRows, unsigned short numCols );
char inputAction();
                
void updateBasket( unsigned short board[][ COLS ],
            unsigned short numRows, unsigned short numCols, char action );
short updateFruits( unsigned short board[][ COLS ],
            unsigned short numRows, unsigned short numCols, char action );

int main()
{
    // symbolic constants
    char action;
    
    // variable declarations
    unsigned short board[ ROWS ][ COLS ];
    short score;
    
    // set up the board
    initBoard( board, ROWS, COLS );
    
    // display the board
    printBoard( board, ROWS, COLS );
    
    // game loop
    action = inputAction();
    score = 0;
    while( 'x' != action )
    {
        // process action
        // update fruits
        score += updateFruits( board, ROWS, COLS, action );
        cout << "Current score: " << score << endl;
        
        // update basket
        updateBasket( board, ROWS, COLS, action );
        
        // print board
        printBoard( board, ROWS, COLS );
        
        // update action
        action = inputAction();
    }
    
    // print the score
    cout << "Your final score is " << score << endl;
    return 0;
}

// initialize the board
void initBoard( unsigned short board[][COLS],
                unsigned short numRows, unsigned short numCols )
{
    // variable declarations
    unsigned short row, col;
    
    // initialize the board to EMPTY
    for( row = 0; row < numRows ; ++ row )
    {
        
        for( col = 0; col < numCols; ++ col )
        {
            board[ row ][ col ] = EMPTY;
        }
    }
    
    // initialize the BASKET
    board[ numRows - 1 ][ numCols / 2 ] = BASKET;
    
    // return
    return;
}

// function to display the board
void printBoard( const unsigned short board[][ COLS ],
            unsigned short numRows, unsigned short numCols )
{
    // variable declarations
    unsigned short row, col;
    
    // draw a line on top
    for( col = 0; col < numCols; ++ col )
    {
        cout << "_ _";        
    }
    cout << "_ _" << endl;
    
    // print the board
    for( row = 0; row < numRows ; ++ row )
    {
        cout << "|";
        for( col = 0; col < numCols; ++ col )
        {
            switch( board[row][col] )
            {
                case EMPTY: cout << "   ";
                    break;
                case FRUIT: cout << " o ";
                    break;
                case BASKET: cout << "|_|";
                    break;
            }
        }
        cout << "|" << endl;
    }
    
    // draw a line at the bottom
    for( col = 0; col < numCols; ++ col )
    {
        cout << "_ _";
    }
    
    // return
    return;
}

// function to read left/right/quit from user
char inputAction()
{
    // variable declarations
    char action;
    
    // input a/d/x and validate
    do
    {
        cout << endl << "Enter a/A for left, s/S for stay, d/D for right, x/X to quit \n";
        cin >> action;
        action = tolower( action );
    }while( !( 'a' == action || 's' == action || 'd' == action || 'x' == action ) );
    
    // return
    return action;
}

// function to update the basket
void updateBasket( unsigned short board[][ COLS ],
            unsigned short numRows, unsigned short numCols, char action )
{
    // variable declarations
    unsigned short col;
    
    // find the column of the basket
    for( col = 0; col < numCols && board[ numRows - 1 ][col] != BASKET; ++col )
    {
        // do nothing
    }
    
    // update the basket based on the action
    switch( action )
    {
        case 'a': if( col > 0)
                  {
                    board[ numRows - 1][col - 1] = BASKET;
                    board[ numRows - 1][col] = EMPTY;
                  }
                break;
        case 'd': if( col < numCols - 1 )
                  {
                     board[ numRows - 1][col + 1] = BASKET;
                     board[ numRows - 1][col] = EMPTY; 
                  }
                break;
    }
    
    //return
    return;
}

// function to update fruits
short updateFruits( unsigned short board[][ COLS ],
            unsigned short numRows, unsigned short numCols, char action )
{
    // symbolic constants
    const unsigned short NEW_FRUIT = 3;
    
    // variable declarations
    short newFruit, row, col, score;
    
    // calculate score for the penultimate row
    score = 0;
    for( col = 0; col < numCols; ++col )
    {
        if( board[ numRows - 2 ][col])
        {
            if( board[numRows - 1][col] )
            {
                // if a friut reaches the basket, increase score by 1
                ++score;
                cout << "You caught a fruit! Score + " << score << endl;
            }
            else
            {
                // if a fruit reches ground reduce score by 1
                --score;
                cout << "You dropped a fruit! Score " << score << endl;
            }
            // delete the fruit but do not add it to the last row
            board[ numRows - 2][col] = EMPTY;
        }
    }
    
    // drop all the other fruits down by one row
    for( row = numRows - 3 ; row >= 0 ; --row )
    {
        for( col = 0; col < numCols; ++col )
        {
            if( board[ row ][ col ])
            {
                board[row][col] = EMPTY;
                board[row + 1][col] = FRUIT;
            }
        }
    }
    
    // decide whether a new friut must be created
    newFruit = rand() % NEW_FRUIT + 1;
    
    if( 1 == newFruit )
    {
        // if so, decide where to generate the fruit
        board[ 0 ][ rand() % numCols ] = FRUIT;
    }
    
    // return the score
    return score;
}
