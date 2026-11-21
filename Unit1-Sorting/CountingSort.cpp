
#include <iostream>
using namespace std;

int main()
{
    int n, arr[100];
    int count[101] = {0};

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " non-negative elements (0 to 100): ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] < 0 || arr[i] > 100)
        {
            cout << "Please enter values between 0 and 100.";
            return 0;
        }

        count[arr[i]]++;
    }

    // Reconstruct the sorted array
    int index = 0;

    for (int i = 0; i <= 100; i++)
    {
        while (count[i] > 0)
        {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
