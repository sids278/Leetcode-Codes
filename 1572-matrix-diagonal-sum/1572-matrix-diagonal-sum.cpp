class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(n-1-i!=i){
                sum+=mat[i][i];
               sum+=mat[i][n-1-i];
            }
            else{
                sum+=mat[i][i];
            }
        }
        return sum;
    }
};