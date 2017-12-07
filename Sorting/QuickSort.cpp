#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];  // Pivot
    int i = low - 1;        // Index of smaller element

    for(int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]); // placeing the pivot in its actual position
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

/* The main function that implements QuickSort
  arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void QuickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        QuickSort(arr, low, pi-1);
        QuickSort(arr, pi+1, high);
    }
}

void display(vector<int>& vec)
{
    int count = vec.size();  // Return size
    cout<<"\nValues stored are: ";
    for(int i = 0; i < count; i++)
    {
        cout<<" "<<vec[i];
    } 
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arr_size = arr.size();
 
    printf("In the given array, ");
    display(arr);
 
    QuickSort(arr, 0, arr_size - 1);
 
    printf("\nAfter Sorting, ");
    display(arr);
    return 0;
}