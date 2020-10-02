#include<bits/stdc++.h>
using namespace std;

const int mx=10000;
int dp[mx][mx];
int LCS1(string s1,string s2,int m,int n){
    // without memorization exponential
    // with memorization o(m*n)
    if(dp[m][n]!=-1)return dp[m][n];

    if(!m or !n)return 0;
    if(s1[m-1]==s2[n-1]){
        dp[m][n] = 1+LCS1(s1,s2,m-1,n-1);
    }
    else{
        dp[m][n]=max(LCS1(s1,s2,m,n-1),LCS1(s1,s2,m-1,n));
    }
    return dp[m][n];
}

int LCS2(string s1,string s2){
    // o(m*n)
    int m = s1.size(),n=s2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1));

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<=n;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for finding LCS
    string ans = "";
    int i=m,j=n;
    while(i and j){

        if(s1[i-1]==s2[j-1]){
            ans += s1[i-1];
            i--,j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }

    reverse(ans.begin(),ans.end());
    cout << ans << endl; // printing lCS

    return dp[m][n];
}
int main(){
    for(int i=0;i<mx;i++){
        for(int j=0;j<mx;j++){
            dp[i][j]=-1;
        }
    }
    string s1="axbght";
    string s2="abt";

    cout << LCS1(s1,s2,s1.size(),s2.size()) << endl;

    cout << LCS2(s1,s2) << endl;
    return 0;
}


// some variation

// 1. Diff Utility
// 2. Min insertions and deletions to convert string s1 into s2
// 3. Shortest Common supersequence
// 4. Longest Palindromic subsequence
// 5. Longest Repeating subsequence
// 6. More optimized DP solutions of lCS
// 7 . priting LCS of 2 strings
