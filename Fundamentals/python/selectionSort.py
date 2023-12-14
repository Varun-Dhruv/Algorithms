
def selectionSort(arr,n):
    for i in range(n):
        min = i
        for j in range(i+1,n):
            if arr[min] > arr[j]:
                min = j
        arr[i],arr[min] = arr[min],arr[i]

if '__name__' == '__main__':
    n = int(input("Enter the Number of total Elements"))
    arr = []
    arr = [int(x) for x in input("Enter the Elements").split()]
