/*
Read the marks obtained by students of second year in an online
examination of particular subject. Find out maximum and minimum marks obtained in that
subject. Use heap data structure. Analyze the algorithm.

Algorithm :
1. Accept the marks for student.
2. Insert the marks in heap.
3. Up-adjust the heap.
4. Repeat the steps 1 to 4 if marks of more students to be entered.
5. Display the maximum marks.

*/
#include <iostream>
using namespace std;
void MaxHeapify(int a[], int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j + 1] > a[j])
            j = j + 1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}
void MinHeapify(int a[], int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j + 1] < a[j])
            j = j + 1;
        if (temp < a[j])
            break;
        else if (temp >= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}
void MaxHeapSort(int a[], int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        MaxHeapify(a, 1, i - 1);
    }
}
void MinHeapSort(int a[], int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        MinHeapify(a, 1, i - 1);
    }
}
void Build_MaxHeap(int a[], int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
        MaxHeapify(a, i, n);
}
void Build_MinHeap(int a[], int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
        MinHeapify(a, i, n);
}
int main()
{
    int n, i;
    cout << "\nEnter number of subjects of second year: ";
    cin >> n;
    n++;
    int arr[n];
    for (i = 1; i < n; i++)
    {
        cout << "Enter the marks : " << i << ": ";
        cin >> arr[i];
    }
    Build_MaxHeap(arr, n - 1);
    cout << "\nPrint array after building MaxHeap :: ";
    for (i = 1; i < n; i++)
        cout << " " << arr[i];
    MaxHeapSort(arr, n - 1);
    int max, min;
    cout << "\n\nSorted Data : ASCENDING : ";
    for (i = 1; i < n; i++)
        cout << " " << arr[i];
    min = arr[1];
    Build_MinHeap(arr, n - 1);
    cout << "\n\nPrint array after";
    for (i = 1; i < n; i++)
        cout << " " << arr[i];
    MinHeapSort(arr, n - 1);
    cout << "\n\nSorted Data : DESCENDING: ";
    max = arr[1];
    for (i = 1; i < n; i++)
        cout << " " << arr[i];
    cout << "\n\nMaximum Marks : " << max << "\nMinimum marks : " << min;
    return 0;
}