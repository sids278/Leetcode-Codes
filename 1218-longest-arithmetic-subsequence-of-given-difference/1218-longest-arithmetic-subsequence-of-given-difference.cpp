class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
         int res = 1;
        unordered_map<int,int> maxmap; // key : element in arr ; value : longest length for AS based on diff
        for(int i = 0 ; i < arr.size() ; i++){
            maxmap[arr[i]] = maxmap[arr[i]-difference]+1;
            res = max(res,maxmap[arr[i]]);
        }
        return res;
    }
};