
#include <iostream>
using namespace std;

int main() {
    int n, capacity;

    int weight[100], profit[100];
    int dp[101][1001] = {0};

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter profits of items: ";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {

            // Exclude the current item
            dp[i][w] = dp[i - 1][w];

            // Include the current item if it fits
            if (weight[i - 1] <= w) {
                int include = profit[i - 1] +
                    dp[i - 1][w - weight[i - 1]];

                if (include > dp[i][w]) {
                    dp[i][w] = include;
                }
            }
        }
    }

    cout << "Maximum Profit: " << dp[n][capacity];

    return 0;
}
