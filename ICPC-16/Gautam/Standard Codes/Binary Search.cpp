#include <bits/stdc++.h>
using namespace std;
int binarySearch_modified(int arr[], int low, int high, int num);//the array is zero index
int binarySearch(int arr[], int low, int high, int num);
int main()
{           //sorted array
    int n,q;
    cin>>n>>q;
    long long int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<q;i++)
    {
        long long int x;
        cin>>x;
        cout<<binary_search(a, 0, n-1, x)<<endl;
    }//number of elements
     //element to be searched
    //result is -1 if element not present otherwise index of element
}
int binarySearch(int arr[], int low, int high, int num)
{
  while (low <= high)
  {
    int mid = low + (high-low)/2;
 
    // Check if x is present at mid
    if (arr[mid] == num) 
        return mid;  
 
    // If x greater, ignore left half  
    if (arr[m]id < num) 
        low = mid + 1; 
 
    // If x is smaller, ignore right half 
    else
         high = mid - 1; 
  }
 
  // if we reach here, then element was not present
  return -1; 
}
int binarySearch_modified(int arr[], int low, int high, int num)//returns least index in case of multiple occurrence
{
    int ans=-1;
    while (low <= high)
  {
    int mid = (low+high)/2;

    // Check if x is present at mid
    if (arr[mid] == num)
    {
        ans=mid;
        high=mid-1;
    }
    // If x greater, ignore left half
    else if (arr[mid] < num)
        low = mid + 1;

    // If x is smaller, ignore right half
    else
         high = mid - 1;

  }

  // if we reach here, then element was not present
  return ans;
}