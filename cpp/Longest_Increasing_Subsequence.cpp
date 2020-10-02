#include<bits/stdc++.h>
using namespace std;

int LIS1(int a[],int n,int& mx){

    if(n==1)return 1;

    int res,max_ending_here=1;
    for(int i=1;i<n;i++){
         res = LIS1(a,i,mx);
        if(a[i-1]<a[n-1] and res+1>max_ending_here){
            max_ending_here = res+1;
        }
    }

    if(max_ending_here>mx){
      mx = max_ending_here;
    }
    return  max_ending_here;
}

int lis(int a[],int n){
  int mx = 1;
  LIS1(a,n,mx);
  return mx;
}
int LIS2(int a[],int n ){
    vector<int> dp(n+1,1);
    dp[0]=1;
    // dp[i] represents what is the length of longest increasing subsequence ending at index i
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(a[j]<a[i]) dp[i] = max(dp[i],dp[j]+1);
        }
    }
    return *max_element(dp.begin(),dp.end());
}

int ceilIndex(vector<int>tail,int left,int right,int ele){

    while(left<right){
          int mid = (left+right)/2;
          if(tail[mid]>=ele) right= mid; // smallest ceil index possible
          else left = mid+1;
    }
    return right;
}

int LIS3(int a[],int n){
    // O(nlog(n))
  // idea is that we put smallest element possible at the end of i length subsequence
  // if we find smaller element than last ele of tail then we binary search to put this at
  // rignt position
    vector<int> tail;
    tail.push_back(a[0]);

    for(int i=1;i<n;i++){
        if(a[i]>tail.back()){
            tail.push_back(a[i]);
        }else{
            int id = ceilIndex(tail,0,tail.size()-1,a[i]);
            tail[id] = a[i];
        }
    }
    return tail.size();
}

int main()
{
     int n; cin >> n;
     int a[n];
     for(int i=0;i<n;i++) cin >> a[i];

      cout << lis(a,n) << endl;

      cout << LIS2(a,n) << endl;

      cout << LIS3(a,n) << endl;
     return 0;
}
