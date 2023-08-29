//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    struct comp{
       bool operator()(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
           if(a.first > b.first) return (true);
           if(b.first > a.first) return (false);
           return a.second.first < b.second.first;
       }
   };
   
   int countSetBits(int n){
       int cnt = 0;
       while(n){
           if(n % 2 == 1) cnt++;
           n /= 2;
       }
       
       return (cnt);
   }
   
   void sortBySetBitCount(int arr[], int n){
       pair<int,pair<int,int>> v[n];
       for(int i=0; i<n; i++){
           v[i] = {countSetBits(arr[i]),{i,arr[i]}};
       }
       sort(v,v+n,comp());
       
       for(int i=0; i<n; i++){
           arr[i] = v[i].second.second;
       }
   }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends