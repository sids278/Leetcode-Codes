class Solution {
public:
    bool valid(int t,vector<int>nums,int h){
        long long  ans=0;
        for(auto x:nums){
            if(x%t==0)ans+=x/t;
            
            else ans+=x/t +1;
        }
        if(ans<=h)return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int avg=0;
        int mx=0;
        for(auto x:piles){
            avg+=x/h;
            mx=max(mx,x);
        }
        
        int l=avg==0?1:avg;
        int r=mx;
        int ans=-1;
        int mi;
        while(l<=r){
            mi=(l+r)/2;
            if(valid(mi,piles,h)){
                ans=mi;
                r=mi-1;
            }
            else{
                l=mi+1;
            }
        }
        return ans;
    }
};