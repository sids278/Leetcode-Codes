//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int n = S.length();
       int result = 0;
       int sum = 0;
       
       for(int i=0;i<n;i++){
           if(S[i] == '0') sum++;
           else sum--;
           if(sum < 0){
               sum = 0;
               continue;
           }
           result = max(result,sum);
       }
       if(result == 0) return -1;
       return result;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends