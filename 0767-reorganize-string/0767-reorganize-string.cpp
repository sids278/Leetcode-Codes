class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(auto x:s){
            mp[x]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        string ans="";
        while(pq.size()>1){
            auto fir=pq.top();
            pq.pop();
            
            auto sec=pq.top();
            pq.pop();
            if(fir.first>1){
                pq.push({fir.first-1,fir.second});
            }
            if(sec.first>1){
                pq.push({sec.first-1,sec.second});
            }
            ans+=fir.second;
            ans+=sec.second;
            // cout<<fir.second<<sec.second<<endl;
            
        }
        if(pq.size()==1){
            // cout<<"camr here";
            if( pq.top().first==1)ans+=pq.top().second;
            else return "";
            return ans;
        }
        return ans;
        
        
    }
};