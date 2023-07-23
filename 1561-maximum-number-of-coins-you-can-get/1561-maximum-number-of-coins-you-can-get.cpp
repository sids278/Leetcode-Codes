class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int ans=0;
        int n=piles.size();
        int i=n-2;
        int j=0;
        while(j<i){
            ans+=piles[i];
            i-=2;
            j+=1;
        }
        return ans;
    }
};