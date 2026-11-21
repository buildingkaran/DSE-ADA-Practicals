
#include <iostream>
using namespace std;

// Find the maximum element
int getMax(int arr[], int n)
{
    int maxValue = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
        }
    }

    return maxValue;
}

// Counting Sort based on digit position
void countingSort(int arr[], int n, int exp)
{
    int output[100];
    int count[10] = {0};

    // Count digit frequencies
    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Calculate cumulative count
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Build output array
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;

        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy output to original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(int arr[], int n)
{
    int maxValue = getMax(arr, n);

    for (int exp = 1; maxValue / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
}

int main()
{
    int n, arr[100];

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " non-negative elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] < 0)
        {
            cout << "Negative numbers are not supported.";
            return 0;
        }
    }

    if (n > 0)
    {
        radixSort(arr, n);
    }

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
