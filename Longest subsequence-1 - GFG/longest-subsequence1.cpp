//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i,int prev,int N,int A[]){
        if(i==N){
            return 0;
        }
        int notPick=f(i+1,prev,N,A);
        int pick=INT_MIN;
        if(abs(A[i]-A[prev])==1||prev==-1)pick=f(i+1,i,N,A)+1;
        return max(pick,notPick);
    }
    int longestSubsequence(int N, int A[])
    {
        // code here
        return f(0,-1,N,A);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends