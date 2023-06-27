//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int search(int l,int r,int k,int arr[],int n){
        if(l>r)return -1;
        int mid=(l+r)/2;
        if(arr[mid]==k)return mid;
        if(arr[mid]>k){
            return search(l,mid-1,k,arr,n);
        }
        return search(mid+1,r,k,arr,n);
    }
    int binarysearch(int arr[], int n, int k) {
        // code here
        int l=0;
        int r=n-1;
        return search(l,r,k,arr,n);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends