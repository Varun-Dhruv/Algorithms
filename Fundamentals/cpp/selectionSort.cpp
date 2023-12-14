#include <bits/stdc++.h>
using namespace std;
// namespace custom{
// int
// }
// T.C -> O(n^2)
// S.C -> O(1)
// no of swaps ->(n-1) swaps 
// no of comparisons -> n(n-1) comparisons

// recursive

void selectionSort(int arr[],int n){
    
}

// iterative
void selectionSort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int curMinIdx = i + 1;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[curMinIdx])
            {
                curMinIdx = j;
            }
        }
        if (arr[i] > arr[curMinIdx])
        {
            swap(arr[i], arr[curMinIdx]);
        }
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
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}