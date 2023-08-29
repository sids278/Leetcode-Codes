//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int BS(int arr[],int i,int j,int x,char t){
    int res=-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(arr[mid]==x){
            res=mid;
            if(t=='f'){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        else if(arr[mid]<x){
            i=mid+1;
        }
        else{
            j=mid-1;
        }
    }
    return res;
}
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int>v(n,-1);
    v[0]=BS(arr,0,n-1,x,'f');
    v[1]=BS(arr,0,n-1,x,'l');
    return v;
}
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends