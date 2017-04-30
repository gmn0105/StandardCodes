#include <bits/stdc++.h>
using namespace std;
int binarySearch_modified(struct data arr[], int low, int high, int num);
struct data
{
	int index;//variable w.r.t which search is conducted
	string s;
};
int main()
{
	int n;
	cin>>n;
	struct data d[n];
	for(int i=0;i<n;i++)
	{
		cin>>d[i].s;
		d[i].index = i;
	}
	int q;
	cin>>q;
	cout<<d[binarySearch_modified(d, 0, n-1, q)].s<<endl;
}
int binarySearch_modified(struct data arr[], int low, int high, int num)//returns least index in case of multiple occurrence
{
    int ans=-1;
    while (low <= high)
  {
    int mid = (low+high)/2;

    // Check if x is present at mid
    if (arr[mid].index == num)
    {
        ans=mid;
        high=mid-1;
    }
    // If x greater, ignore left half
    else if (arr[mid].index < num)
        low = mid + 1;

    // If x is smaller, ignore right half
    else
         high = mid - 1;

  }

  // if we reach here, then element was not present
  return ans;
}