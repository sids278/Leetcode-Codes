//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    
    unordered_map<string,int> m;
  bool solve(string s){
     if(s.size()==0) return 1;
     
     for(int i=1;i<=s.size(); i++){
          string temp = (s.substr(0,i));
          if(m[temp]>0 && solve(s.substr(i,s.size()-i+1))){
              return 1;
          }else continue;
      }
      return 0;
  }
  int wordBreak(string s, vector<string>& wordDict) {
      for(int i=0;i<wordDict.size(); i++){
          m[wordDict[i]]++;
      }
    
      return solve(s);
   }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends