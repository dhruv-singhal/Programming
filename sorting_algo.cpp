#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selection_sort(int arr[], int n)
{
    for(int i= n-1;i>=1;i--)
    {
        int maxIdx = i;
        for(int j =0;j<i;j++)
        {
            if(arr[j] > arr[maxIdx])
            maxIdx = j;

        }
    swap(&arr[i], &arr[maxIdx]);

    }
}

void bubble_sort(int arr[],int n)
{
    for(int i=n-1;i>=1;i--)
    {
        bool is_sorted = true;
        for(int j=0;j<i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j] , &arr[j+1]);
                is_sorted = false;

            }
        }
        if(is_sorted) return;

    }
}

void insertion_sort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int next = arr[i];
        int j;
        for(j=i-1;j>=0 && arr[j]> next; j--)
        {
            arr[j+1] = arr[j];

        }
        arr[j+1] = next;
    }
}

void merge(int arr[],int low,int mid, int high)
{
    int n = high-low+1;
    int* b = new int[n];
    int left=low, right=mid+1, bIdx = 0;

    while(left<=mid && right <=high)
    {
        if(arr[left]<=arr[right])
            b[bIdx++] = arr[left++];
        else
            b[bIdx++] = arr[right++];

    }

    while( left<=mid){
       b[bIdx++] = arr[left++];
    }
    while(right<=high){
        b[bIdx++] = arr[right++];
    }

    for(int k =0; k<n; k++)
        arr[low+k] = b[k];
    
    delete b;

}

void merge_sort(int arr[], int low,int high)
{
    if(low < high) {
        int mid = (low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr, mid + 1, high);
        merge(arr,low,mid,high);

    }
}


int partition(int arr[], int low, int high)
{
    int p = arr[low];
    int m = low;
    
    for(int k = low+1; k<=high; k++ )
    {
        if(arr[k]<p)
        {
            m++;
            swap(arr[k],arr[m]);
        }
        else{

        }
        
    }
    swap(&arr[low], &arr[m]);
    return m;
}

void quick_sort(int arr[], int low, int high)
{
    if(low < high){

        
        int pivotIdx = partition(arr, low, high);

        quick_sort(arr, low,pivotIdx-1);
        quick_sort(arr, pivotIdx+1, high);
    }
}






void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}

int main ()
{
    int arr[]= {29,10,14,37,13};
    int n = 5;
    selection_sort(arr, n);
    cout<<"Selection_Sorted Array: \n";
    printArray(arr,n);
    int arr1[]= {21,101,114,376,113};
    cout<<"Bubble_Sorted Array: \n";
    bubble_sort(arr1, n);
    printArray(arr1,n);
    cout<<"Insertion_Sorted Array: \n";
    int arr2[]= {221,1201,1114,1376,1113};
    insertion_sort(arr2,n);
    printArray(arr2,n);
    cout<<"Merge_Sorted Array: \n";
    int arr3[]= {22,12,14,16,11};
    merge_sort(arr3,0,n-1);
    printArray(arr3,n);
    cout<<"Quick_Sorted Array: \n";
    int arr4[]= {221,1201,1114,1376,1113};
    quick_sort(arr4,0,n-1);
    printArray(arr4,n);
    return 0;
}