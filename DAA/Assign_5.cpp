#include <iostream>
using namespace std;


//Write a program for analysis of quick sort by using deterministic and randomized variant.


void printSummary(int* nums, int swaps, int comparisons)
{
    cout<<"Sorted Array: "<<endl;
    for(int i=0;i<sizeof(nums);i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<"\nNo of swaps: "<<swaps<<"\nNo. of comparisons: "<<comparisons<<endl;
}

//------------------------------------------------------------------------


// 1. Deterministic
int partition_deterministic(int* nums, int low, int high)
{
    int pivot = nums[low];
    int p = low + 1;
    int q = high;

    while(1)
    {
        while(p <= high && nums[p] <= pivot)
        {
            p++;
        }
        while(nums[q] > pivot)
        {
            q--;
        }
        if(p < q)
        {
            swap(nums[p], nums[q]);
        }
        else
        {
            break;
        }
    }
    swap(nums[low], nums[q]);
    return q;
}


void quickSort_deterministic(int* nums, int low, int high, int& swaps, int& comparisons)
{
    if(low < high)
    {
        int k = partition_deterministic(nums,low,high);
        comparisons += (high-low);
        swaps += 2;
        quickSort_deterministic(nums, low, k-1, swaps, comparisons);
        quickSort_deterministic(nums, k+1, high, swaps, comparisons);
    }
}

//----------------------------------------------------------------------------------------------------------


// 2. Randomized Quicksort


int partition_randomized(int* nums, int low, int high)
{
    int randomIndex = low + rand() % (high - low + 1);
    swap(nums[low], nums[randomIndex]);

    int pivot = nums[low];
    int p = low + 1;
    int q = high;
    while(1)
    {
        while(p <= high && nums[p] < pivot)
        {
            p++;
        }
        while(nums[q] > pivot)
        {
            q--;
        }
        if(p < q)
        {
            swap(nums[p], nums[q]);
        }
        else
        {
            break;
        }
    }
    swap(nums[low], nums[q]);
    return q;
}

void quickSort_randomized(int* nums, int low, int high, int& swaps, int& comparisons)
{
    if(low < high)
    {
        int k = partition_randomized(nums, low, high);
        comparisons += (high - low);
        swaps += 2;

        quickSort_randomized(nums, low, k-1, swaps, comparisons);
        quickSort_randomized(nums, k+1, high, swaps, comparisons);
    }
}


//---------------------------------------------------------------------------


int main()
{
    int n;
    cout<<"Enter no of elements: ";
    cin>>n;

    int* nums = new int[n];
    cout<<"\nEnter array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    int d_swaps = 0;
    int d_comparisons = 0;
    int r_swaps = 0;
    int r_comparisons = 0;

    cout<<"\n*** Deterministic Quicksort ***"<<endl;
    quickSort_deterministic(nums,0,n-1,d_swaps, d_comparisons);
    printSummary(nums, d_swaps, d_comparisons);

    cout<<"\n\n*** Randomized QuickSort ***"<<endl;
    quickSort_randomized(nums, 0, n-1, r_swaps, r_comparisons);
    printSummary(nums, r_swaps, r_comparisons);

    return 0;
}