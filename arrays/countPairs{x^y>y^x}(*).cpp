// https://practice.geeksforgeeks.org/problems/number-of-pairs-1587115620/1#

long long countPairs(int X[], int Y[], int m, int n)
    {
        sort(X,X+m);
        sort(Y,Y+n);
        int mx_1 = X[m-1];
        long long ans=0;
    //   for 2 -> 1,5,6,...
        long long cnt2_1 = upper_bound(X,X+m,2) - lower_bound(X,X+m,2);
        long long cnt1_2 = upper_bound(Y,Y+n,1) - lower_bound(Y,Y+n,1);
        ans+=(cnt2_1*( cnt1_2 + (Y+n-lower_bound(Y,Y+n,5)) ));
    //   for 3 -> 1,2,4,5,...
        long long cnt3_1 = upper_bound(X,X+m,3) - lower_bound(X,X+m,3);
        long long cnt3_2 = upper_bound(Y,Y+n,3) - lower_bound(Y,Y+n,3);
        ans+=(cnt3_1*(n-cnt3_2));
    //   for rest : i -> i+1,i+2,...
        for(int i=4;i<=mx_1;i++){
            long long cnt = upper_bound(X,X+m,i)-lower_bound(X,X+m,i);
            long long cnt1 = Y+n - lower_bound(Y,Y+n,i+1);
            ans+=(cnt*(cnt1+cnt1_2));
        }
        return ans;
    }
