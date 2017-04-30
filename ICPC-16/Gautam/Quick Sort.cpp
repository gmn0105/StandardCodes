#include <iostream>
using namespace std;
int partition1(int a[], int start, int last);//the array is zero index
int check(int a[], int start, int last);
void quicksort(int a[], int start, int last);
int main()
{
	int n;
	cin>>n;									
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quicksort(a, 0, n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" "; 
    }
    cout<<endl;
}
int partition1(int a[], int start, int last)
{
	int piv=a[start];
	int i=start+1;
	for(int j=start+1;j<=last;j++)
	{
		if(a[j]<piv)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i+=1;
		}
	}
	int t=a[start];
	a[start]=a[i-1];
	a[i-1]=t;
	//cout<<i-1<<endl;
	return i-1;
}
int check(int a[], int start, int last)
{
    for(int i=start;i<last;i++)
    {
        if(a[i]>a[i+1])
        {
            return 0;
        }
    }
    return 1;
}
void quicksort(int a[], int start, int last)
{
	if(start<last)
	{
		int piv=partition1(a, start, last);
		quicksort(a, start, piv-1);
		quicksort(a, piv+1, last);
     }
}
