class Solution {
public:
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n2=potions.size();
        
        sort(potions.begin(),potions.end());
        int n=spells.size();
        for(int i=0;i<n;i++){
            double req= (double)success/ (double)spells[i];
            req=ceil(req);
            
            int idx=lower_bound(potions.begin(),potions.end(),req)-potions.begin();
            ans.push_back(n2-idx);
            
        }
        return ans;
    }
};