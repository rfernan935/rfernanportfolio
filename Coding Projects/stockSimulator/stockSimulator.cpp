/******************************************************************************

Name: Rebecca Fernandez
Date: 11/28/23
Project: 10
Email: rfernan2@ramapo.edu

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
short inputMenuChoice();
void printBuyMenu( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[], unsigned short size );
short inputBuyMenuChoice( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[], unsigned short size );
short inputBuyQuantity( short buyMenuChoice, short buyQuantity, float currentSharePrice[], float cashBalance );
short buyUpdateTotalShares( short buyMenuChoice, short buyQuantity, short totalShares[] );
float buyUpdateCashBalance( short buyMenuChoice, short buyQuantity, short totalShares[], float currentSharePrice[], float cashBalance );
short inputSellMenuChoice( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[], unsigned short size );
short inputSellQuantity( short sellMenuChoice, short sellQuantity, short totalShares[], float currentSharePrice[], float cashBalance );
short sellUpdateTotalShares( short sellMenuChoice, short sellQuantity, short totalShares[] );
float sellUpdateCashBalance( short sellMenuChoice, short sellQuantity, short totalShares[], float currentSharePrice[], float cashBalance );
void printCurrentHoldings( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[], unsigned short size, float cashBalance );
float updateSharePrice( float currentSharePrice[] );
void finalReport( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[], float lowestPrice[], float highestPrice[], unsigned short size, float cashBalance );

int main()
{
    // Symbolic constants
    
    // Variable declarations
    short menuChoice, buyQuantity, sellQuantity, buyMenuChoice, sellMenuChoice;
    short totalShares[ MAX_STOCKS ] = { 0 } ;
    float cashInvestment,
          cashBalance = 0,
          startPrice,
          lowestPrice[MAX_STOCKS],
          highestPrice[MAX_STOCKS];
          //currentSharePrice;
    float currentSharePrice[ MAX_STOCKS ] = { 189.69, 369.84, 153.23, 53.84,
    306.49, 34.29, 160.26, 269.78, 90.60, 163.07 } ;


    // Input initial cash investment
    cout << "Welcome to Rebecca Fernandez's stockbroker simulation program \n";
    cashBalance = cashBalance + inputCashInvestment( cashBalance );
    
    
    // Begin menu loop
    menuChoice = inputMenuChoice();
    while( menuChoice != MAX_MENU_CHOICE)
    {
        // go to chosen menu page
        switch( menuChoice )
        {
            case 1: buyMenuChoice = inputBuyMenuChoice( STOCK_NAMES, totalShares, currentSharePrice, MAX_STOCKS );
                    buyQuantity = inputBuyQuantity( buyMenuChoice, buyQuantity, currentSharePrice, cashBalance );
                    totalShares[ MAX_STOCKS ] = buyUpdateTotalShares( buyMenuChoice, buyQuantity, totalShares );
                    cashBalance = buyUpdateCashBalance( buyMenuChoice, buyQuantity, totalShares, currentSharePrice, cashBalance );
                break;
            case 2: sellMenuChoice = inputSellMenuChoice( STOCK_NAMES, totalShares, currentSharePrice, MAX_STOCKS );
                    sellQuantity = inputSellQuantity( sellMenuChoice, sellQuantity, totalShares, currentSharePrice, cashBalance );
                    totalShares[ MAX_STOCKS ] = sellUpdateTotalShares( sellMenuChoice, sellQuantity, totalShares );
                    cashBalance = sellUpdateCashBalance( sellMenuChoice, sellQuantity, totalShares, currentSharePrice, cashBalance );
                break;
            case 3: cashBalance = inputCashInvestment( cashBalance );
                break;
            case 4: printCurrentHoldings( STOCK_NAMES, totalShares, currentSharePrice, MAX_STOCKS, cashBalance )
;
                break;
            case MAX_MENU_CHOICE:
                break;
        }
        
        // update share price
        currentSharePrice[ MAX_STOCKS ] = updateSharePrice( currentSharePrice );
        
       
        // update highest price Variable
        for (size_t i = 0; i < MAX_STOCKS; i++)
        {
            if(currentSharePrice[i] > highestPrice[i])
            {
                highestPrice[i] = currentSharePrice[i];
            }
        }
        
        // update lowest price variable
        for (size_t i = 0; i < MAX_STOCKS; i++)
        {
            if(currentSharePrice[i] > lowestPrice[i])
            {
                lowestPrice[i] = currentSharePrice[i];
            }
        }
        
        // ask for the next menu choice
        // input menu choice
        menuChoice = inputMenuChoice();
        
    }
    
    //print final report upon quit
    finalReport(STOCK_NAMES, totalShares, currentSharePrice, lowestPrice, highestPrice, MAX_STOCKS, cashBalance );
    
    return 0;
}

// Funtion to print menu
void printMenu()
{
    // Symbolic constants
    
    // Variable delarations
    
    // Output menu
    cout << endl
         << "Here are your options: \n"
         << "1. Buy shares \n"
         << "2. Sell shares \n"
         << "3. Add cash to the account (minimum $100) \n"
         << "4. Print current holdings \n"
         << "5. Quit \n\n";
    
    // exit menu
    return;
}    
    
// Function to input menu option
short inputMenuChoice()
{
    // Symbolic constants
    
    // Variable delarations
    short menuChoice;
    
    // call print menu
    printMenu();
    
    // Input menu choice
    do
    {
        cout << "Please enter your selection (1-5) \n";
        cin >> menuChoice;
        cout << endl;
    }while( !( menuChoice >= 1 && menuChoice <= MAX_MENU_CHOICE ));
    
    // Return menu choice
    return menuChoice;
}

// Function for option 3: to compute cash balance after investment
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
        << MIN_CASH_INVESTMENT << ") \n$";
        cin >> cashInvestment;
        cout << endl;
        if( !(cashInvestment >= MIN_CASH_INVESTMENT ))
        {
            cout << "Value is less than $" << MIN_CASH_INVESTMENT
            << ", please try again. \n";
        }
    }while( !(cashInvestment >= MIN_CASH_INVESTMENT ));
    
    // compute cash balance
    cashBalance = cashInvestment + cashBalance;
    
    // output cash balance
    cout.setf( ios::fixed );
    cout.precision( 2 );
    cout << "Your current cash balance is $" << cashBalance << endl;
    
    // Return cash balance
    return cashBalance;
}

// Function for option 1: buy menu
void printBuyMenu( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[], unsigned short size )
//( short totalShares, float currentSharePrice, float cashBalance )
{
    // Variable declarations
    unsigned short count;
    
    // output report
     for( count = 0 ; count < size ; count++ )
    {
        cout << count + 1 << ". " << STOCK_NAMES[ count ] << ": " << totalShares[ count ]
        << " owned, current price = $" << currentSharePrice[ count ] << endl;
    }
    
    //Return
    return;
}

// Function to input buy menu option
short inputBuyMenuChoice( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[], unsigned short size )
{
    // Variable delarations
    short buyMenuChoice;
    
    // call print menu
    printBuyMenu( STOCK_NAMES, totalShares, currentSharePrice, size );
    
    
    // Input menu choice
    do
    {
        cout << "Please enter your selection of stock to purchase (1-10) \n";
        cin >> buyMenuChoice;
        cout << endl;
    }while( !( buyMenuChoice >= 1 && buyMenuChoice <= MAX_STOCKS ));
    
    // convert buy menu choice to array number
    buyMenuChoice = buyMenuChoice - 1 ;
    
    // Return menu choice
    return buyMenuChoice;
}

// Function for option 1: to input and validate quantity of chosen share to buy
short inputBuyQuantity( short buyMenuChoice, short buyQuantity, float currentSharePrice[], float cashBalance )
{
    // input and validate buy quantity
    do
    {
        cout << "How many shares of " << STOCK_NAMES[ buyMenuChoice ] << " would you like to buy? \n";
        cin >> buyQuantity;
        cout << endl;
        
        if( !(cashBalance >= currentSharePrice[ buyMenuChoice ] * buyQuantity))
        {
            cout << "Sorry, you do not have enough cash to buy " << buyQuantity << " shares. \n";
        }
        
    }while( !(cashBalance >= currentSharePrice[ buyMenuChoice ] * buyQuantity ));
    
    // return buy quantity
    return buyQuantity;
}
    
//function for option 1: calculate total shares after buying    
short buyUpdateTotalShares( short buyMenuChoice, short buyQuantity, short totalShares[] )
{
    // calculate total shares
    totalShares[ buyMenuChoice ] = buyQuantity + totalShares[ buyMenuChoice ];
    
    // Output total shares
    //cout << "You have " << totalShares << " shares of Citigroup \n";
    
    //return total shares
    return totalShares[ buyMenuChoice ];
}    
    
//function for option 1: calculate cash balance after buying
float buyUpdateCashBalance( short buyMenuChoice, short buyQuantity, short totalShares[], float currentSharePrice[], float cashBalance )
{
    // calculate cash balance after buying
    cashBalance = cashBalance - (currentSharePrice[ buyMenuChoice ] * buyQuantity);
    
    // print total cost and current cash balance
    cout << "The cost of your purchase is $" << buyQuantity * currentSharePrice[ buyMenuChoice ] << endl;
    
    // return total shares
    return cashBalance;
}


// Function for option 2: sell menu
void printSellMenu( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[], unsigned short size )
//( short totalShares, float currentSharePrice, float cashBalance )
{
    // Variable declarations
    unsigned short count;
    
    // output report
     for( count = 0 ; count < size ; count++ )
    {
        cout << count + 1 << ". " << STOCK_NAMES[ count ] << ": " << totalShares[ count ]
        << " owned, current price = $" << currentSharePrice[ count ] << endl;
    }
    
    //Return
    return;
}

// Function to input sell menu option
short inputSellMenuChoice( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[], unsigned short size )
{
    // Variable delarations
    short sellMenuChoice;
    
    // call print menu
    printSellMenu( STOCK_NAMES, totalShares, currentSharePrice, size );
    
    
    // Input menu choice
    do
    {
        cout << "Please enter your selection of stock to sell (1-10) \n";
        cin >> sellMenuChoice;
        cout << endl;
    }while( !( sellMenuChoice >= 1 && sellMenuChoice <= MAX_STOCKS ));
    
    // convert sell menu choice to array number
    sellMenuChoice = sellMenuChoice - 1 ;
    
    // Return menu choice
    return sellMenuChoice;
}





// Function for option 2 (sell): to input and validate quantity of shares to sell
short inputSellQuantity( short sellMenuChoice, short sellQuantity, short totalShares[], float currentSharePrice[], float cashBalance )
{
    // input and validate sell quantity
    do
    {
        cout << "How many shares of " << STOCK_NAMES[ sellMenuChoice ] << " would you like to sell? \n";
        cin >> sellQuantity;
        cout << endl;
        if( !(totalShares[ sellMenuChoice ] >= sellQuantity))
        {
            cout << "Sorry, you do not have enough shares to sell " << sellQuantity << " shares. \n";
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
void printCurrentHoldings( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[], unsigned short size, float cashBalance )
//( short totalShares, float currentSharePrice, float cashBalance )
{
    // Variable declarations
    unsigned short count;
    float priceAccumulator = 0;
    
    // output report
     for( count = 0 ; count < size ; count++ )
    {
   cout << count + 1 << ". " << STOCK_NAMES[ count ] << ": " << totalShares[ count ]
        << " owned, current price = $" << currentSharePrice[ count ] << ", net worth = $"
        << currentSharePrice[ count ] * totalShares[ count ] << endl;
        priceAccumulator = priceAccumulator + ( currentSharePrice[ count ] * totalShares[ count ] );
    }
    cout << "You have $" << cashBalance << " available cash. \n"
         << "The total worth of your portfolio is $" << priceAccumulator + cashBalance << endl;
    
    /*
    cout << "You have " << totalShares << " shares of Citigroup. \n"
         << "They are worth $" << totalShares * currentSharePrice << endl
         << "You have $" << cashBalance << " available cash. \n"
         << "The total worth of your portfolio is $" << (totalShares * currentSharePrice) + cashBalance << endl;
    */
    
    // return
    return;
}


