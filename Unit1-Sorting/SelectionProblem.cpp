
#include <iostream>
using namespace std;

// Partition function
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Find kth smallest element
int quickSelect(int arr[], int low, int high, int k)
{
    if (low <= high)
    {
        int pi = partition(arr, low, high);

        if (pi == k - 1)
        {
            return arr[pi];
        }

        if (pi > k - 1)
        {
            return quickSelect(arr, low, pi - 1, k);
        }

        return quickSelect(arr, pi + 1, high, k);
    }

    return -1;
}

int main()
{
    int n, arr[100], k;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0 || n > 100)
    {
        cout << "Invalid array size.";
        return 0;
    }

    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    if (k < 1 || k > n)
    {
        cout << "Invalid value of k.";
        return 0;
    }

    int result = quickSelect(arr, 0, n - 1, k);

    cout << "The " << k << "th smallest element is: " << result;

    return 0;
}
