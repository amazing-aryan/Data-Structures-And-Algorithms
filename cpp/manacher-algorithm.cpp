// Manacher's Algorithm - Finding all sub-palindromes in O(N)

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  string s;
  cin >> s;
  int n = s.length();
  int d1[n], d2[n];
  for(int i = 0, l = 0, r = -1; i < n; ++i) {
    int k = (i > r) ? 1 : min(d1[l+r-i], r-i+1);
    while(i-k>=0 && i+k<n && s[i+k] == s[i-k]) {
      k++;
    }
    d1[i] = k--;
    if(i+k > r) {
      l = i - k;
      r = i + k;
    }
  }

  for(int i = 0, l = 0, r = -1; i < n; ++i) {
    int k = (i > r) ? 0 : min(d1[l+r-i+1], r-i+1);
    while(i-k-1>=0 && i+k<n && s[i+k-1] == s[i-k]) {
      k++;
    }
    d2[i] = k--;
    if(i+k > r) {
      l = i - k - 1;
      r = i + k;
    }
  }

  for(int i=0;i<n;i++) cout << d1[i] << " "; cout << endl;
  for(int i=0;i<n;i++) cout << d2[i] << " "; cout << endl;  

  return 0;
}
