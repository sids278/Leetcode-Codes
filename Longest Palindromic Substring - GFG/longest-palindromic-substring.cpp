//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    pair<int,int>f(int left,int right,int n,string s){
            while(left>=0 && right<n){
                if(s[left]==s[right]){
                    left--;
                    right++;
                }
                else{
                    return {left,right};
                }
            }
            return {left,right};
    }
    string longestPalindrome(string S){
        // code here 
        int n=S.size();
        int start=0;
        int l,r;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            //even
            
            auto x=f(i,i+1,n,S);
            l=x.first;
            r=x.second;
            
            if(ans<r-l-1){
                ans=r-l-1;
                start=l+1;
            }
            
            // odd 
            auto y=f(i-1,i+1,n,S);
            
            l=y.first;
            r=y.second;
            if(ans<r-l-1){
                ans=r-l-1;
                start=l+1;
            }
            
        }
        // cout<<start<<ans;
        return S.substr(start,ans);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends