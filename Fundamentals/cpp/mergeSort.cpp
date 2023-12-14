#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int beg, int mid, int end)
{
    int subArrOne = mid - beg + 1;
    int subArrTwo = end - mid;
    auto *leftArr = new int[subArrOne], *rightArr = new int[subArrTwo];

    for (auto i = 0; i < subArrOne; i++)
        leftArr[i] = arr[beg + i];
    for (auto j = 0; j < subArrTwo; j++)
        rightArr[j] = arr[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = beg;

    while (indexOfSubArrayOne < subArrOne && indexOfSubArrayTwo < subArrTwo)
    {
        if (leftArr[indexOfSubArrayOne] <= rightArr[indexOfSubArrayTwo])
        {
            arr[indexOfMergedArray] = leftArr[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            arr[indexOfMergedArray] = rightArr[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrOne)
    {
        arr[indexOfMergedArray] = leftArr[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrTwo)
    {
        arr[indexOfMergedArray] = rightArr[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArr;
    delete[] rightArr;
}
void mergeSort(int arr[], int beg, int end)
{
    if (beg >= end)
        return;
    int mid = beg + (end - beg) / 2;
    mergeSort(arr, beg, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, beg, mid, end);
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
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}