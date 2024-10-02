class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Precompute prefix sums for each row
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        
        int ans = 0;
        
        // Iterate over all pairs of columns
        for (int colStart = 0; colStart < m; ++colStart) {
            for (int colEnd = colStart; colEnd < m; ++colEnd) {
                
                unordered_map<int, int> prefixSumCount;
                prefixSumCount[0] = 1;  // Initial condition for submatrices starting from row 0
                int currSum = 0;
                
                // Iterate over all rows
                for (int row = 0; row < n; ++row) {
                    // Compute the sum of elements in the current submatrix
                    currSum += matrix[row][colEnd] - (colStart > 0 ? matrix[row][colStart - 1] : 0);
                    
                    // Check if there is a prefix sum that matches the target
                    if (prefixSumCount.find(currSum - target) != prefixSumCount.end()) {
                        ans += prefixSumCount[currSum - target];
                    }
                    
                    // Increment the count of the current prefix sum
                    prefixSumCount[currSum]++;
                }
            }
        }
        
        return ans;
    }
};
