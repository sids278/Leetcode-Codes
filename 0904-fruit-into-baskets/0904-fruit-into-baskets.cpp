class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> mp;
        int j = 0;
        int i=0;
        int ans = 0;
        while(i<n){
            mp[fruits[i]]++;
            if(mp.size()>2){
                mp[fruits[j]]--;
                if(mp[fruits[j]]==0){
                    mp.erase(fruits[j]);
                }
                j++;
            }
            // cout<<i<<" "<<j<<endl;
            ans = max(i-j+1,ans);
            i++;
            
        }
        return ans;
    }
};