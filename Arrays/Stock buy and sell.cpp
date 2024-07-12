#include <iostream>
#include <cmath>
using namespace std;

int maxProfit(int price[], int n)
{
    int profit = 0; // Initialize profit to 0

    // Traverse through the price array
    for (int i = 1; i < n; i++)
    {
        // If the current price is greater than the previous price
        if (price[i] > price[i - 1])
            // Add the difference to the profit
            profit += price[i] - price[i - 1];
    }

    return profit; // Return the total profit
}

int main()
{
    // Array of stock prices on different days
    int arr[] = {1, 5, 3, 8, 12}, n = 5;

    // Print the maximum profit that can be made
    cout << maxProfit(arr, n);
}