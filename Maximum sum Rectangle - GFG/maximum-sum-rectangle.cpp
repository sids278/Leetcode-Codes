//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int kadane(vector<int>v)

  {

        int sum=0;

        int max=INT_MIN;

        for(int i=0;i<v.size();i++)

        {

            sum+=v[i];

            if(sum>max)

            max=sum;

            if(sum<0)

            sum=0;

        }

        return max;

    }

    

    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {

        // code here

        int mx =INT_MIN;

        for(int i = 0; i<R;i++)

        {

            vector<int>v(C,0);

            for(int i1 = i;i1<R;i1++)

            {

                for(int j =0;j<C;j++)

                {

                    v[j] += M[i1][j];

                }

                mx = max(mx,kadane(v));

            }

        }

        return (mx);

    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends