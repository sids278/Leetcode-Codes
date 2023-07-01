//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    int dp[1001][1001];
    int solve (int i, int j, int a[]){
        
        if (i > j)
         return 0;
         
         if (dp[i][j] != -1)
          return dp[i][j];
          
         int x= a[i]+ min (solve (i+2, j, a), solve (i+1, j-1, a));
         int y= a[j]+ min (solve (i, j-2, a), solve (i+1, j-1, a));
         
         return dp[i][j]= max (x,y);
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        dp[n][n];
        memset(dp, -1, sizeof (dp));
        return solve (0, n-1 , arr);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends