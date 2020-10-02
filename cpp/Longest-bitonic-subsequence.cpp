#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;
vector<int> LIS(N,1);
vector<int> LDS(N,1);


void LIS2(int a[],int n ){
    LIS[0]=1;
    // LIS[i] represents what is the length of longest increasing subsequence
    // ending at index i
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(a[j]<a[i]) LIS[i] = max(LIS[i],LIS[j]+1);
        }
    }
    // return *max_element(LIS.begin(),LIS.end());
}

void LDS2(int a[],int n ){
    LDS[0]=1;
    // LDS[i] represents what is the length of longest decreasing subsequence
    // starting at index i

    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(a[j]<a[i]){
                LDS[i]= max(LDS[i],LDS[j]+1);
            }
        }
    }
    // return *max_element(LDS.begin(),LDS.end());
}

int longestBitonic(int a[],int n)
{
    // time  : o(n^2+n^2+n) => o(n^2)
    // space : o(n)
    // longest bitonic will be lds[i]+lis[i]-1 (1 becz a[i] is considered in both sequences)
    LDS2(a,n);
    LIS2(a,n);
    int ans =0;
    for(int i=0;i<n;i++){
        ans = max(ans,LDS[i]+LIS[i]-1);
    }
    return ans;
}
int main()
{
    int a[]={1,11,2,10,4,5,2,1};

    cout << longestBitonic(a,size(a)) << endl;
}
