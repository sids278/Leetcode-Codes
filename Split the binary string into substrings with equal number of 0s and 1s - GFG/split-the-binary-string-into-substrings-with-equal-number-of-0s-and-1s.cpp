//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
       
    int n = str.length();
    int zeros = 0, ones = 0; // Count of 0s and 1s in the current window
    int ans = 0; // Count of balanced substrings
    int start = 0; // Start of the current window

    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            zeros++;
        } else {
            ones++;
        }

        // If the current window has an equal number of 0s and 1s
        if (zeros == ones) {
            ans++;
            zeros = 0;
            ones = 0;
            start = i + 1; // Move the window's start to the next character
        }
    }

    // If we have processed the entire string and the counts are not equal
    if (zeros != ones) {
        return -1;
    }

    return ans;

        
    

    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends