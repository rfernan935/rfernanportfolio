/******************************************************************************

Rebecca Fernandez's Stock Market Simulator

Contacts
Email: rfernan2@ramapo.edu
LinkedIn: www.linkedin.com/in/rebeccafernandez935

*******************************************************************************/
#include <iostream>
#include <cstdlib>

using namespace std;

// Symbolic constants
    const short MAX_MENU_CHOICE = 5,
                MAX_STOCKS = 10;
    const string STOCK_NAMES[ MAX_STOCKS ] =
    { "Apple Inc", "Microsoft Corporation", "American Express Co", 
      "Cisco Systems Inc", "Home Depot Inc", "Intel Corp", "Johnson and Johnson",
      "McDonald's Corp", "Nike Inc", "Walmart Inc" };

// Prototypes
float inputCashInvestment( float cashBalance );
void printMenu();
short inputMenuChoice(const string STOCK_NAMES[], float currentSharePrice[] );
void printBuyMenu( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[] );
short inputBuyMenuChoice( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[] );
short inputBuyQuantity( short buyMenuChoice, short buyQuantity, float currentSharePrice[], float cashBalance );
short buyUpdateTotalShares( short buyMenuChoice, short buyQuantity, short totalShares[] );
float buyUpdateCashBalance( short buyMenuChoice, short buyQuantity, short totalShares[], float currentSharePrice[], float cashBalance );
short inputSellMenuChoice( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[] );
short inputSellQuantity( short sellMenuChoice, short sellQuantity, short totalShares[], float cashBalance );
short sellUpdateTotalShares( short sellMenuChoice, short sellQuantity, short totalShares[] );
float sellUpdateCashBalance( short sellMenuChoice, short sellQuantity, short totalShares[], float currentSharePrice[], float cashBalance );
void printCurrentHoldings( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[], float cashBalance );
float initializeSharePrice( float currentSharePrice[]);
float updateSharePrice( float currentSharePrice[] );
void finalReport( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[], float lowestPrice[], float highestPrice[], float cashBalance );

int main()
{
    // Symbolic constants
    
    // Variable declarations
    short menuChoice, buyQuantity, sellQuantity, buyMenuChoice, sellMenuChoice, count;
    short totalShares[ MAX_STOCKS ] = { 0 } ;
    float cashInvestment,
          cashBalance = 0,
          lowestPrice[MAX_STOCKS],
          highestPrice[MAX_STOCKS];
    float currentSharePrice[ MAX_STOCKS ] = { 0 };
   
    // Initialize currentSharePrice
        currentSharePrice[MAX_STOCKS] = initializeSharePrice( currentSharePrice );

    // Initialize lowestPrice and highestPrice
    for (count = 0; count < MAX_STOCKS; count++)
    {
        lowestPrice[count] = currentSharePrice[count];
        highestPrice[count] = currentSharePrice[count];
    }
    
    // Input initial cash investment
    cout << "Welcome to Rebecca Fernandez's stockbroker simulation program" << endl;
    cashBalance = cashBalance + inputCashInvestment( cashBalance );
    
    
    // Begin menu loop
    menuChoice = inputMenuChoice(STOCK_NAMES, currentSharePrice);
    while( menuChoice != MAX_MENU_CHOICE)
    {
       // go to chosen menu page
        switch( menuChoice )
        {
            case 1: buyMenuChoice = inputBuyMenuChoice( STOCK_NAMES, totalShares, currentSharePrice );
                    buyQuantity = inputBuyQuantity( buyMenuChoice, buyQuantity, currentSharePrice, cashBalance );
                    totalShares[ MAX_STOCKS ] = buyUpdateTotalShares( buyMenuChoice, buyQuantity, totalShares );
                    cashBalance = buyUpdateCashBalance( buyMenuChoice, buyQuantity, totalShares, currentSharePrice, cashBalance );
                break;
            case 2: sellMenuChoice = inputSellMenuChoice( STOCK_NAMES, totalShares, currentSharePrice );
                    sellQuantity = inputSellQuantity( sellMenuChoice, sellQuantity, totalShares, cashBalance );
                    totalShares[ MAX_STOCKS ] = sellUpdateTotalShares( sellMenuChoice, sellQuantity, totalShares );
                    cashBalance = sellUpdateCashBalance( sellMenuChoice, sellQuantity, totalShares, currentSharePrice, cashBalance );
                break;
            case 3: cashBalance = inputCashInvestment( cashBalance );
                break;
            case 4: printCurrentHoldings( STOCK_NAMES, totalShares, currentSharePrice, cashBalance )
;
                break;
            case MAX_MENU_CHOICE:
                break;
        }
        
        // update share price
        if(menuChoice != MAX_MENU_CHOICE)
        {
             // update share price
                currentSharePrice[ MAX_STOCKS ] = updateSharePrice( currentSharePrice );

            // update highest price
             for (count = 0; count < MAX_STOCKS; count++)
            {
                if(currentSharePrice[count] > highestPrice[count])
                {
                    highestPrice[count] = currentSharePrice[count];
                }
            }
            
            // update lowest price
            for (count = 0; count < MAX_STOCKS; count++)
            {
                if(currentSharePrice[count] < lowestPrice[count])
                {
                    lowestPrice[count] = currentSharePrice[count];
                }
            }
        }
                
        // ask for the next menu choice
        menuChoice = inputMenuChoice(STOCK_NAMES, currentSharePrice);

    }
    
    //print final report upon quit
    finalReport(STOCK_NAMES, totalShares, currentSharePrice, lowestPrice, highestPrice, cashBalance );
    
    return 0;
}

