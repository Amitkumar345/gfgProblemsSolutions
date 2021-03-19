// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// problem -> count inversions
// inversion -> a[i]>a[j] where i<j
  long long int countMerge(long long a[],long long l,long long mid,long long r){
        long long int ans=0;
        long long n1=mid+1-l,n2=r-mid;
        long long left[n1],right[n2];
        
        long long i,j,k=l;
        for(i=0;i<n1;i++)left[i]=a[l+i];
        for(i=0;i<n2;i++)right[i]=a[mid+1+i];
        i=0;j=0;
        while(i<n1 && j<n2){
            if(left[i]<=right[j]){
                a[k++]=left[i++];
            }else{
                a[k++]=right[j++];
                ans+=(n1-i);
            }
        }
        while(i<n1){
            a[k++]=left[i++];
        }
        while(j<n2){
            a[k++]=right[j++];
        }
        return ans;
        
    }
    long long int inversionCnt(long long a[], long long l,long long r){
        long long int ans=0;
        if(l<r){
            long long mid = l+(r-l)/2;
            ans+=inversionCnt(a,l,mid);
            ans+=inversionCnt(a,mid+1,r);
            ans+=countMerge(a,l,mid,r);
        }
        return ans;
        
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return inversionCnt(arr,0,N-1);
    }
