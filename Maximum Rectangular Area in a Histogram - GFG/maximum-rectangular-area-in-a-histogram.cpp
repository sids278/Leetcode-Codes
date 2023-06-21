//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<int> nsl(long long arr[], int n)
    {
        vector<int> v;
        stack<pair<long long, int>> st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and st.top().first>=arr[i])
            st.pop();
            
            st.empty()? v.push_back(-1): v.push_back(st.top().second);
            st.push({arr[i],i});
        }
        return v;
    }
    
    
    vector<int> nsr(long long arr[], int n)
    {
        vector<int> v;
        stack<pair<long long, int>> st;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and st.top().first>=arr[i])
            st.pop();
            
            st.empty()? v.push_back(n): v.push_back(st.top().second);
            st.push({arr[i],i});
        }
        reverse(v.begin(),v.end());
        return v;
    }
    
    
    long long getMaxArea(long long arr[], int n)
    {
        vector<int> left=nsl(arr,n);
        vector<int> right=nsr(arr,n);
        long long ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans,arr[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends