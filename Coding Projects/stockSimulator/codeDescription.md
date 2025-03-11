### Overview of the Stock Market Simulator
This C++ program is a stock market simulator that allows users to:

- Buy and sell shares.
- Add cash to their account.
- View current holdings (including individual stock values and total net worth).
- Track stock price changes (with highest and lowest values recorded).
- Generate a final report summarizing the user's financial position.

## Key Features and How They Work
1. Initialization
The program begins by welcoming the user and asking for an initial cash investment (minimum $100).
It initializes 10 popular stock names (e.g., Apple, Microsoft) and assigns random starting prices between $50 and $150.
Each stock's highest and lowest price trackers are initialized to the starting price.
3. Main Menu Options
The main menu presents five options:

1. Buy Shares
2. Sell Shares
3. Add Cash to the Account
4. Print Current Holdings
5. Quit the Program

3. Buying Shares
The user is prompted to select a stock from the list.
They enter the number of shares they want to purchase. The program ensures the user has enough cash for the purchase.
Once verified:
The stock's total share count is updated.
The user's cash balance is reduced accordingly.
4. Selling Shares
The user selects a stock they own.
They input the number of shares they wish to sell.
The program verifies they have enough shares to complete the sale.
The cash balance is updated with the proceeds from the sale.
5. Adding Cash
Users can add additional funds with a minimum investment of $100.
The new balance is calculated and displayed.
6. Viewing Current Holdings
The program prints a detailed list of:
Stocks owned.
The number of shares for each stock.
Each stock's current value.
It calculates and displays:
Total cash balance.
Net worth (cash + total value of stocks).
7. Stock Price Updates
After every action (buy, sell, add cash, etc.), stock prices are adjusted by a random percentage between -5% and +5% to simulate market fluctuations.
The program keeps track of:
The highest price each stock has reached.
The lowest price each stock has reached.
8. Final Report
When the user chooses to quit, a detailed summary is displayed:

Final cash balance.
Total net worth.
Each stock’s:
Final value.
Number of shares owned.
Highest and lowest recorded prices.
Program Flow
User starts the program.
Initial cash investment is entered.
User interacts with the menu to buy/sell shares, add cash, or check holdings.
After each action, stock prices are updated.
When the user quits, the final report is shown.

