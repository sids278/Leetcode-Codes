class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        //[3,4,2,3,4,7]
        map<int,int>mp;
        int n=cards.size();
        int ans=1e9;
        for(int i=0;i<n;i++){
            if(mp.find(cards[i])!=mp.end()){
                ans=min(i-mp[cards[i]]+1,ans);
                
            }
            mp[cards[i]]=i;
        }
        return ans==1e9?-1:ans;
    }
};