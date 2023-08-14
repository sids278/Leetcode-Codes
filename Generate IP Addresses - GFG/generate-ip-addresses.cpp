//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    bool isValidSegment(const string &segment) {
    if (segment.size() > 1 && segment[0] == '0') {
        return false; // Avoid leading zeros
    }
    int num = stoi(segment);
    return num >= 0 && num <= 255;
    }
    
    void backtrack(string &s, int start, int segmentsLeft, string current, vector<string> &result) {
        if (segmentsLeft == 0) {
            if (start == s.size()) {
                result.push_back(current);
            }
            return;
        }
    
        for (int i = 1; i <= 3 && start + i <= s.size(); ++i) {
            string segment = s.substr(start, i);
            if (isValidSegment(segment)) {
                string newSegment = current.empty() ? segment : current + "." + segment;
                backtrack(s, start + i, segmentsLeft - 1, newSegment, result);
            }
        }
    }
    
    vector<string> genIp(string &s) {
        vector<string> result;
        backtrack(s, 0, 4, "", result);
        return result;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends