
#include <iostream>
using namespace std;

int main() {
    int n, target;
    int arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    bool dp[101][1001] = {false};

    // Sum 0 is possible with an empty subset
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {

            // Do not include current element
            dp[i][j] = dp[i - 1][j];

            // Include current element if possible
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i][j] ||
                           dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    if (dp[n][target])
        cout << "Subset with given sum exists.";
    else
        cout << "Subset with given sum does not exist.";

    return 0;
}
