class Solution {
public:
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
	     s.push(-1);
         vector<int> ans(n);
	     for(int i=n-1; i>=0; i--){
	     int num = arr[i];
	     while( s.top()!= -1 && arr[s.top()]>= num){
	         s.pop();
	     }
	     
	     ans[i] = s.top();
	     s.push(i);
	    }
    return ans;
    }

    vector<int> prevSmallerElement(vector<int> arr, int n) {
            stack<int> s;
             s.push(-1);
             vector<int> ans(n);
             for(int i=0; i<n; i++){
             int num = arr[i];
             while( s.top()!= -1 &&arr[s.top()]>= num){
                 s.pop();
             }

             ans[i] = s.top();
             s.push(i);
            }
        return ans;
    }


public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int l = heights[i];

            if(next[i]== -1){
                next[i] = n;
            }

            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int ans=0;
        vector<int>heights(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]-'0'==1)
                {
                    heights[j]++;
                }
                else heights[j]=0;
            }
            
            ans=max(ans,largestRectangleArea(heights));
        }
        return ans;
    }
};