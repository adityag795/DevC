#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>

using namespace std;

void Merge(vector<int> &arr, int &l, int &m, int &r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Creating temporary arrays.
    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[].
    for(i = 0; i < n1; i++)
        L[i] = arr[ l + i ];
    for(j = 0; j < n2; j++)
        R[j] = arr[ m + 1 + j ];

    // Merge the temporary arrays back into arr[l..r].
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    while( i < n1 && j < n2 )
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any.
    while( i < n1 )
    {
        arr[k] = L[i];
        i++; k++;
    }
    
    // Copy the remaining elements of R[], if there are any.
    while( j < n2 )
    {
        arr[k] = R[j];
        j++;k++;
    }
}

void MergeSort(vector<int> &arr, int l, int r) // Time Complexity: O(nlogn)
{
    if (l < r)
    {
        int m = l + (r - l)/2;
        MergeSort(arr, l, m);
        MergeSort(arr, m+1, r);
        Merge(arr, l , m , r);
    }
}

void display(vector<int> &vec)
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
 
    MergeSort(arr, 0, arr_size - 1);
 
    printf("\nAfter Sorting, ");
    display(arr);
    return 0;
}