// Funtion to print menu
void printMenu()
{
    // Symbolic constants
    
    // Variable delarations

    // Output menu
    cout << endl
         << "Here are your options:" << endl
         << "1. Buy shares" << endl
         << "2. Sell shares" << endl
         << "3. Add cash to the account (minimum $100)" << endl
         << "4. Print current holdings" << endl
         << "5. Quit" << endl << endl;
    
    // exit menu
    return;
}    
    
// Function to input menu option
short inputMenuChoice(const string STOCK_NAMES[], float currentSharePrice[])
{
    // Symbolic constants
    
    // Variable delarations
    short menuChoice, count;
    
    //Print current stock prices
    cout << "Current Stock Prices:" << endl;
    for( count = 0 ; count < MAX_STOCKS ; count++ )
    {
        cout << count + 1 << ". " << STOCK_NAMES[ count ] << ":  current price = $" << currentSharePrice[ count ] << endl;
    }

    // call print menu
    printMenu();
    
    // Input menu choice
    do
    {
        cout << "Please enter your selection (1-5)" << endl;
        cin >> menuChoice;
        cout << endl;
    }while( !( menuChoice >= 1 && menuChoice <= MAX_MENU_CHOICE ));
    
    // Return menu choice
    return menuChoice;
}

// Function for option 3 (add cash): to compute cash balance after investment
float inputCashInvestment( float cashBalance )
{
    // Symbolic constants
    const short MIN_CASH_INVESTMENT = 100;

    // Variable declarations
    float cashInvestment;
    
    // input and validate cash investment
    do
    {
        cout << "Please enter your cash investment (at least $" 
        << MIN_CASH_INVESTMENT << ") " << endl << "$";
        cin >> cashInvestment;
        cout << endl;
        if( !(cashInvestment >= MIN_CASH_INVESTMENT ))
        {
            cout << "Value is less than $" << MIN_CASH_INVESTMENT
            << ", please try again." << endl;
        }
    }while( !(cashInvestment >= MIN_CASH_INVESTMENT ));
    
    // compute cash balance
    cashBalance = cashInvestment + cashBalance;
    
    // output cash balance
    cout.setf( ios::fixed );
    cout.precision( 2 );
    cout << "Your current cash balance is $" << cashBalance << endl << endl;
    
    // Return cash balance
    return cashBalance;
}

// Function for option 1(buy): buy menu
void printBuyMenu( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[] )
{
    // Variable declarations
    unsigned short count;
    
    // output report
     for( count = 0 ; count < MAX_STOCKS ; count++ )
    {
        cout << count + 1 << ". " << STOCK_NAMES[ count ] << ": " << totalShares[ count ]
        << " owned, current price = $" << currentSharePrice[ count ] << endl;
    }
    
    //Return
    return;
}

