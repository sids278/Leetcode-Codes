class Solution {
public:
    
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<bool> rowFlag(n, true), colFlag(n, true);
long long totalSum = 0, remainingRows = n, remainingCols = n;

for (int i = queries.size() - 1; i >= 0; --i) {
    int queryType = queries[i][0];
    int index = queries[i][1];
    int value = queries[i][2];

    if (queryType == 0 && rowFlag[index]) {
        totalSum += remainingCols * value;
        rowFlag[index] = false;
        remainingRows--;
    }
    if (queryType == 1 && colFlag[index]) {
        totalSum += remainingRows * value;
        colFlag[index] = false;
        remainingCols--;
    }
}

return totalSum;
    }
};