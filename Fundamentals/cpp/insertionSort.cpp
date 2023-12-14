#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int hole = arr[i]; // hole
        int j = i - 1;
        while (j >= 0 && arr[j] > hole)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = hole;
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertionSort(arr, n);
    printArray(arr, n);
}