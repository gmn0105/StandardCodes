#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
void zalgo(string s, string s1, int *z)
{
    int R=0,L=0;
    s1 += "$";
    s1 += s;
    s = s1;
    long int n=s.length();
    z[0]=0;
    for (int i = 1; i < n; i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && s[R-L] == s[R])
            {
                R++;
            }
            z[i] = R-L;
            R--;
        }
        else
        {
            int k = i-L;
            if (z[k] < R-i+1)
            {
                z[i] = z[k];
            }
            else
            {
                L = i;
                while (R < n && s[R-L] == s[R])
                {
                    R++;
                }
                z[i] = R-L;
                R--;
            }
        }
    }
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int a[1000000];
    zalgo(s1, s2, a);
        // in a[], if s2.length = l, a[i]=l means that in s1, there is a substring s2 is starting at index i. 
}
