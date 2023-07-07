class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0;
        int ans=0;
        int n=grumpy.size();
        int start=0;
        // window code maximum you can get out of grumpy minutes
        // [4,10,10]
        // [1,1,0]
        // 2
        for(int i=0;i<n;i++){
            if(grumpy[i]==1)sum+=customers[i];
            if(i>=minutes){
                if(grumpy[i-minutes]==1)sum-=customers[i-minutes];
            }
            ans=max(ans,sum);
            
        }
        cout<<ans;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0)ans+=customers[i];
            
        }
        return ans;
    }
};