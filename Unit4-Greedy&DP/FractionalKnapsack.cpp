
#include <iostream>
using namespace std;

int main()
{
    int n;
    float weight[100], profit[100], ratio[100];
    float capacity, totalProfit = 0;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weight and profit of each item:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> profit[i];

        ratio[i] = profit[i] / weight[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Sort items by decreasing profit/weight ratio
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                swap(ratio[j], ratio[j + 1]);
                swap(weight[j], weight[j + 1]);
                swap(profit[j], profit[j + 1]);
            }
        }
    }

    // Select items greedily
    for (int i = 0; i < n; i++)
    {
        if (capacity >= weight[i])
        {
            totalProfit += profit[i];
            capacity -= weight[i];
        }
        else
        {
            totalProfit += ratio[i] * capacity;
            capacity = 0;
            break;
        }
    }

    cout << "Maximum Profit: " << totalProfit;

    return 0;
}