// Function for option 1 (buy): to input buy menu option
short inputBuyMenuChoice( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[] )
{
    // Variable delarations
    short buyMenuChoice;
    
    // call print menu
    printBuyMenu( STOCK_NAMES, totalShares, currentSharePrice );
    
    
    // Input menu choice
    do
    {
        cout << "Please enter your selection of stock to purchase (1-10)" << endl;
        cin >> buyMenuChoice;
        cout << endl;
    }while( !( buyMenuChoice >= 1 && buyMenuChoice <= MAX_STOCKS ));
    
    // convert buy menu choice to array number
    buyMenuChoice = buyMenuChoice - 1 ;
    
    // Return menu choice
    return buyMenuChoice;
}

// Function for option 1 (buy): to input and validate quantity of chosen share to buy
short inputBuyQuantity( short buyMenuChoice, short buyQuantity, float currentSharePrice[], float cashBalance )
{
    // input and validate buy quantity
    do
    {
        cout << "How many shares of " << STOCK_NAMES[ buyMenuChoice ] << " would you like to buy?" << endl;
        cin >> buyQuantity;
        cout << endl;
        
        if( !(cashBalance >= currentSharePrice[ buyMenuChoice ] * buyQuantity))
        {
            cout << "Sorry, you do not have enough cash to buy " << buyQuantity << " shares." << endl;
        }
        
    }while( !(cashBalance >= currentSharePrice[ buyMenuChoice ] * buyQuantity ));
    
    // return buy quantity
    return buyQuantity;
}
    
//function for option 1 (buy): calculate total shares after buying    
short buyUpdateTotalShares( short buyMenuChoice, short buyQuantity, short totalShares[] )
{
    // calculate total shares
    totalShares[ buyMenuChoice ] = buyQuantity + totalShares[ buyMenuChoice ];
    
    //return total shares
    return totalShares[ buyMenuChoice ];
}    
    
//function for option 1 (buy): calculate cash balance after buying
float buyUpdateCashBalance( short buyMenuChoice, short buyQuantity, short totalShares[], float currentSharePrice[], float cashBalance )
{
    // calculate cash balance after buying
    cashBalance = cashBalance - (currentSharePrice[ buyMenuChoice ] * buyQuantity);
    
    // print total cost and current cash balance
    cout << "The cost of your purchase is $" << buyQuantity * currentSharePrice[ buyMenuChoice ] << endl;
    
    // return total shares
    return cashBalance;
}


// Function for option 2 (sell): sell menu
void printSellMenu( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[] )
{
    // Variable declarations
    unsigned short count;
    
    // output report
     for( count = 0 ; count < MAX_STOCKS ; count++ )
    {
        cout << count + 1 << ". " << STOCK_NAMES[ count ] << ": " << totalShares[ count ]
        << " owned, current price = $" << currentSharePrice[ count ] << endl;
    }
    
    //Return
    return;
}

// Function for option 2 (sell): to input sell menu option
short inputSellMenuChoice( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[] )
{
    // Variable delarations
    short sellMenuChoice;
    
    // call print menu
    printSellMenu( STOCK_NAMES, totalShares, currentSharePrice );
    
    // Input menu choice
    do
    {
        cout << "Please enter your selection of stock to sell (1-10)" << endl;
        cin >> sellMenuChoice;
        cout << endl;
    }while( !( sellMenuChoice >= 1 && sellMenuChoice <= MAX_STOCKS ));
    
    // convert sell menu choice to array number
    sellMenuChoice = sellMenuChoice - 1 ;
    
    // Return menu choice
    return sellMenuChoice;
}

// Function for option 2 (sell): to input and validate quantity of shares to sell
short inputSellQuantity( short sellMenuChoice, short sellQuantity, short totalShares[], float cashBalance )
{
    // input and validate sell quantity
    do
    {
        cout << "How many shares of " << STOCK_NAMES[ sellMenuChoice ] << " would you like to sell?" << endl;
        cin >> sellQuantity;
        cout << endl;
        if( !(totalShares[ sellMenuChoice ] >= sellQuantity))
        {
            cout << "Sorry, you do not have enough shares to sell " << sellQuantity << " shares." << endl;
        }
    }while( !(totalShares[ sellMenuChoice ] >= sellQuantity ));
    
    // return sell quantity
    return sellQuantity;
}

// Function for option 2 (sell): update total shares
short sellUpdateTotalShares( short sellMenuChoice, short sellQuantity, short totalShares[] )
{
    // calculate total shares
    totalShares[ sellMenuChoice ] = totalShares[ sellMenuChoice ] - sellQuantity;
    
    // return total shares
    return totalShares[ sellMenuChoice ];
}


