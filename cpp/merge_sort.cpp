#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr,int l,int m,int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int left[n1],right[n2];

    int i=0; // iterator for left array
    int j=0; // for right array
    int k=l; // for original array

    for(int i=0;i<n1;i++)left[i] = arr[l+i];  // copy the elemnts in right and left subarray

    for(int i=0;i<n2;i++)right[i] = arr[m+1+i];

    while(i<n1 and j<n2){
        if(left[i]<=right[j]){
            arr[k++] = left[i];
            i++;
        }else{
            arr[k++] = right[j];
            j++;
        }
    }

    // copy the remaining elements (one of arrays will still have remaining elements)
    while(i<n1){
        arr[k++] = left[i++];
    }
    while(j<n2){
        arr[k++] = right[j++];
    }

}

void merge_sort(vector<int>& arr,int left, int right){
    // Time O(n*log2(n)) in all 3 cases
    // Space o(n)
    // Stable : YES
    // In-Place :NO
    if(left<right){
        int mid = (left+right)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    merge_sort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}
