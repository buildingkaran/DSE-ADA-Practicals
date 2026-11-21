
#include <iostream>
using namespace std;

// Find maximum of three values
int maxValue(int a, int b, int c)
{
    if (a > b && a > c)
        return a;

    if (b > c)
        return b;

    return c;
}

// Find maximum sum crossing the middle
int maxCrossingSum(int arr[], int low, int mid, int high)
{
    int sum = 0;
    int leftSum = -1000000;

    for (int i = mid; i >= low; i--)
    {
        sum = sum + arr[i];

        if (sum > leftSum)
        {
            leftSum = sum;
        }
    }

    sum = 0;
    int rightSum = -1000000;

    for (int i = mid + 1; i <= high; i++)
    {
        sum = sum + arr[i];

        if (sum > rightSum)
        {
            rightSum = sum;
        }
    }

    return leftSum + rightSum;
}

// Divide and Conquer function
int maxSubarraySum(int arr[], int low, int high)
{
    if (low == high)
    {
        return arr[low];
    }

    int mid = (low + high) / 2;

    int leftSum = maxSubarraySum(arr, low, mid);

    int rightSum = maxSubarraySum(arr, mid + 1, high);

    int crossSum = maxCrossingSum(arr, low, mid, high);

    return maxValue(leftSum, rightSum, crossSum);
}

int main()
{
    int n, arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0 || n > 100)
    {
        cout << "Invalid array size.";
        return 0;
    }

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = maxSubarraySum(arr, 0, n - 1);

    cout << "Maximum Subarray Sum: " << result;

    return 0;
}