// Function for option 2 (sell): update cash balance
float sellUpdateCashBalance( short sellMenuChoice, short sellQuantity, short totalShares[], float currentSharePrice[], float cashBalance )
{
    // calculate cash balance after selling
    cashBalance = cashBalance + (currentSharePrice[ sellMenuChoice ] * sellQuantity);
    
    cout << "The proceeds of your sale are $" << sellQuantity * currentSharePrice[ sellMenuChoice ] << endl;
    
    //return cash balance
    return cashBalance;
}


// function for option 4: to print current holdings
void printCurrentHoldings( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[], float cashBalance )
{
    // Variable declarations
    unsigned short count;
    float priceAccumulator = 0;
    
    // output report
     for( count = 0 ; count < MAX_STOCKS ; count++ )
    {
        cout << count + 1 << ". " << STOCK_NAMES[ count ] << ": " << totalShares[ count ]
             << " owned, current price = $" << currentSharePrice[ count ] << ", net worth = $"
             << currentSharePrice[ count ] * totalShares[ count ] << endl;

        priceAccumulator = priceAccumulator + ( currentSharePrice[ count ] * totalShares[ count ] );
    }

    cout << "You have $" << cashBalance << " available cash." << endl
         << "The total worth of your portfolio is $" << priceAccumulator + cashBalance << endl;
    
    // return
    return;
}


// function to write final report
void finalReport( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[], float lowestPrice[], float highestPrice[], float cashBalance )
{
    // variable declarations
    short count;
    float sharesSum;

    //calculate total of all owned stock at final stock prices
    sharesSum = 0;
    for ( count = 0; count < MAX_STOCKS; count++)
    {
        sharesSum += totalShares[count] * currentSharePrice[count];
    }
    
    // output reports

    // print highest/lowest/final prices report
    cout << "Final report:" << endl;
    cout.setf( ios::fixed );
    cout.precision( 2 );
    for (count = 0 ; count < MAX_STOCKS ; count++)
    {
        cout << "The highest price of " << STOCK_NAMES[count] << " was $" << highestPrice[count] << endl
         << "The lowest price of " << STOCK_NAMES[count] << " was $" << lowestPrice[count] << endl
         << "The final price of " << STOCK_NAMES[count] << " is $" << currentSharePrice[count] << endl
         << "You have " << totalShares[count] << " shares of " << STOCK_NAMES[count] << "." << endl
         << "They are worth $" << totalShares[count] * currentSharePrice[count] << endl << endl;
    }
    
    // print final net worth
   cout << "You have $" << cashBalance << " available cash." << endl
        << "The total worth of your portfolio is $" << sharesSum + cashBalance << endl
        << "Thank you for using Rebecca Fernandez's Stock Simulator" << endl;
    
    // return
    return;
}

// function to initialize share prices
float initializeSharePrice( float currentSharePrice[])
{
    // variable declarations
    float newShareBase;
    unsigned short count;

    // initialize whole number within range $50 to $250
    
        // seed random generator
        srand( time( NULL ) );
        
        // update all stock prices
        for( count = 0 ; count < MAX_STOCKS ; count++ )
        {
            // determine share base number 50 to 150
            do
            {
            newShareBase = rand() % 100 + 50;
            }while( !(newShareBase != 0) );

            // assign determined number to current share price
            currentSharePrice[count] = newShareBase;
        }

    // use updateSharePrice function to determine decimals
    currentSharePrice[ MAX_STOCKS ] = updateSharePrice( currentSharePrice );
            
    //return current share price
    return currentSharePrice[ MAX_STOCKS ];
}

// function to update share prices 
float updateSharePrice( float currentSharePrice[] )
{
    // variable declarations
    float newSharePercentage;
    unsigned short count;
    
    // seed random generator
    srand( time( NULL ) );
    
    // update all stock prices
     for( count = 0 ; count < MAX_STOCKS ; count++ )
    {
       // determine percentage to adjust each stock by (-5% to 5%)
        do
        {
          newSharePercentage = rand() % 10  - 5;
        }while( !(newSharePercentage != 0) );

        // adjust stock prices accordingly
        currentSharePrice[ count ] = ( ( 1 - ( newSharePercentage / 100)) * currentSharePrice[ count ] );
    }

    // return current share price
    return currentSharePrice[ MAX_STOCKS ];
}

