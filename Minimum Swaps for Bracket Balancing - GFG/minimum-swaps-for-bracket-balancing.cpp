//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here 
        int n= S.length();
       int open=0, close=0,swp=0,unbalance=0;
       
      
       for(int i=0; i<n; i++)
       {
           if(S[i]=='[')
           {
               open++;
               
               if(unbalance>0)
               {
                   swp+=unbalance;
                  
               }
           }
           else if(S[i]==']')
           {
               close++;
           }
       
          unbalance = close- open;
       }
       return swp;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends