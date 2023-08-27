//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        map<char,char> mp;
        mp['{'] = '}';
        mp['('] = ')';
        mp['['] = ']';
        
        stack<char> st;
        for(int i =0;i<x.length();i++){
            if(x[i]=='}'||x[i]==')'||x[i]==']'){
                if(st.empty()) return false;
                if(mp[st.top()]!=x[i]) return false;
                else{ st.pop(); continue;}
            }
            else st.push(x[i]);
        }
        
         return st.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends