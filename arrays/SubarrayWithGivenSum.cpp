// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    // Function to find the subarray with given sum k
    // arr: input array
    // n: size of array
    vector<int> subarraySum(int a[], int n, int sum){
        
        int s=0;
        int l=0,r=0;
        for(int i=0;i<n;i++){
            if(s==sum){
                break;
            }else if(a[i]+s<=sum){
                s+=a[i];
                r=i;
                continue;
            }else{
                s-=a[l++];
                i--;
            }
        }
        vector<int> v;
        if(s==sum){
             v={l+1,r+1};
            return v;
        }
        v={-1};
        return v;
        
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
