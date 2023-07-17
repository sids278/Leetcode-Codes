class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>indegree(n,0);
        for(auto road:roads){
            indegree[road[0]]++;
            indegree[road[1]]++;
        }
        
        sort(indegree.begin(),indegree.end());
        long long sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=(i+1)*indegree[i];
        }
        return sum;
    }
};