// function to write final report
void finalReport( const string STOCK_NAMES[], short totalShares[], float currentSharePrice[], float lowestPrice[], float highestPrice[], unsigned short size, float cashBalance )
{
    // variable declarations
    unsigned short count;

    // output reports

    
    /*actual report
    cout.setf( ios::fixed );
    cout.precision( 2 );
    for( count = 0 ; count < size ; count++ )
    {
        cout << "You have " << totalShares[count] << " shares of " << STOCK_NAMES[count] << ".\n"
         << "They are worth $" << totalShares[count] * currentSharePrice[count] << endl << endl
         /*<< "You have $" << cashBalance << " available cash. \n"
         << "The total worth of your portfolio is $"
         << (totalShares[count] * currentSharePrice[count]) + cashBalance << endl << endl;
    }*/
    /* lowest report
    cout.setf( ios::fixed );
    cout.precision( 2 );
    for( count = 0 ; count < size ; count++ )
    {
        cout << "The lowest price of " << STOCK_NAMES[count] << " was $" << lowestPrice[count] << endl
         << "At this price: \n"
         << "You have " << totalShares[count] << " shares of " << STOCK_NAMES[count] << ". \n"
         << "They are worth $" << totalShares[count] * lowestPrice[count] << endl << endl
         /*<< "You have $" << cashBalance << " available cash. \n"
         << "The total worth of your portfolio is $"
         << (totalShares[count] * lowestPrice[count]) + cashBalance << endl << endl;
    }*/

    // highest/lowest report
    cout << "Final report: \n";
    cout.setf( ios::fixed );
    cout.precision( 2 );
    for (count = 0 ; count < size ; count++)
    {
        cout << "The highest price of " << STOCK_NAMES[count] << " was $" << highestPrice[count] << endl
         << "At this price: \n"
         << "The lowest price of " << STOCK_NAMES[count] << " was $" << lowestPrice[count] << endl
         << "At this price: \n"
         << "You have " << totalShares[count] << " shares of " << STOCK_NAMES[count] << ". \n"
         << "They are worth $" << totalShares[count] * highestPrice[count] << endl << endl
         /*<< "You have $" << cashBalance << " available cash. \n"
         << "The total worth of your portfolio is $"
         << (totalShares[count] * highestPrice[count]) + cashBalance*/;
    }
    
   cout << "The total worth of your portfolio is $" << (totalShares[count] * highestPrice[count]) + cashBalance << endl
        << "Thank you for using Rebecca Fernandez's Stock Simulator" << endl;
    
    // return
    return;
}


// function to update share price 
float updateSharePrice( float currentSharePrice[] )
{
    // variable declarations
    float newSharePercentage;
    unsigned short count;
    
    // seed random generator
    srand( time( NULL ) );
    
    // compute updated share price
    do
    {
        newSharePercentage = rand() % 10  - 5;
    }while( !(newSharePercentage != 0) );
    
    
    // update all stock prices
     for( count = 0 ; count < MAX_STOCKS ; count++ )
    {
        currentSharePrice[ count ] = ( ( 1 - ( newSharePercentage / 100)) * currentSharePrice[ count ] );
    }

    // return current share price
    return currentSharePrice[ MAX_STOCKS ];
}

