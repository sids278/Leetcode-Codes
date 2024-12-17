class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        map<int, vector<string>, greater<int>>mp2;
        vector<string>ans;
        int n=words.size();
        for(auto x:words){
            mp[x]++;
            
        }
        for(auto x:mp){
            mp2[x.second].push_back(x.first);
        }
        int cnt=0;
        for(auto x:mp2){
            vector<string>v=x.second;
            sort(v.begin(),v.end());
            for(auto y:v){
                if(k==0){
                    
                    return ans;
                }
                ans.push_back(y);
                k--;
            }
        }
        
        return ans;
    }
};