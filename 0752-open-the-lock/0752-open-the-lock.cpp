class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        
        if(dead.find("0000") != dead.end()) return -1;
        
        q.push({"0000", 0});
        visited.insert("0000");
        
        while(!q.empty()) {
            string cur = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(cur == target) return steps;
            
            for(int i = 0; i < 4; ++i) {
                string next = cur;
                
                // Try moving the wheel forward
                next[i] = (cur[i] - '0' + 1) % 10 + '0';
                if(visited.find(next) == visited.end() && dead.find(next) == dead.end()) {
                    q.push({next, steps + 1});
                    visited.insert(next);
                }
                
                // Try moving the wheel backward
                next[i] = (cur[i] - '0' + 9) % 10 + '0';
                if(visited.find(next) == visited.end() && dead.find(next) == dead.end()) {
                    q.push({next, steps + 1});
                    visited.insert(next);
                }
            }
        }
        
        return -1;  // If we can't reach the target
    }
};
