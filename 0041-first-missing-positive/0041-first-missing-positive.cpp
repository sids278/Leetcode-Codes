class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxI=-1;
        for(auto x:nums){
            if(x>0)mp[x]=1;
            maxI=max(maxI,x);
        }
        if(mp.find(1)==mp.end())return 1;
        int n=nums.size();
        int ans=1e9;
        for(int i=1;i<maxI;i++){
            if(mp.find(i)==mp.end()){
                return i;
            }
        }
        
        return maxI+1;
        
    }
};