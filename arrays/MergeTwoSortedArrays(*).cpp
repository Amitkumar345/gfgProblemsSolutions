// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long a[], long long b[], int n, int m) 
        { 
            if(a[n-1]<=b[0])return;
            int i=n-1,j=0;
            while(a[i]>b[j] && i>=0 && j<m){
                swap(a[i],b[j]);
                i--;j++;
            }
            sort(a,a+n);
            sort(b,b+m);
        } 
};

