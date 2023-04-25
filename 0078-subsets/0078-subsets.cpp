class Solution {
public:

    vector<vector<int>>ans;
    void backtrack(vector<int>&arr,int start,vector<int>&temp){
        ans.push_back(temp);
        for(int i=start;i<arr.size();i++){
            temp.push_back(arr[i]);
            backtrack(arr,i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        int n=arr.size();
        vector<int>temp;
        backtrack(arr,0,temp);
        return ans;
    }
};