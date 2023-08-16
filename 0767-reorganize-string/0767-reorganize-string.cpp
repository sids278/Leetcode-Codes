class Solution {
public:
    string reorganizeString(string str) {
//         unordered_map<char,int>mp;
//         for(auto x:s){
//             mp[x]++;
//         }
//         priority_queue<pair<int,int>>pq;
//         for(auto x:mp){
//             pq.push({x.second,x.first});
//         }
//         string ans="";
//         while(pq.size()>1){
//             auto fir=pq.top();
//             pq.pop();
            
//             auto sec=pq.top();
//             pq.pop();
//             if(fir.first>1){
//                 pq.push({fir.first-1,fir.second});
//             }
//             if(sec.first>1){
//                 pq.push({sec.first-1,sec.second});
//             }
//             ans+=fir.second;
//             ans+=sec.second;
            
//         }
//         if(pq.size()<=1){
//             if( pq.top().first==1)ans+=pq.top().second;
//             return ans;
//         }
//         else{
//             return "";
//         }
        unordered_map<char, int> freq;
        // max-heap
        priority_queue<pair<int, char>> max_heap;
        for(auto x: str)
            freq[x]++;
        
        for(auto it: freq)
            max_heap.push({it.second, it.first});
        
        str = "";
        while(max_heap.size() > 1){
            auto top1 = max_heap.top();
            max_heap.pop();
            auto top2 = max_heap.top();
            max_heap.pop();
            
            str += top1.second;
            str += top2.second;
            
            if(--top1.first > 0)
                max_heap.push(top1);
            if(--top2.first > 0)
                max_heap.push(top2);
            
        }
        
        if(max_heap.size()){
            if(max_heap.top().first == 1)
                str += max_heap.top().second;
            else
                return "";
        }
        
        return str;
    }
};