class Solution {
public:
    bool search(int l,int r,vector<int>&v,int target){
        if(l>r)return false;
        int mid=(l+r)/2;
        if(v[mid]==target)return true;
        if(v[mid]>target)return search(l,mid-1,v,target);
        return search(mid+1,r,v,target);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][m-1]>=target){
                return search(0,m-1,matrix[i],target);
            }
        }
        return false;
    }
};