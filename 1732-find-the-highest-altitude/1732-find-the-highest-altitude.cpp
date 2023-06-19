class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>pre(n+1,0);
        pre[0]=0;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+gain[i-1];
        }
        sort(pre.begin(),pre.end());
        if(pre[n]>0)return pre[n];
        return 0;
    }
};