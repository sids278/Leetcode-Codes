//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool helper(int sum,int s,int inx,int k,int n,int a[],bool arr[]){
        if(k==1)return true;
        if(sum>s)return false;
        if(sum==s){
            return helper(0,s,0,k-1,n,a,arr);
        }
        for(int i=inx;i<n-1;i++){
            if(arr[i]==false){
                arr[i]=true;
                if(helper(sum+a[i],s,inx+1,k,n,a,arr)){
                    return true;
                }
                else arr[i]=false;
            }
        }
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
        if(k==0)return 0;
        if(k==1)return 1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        if(sum%k!=0)return false;
        bool arr[n]={false};
        return helper(0,sum/k,0,k,n,a,arr);
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
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends