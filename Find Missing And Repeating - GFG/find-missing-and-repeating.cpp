//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int>answer(2,-1);
        int i=0;
        int value=0;
        int element=0;
        
        for(i=0; i<n;i++){
            value = abs(arr[i]);
            element = arr[value-1];
            if(element > 0) arr[value-1] = -element;
            else answer[0]=value;
        }
        for(i=0;i<n;i++){
            if(arr[i]>0){
                answer[1]=i+1;
                break;
            }
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends