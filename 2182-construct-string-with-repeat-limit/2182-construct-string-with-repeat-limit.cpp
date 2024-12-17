class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char,int>mp;
        for(auto x:s){
            mp[x]++;
        }
        priority_queue<pair<char,int>> pq;
        for(auto x:mp){
            pq.push({x.first,x.second});
        }
        string ans="";
        while(!pq.empty()){
            auto y=pq.top();
            pq.pop();
            if(y.second<=repeatLimit){
                for(int i=0;i<y.second;i++){
                    ans+=y.first;
                }
                
            }
            else{
                for(int i=0;i<repeatLimit;i++){
                    ans+=y.first;
                }
                if(pq.empty())break;
                auto next=pq.top();
                pq.pop();
                ans+=next.first;
                if(next.second-1)pq.push({next.first,next.second-1});
                int cnt=y.second-repeatLimit;
                pq.push({y.first,cnt});
            }
        }
        return ans;
    }
};