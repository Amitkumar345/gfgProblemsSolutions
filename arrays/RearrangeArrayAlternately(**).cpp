// https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1

class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *a, int n) 
    { 
    	long long mx = a[n-1] + 1;
    	int l=0,r=n-1;
    	long long org;
    	for(int i=0;i<n;i++){
    	    if(i&1){
    	        org = a[l++]%mx;
    	    }else{
    	        org = a[r--]%mx;
    	    }
    	    a[i] = a[i] + org*mx;
    	   // storing two elements at one position
    	}
    	for(int i=0;i<n;i++)
    	    a[i] /= mx;
    }
};
