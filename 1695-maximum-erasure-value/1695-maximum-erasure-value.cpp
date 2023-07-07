class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ws=0;
        int we=0;
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        int sum=0;
        while(we<n){
            mp[nums[we]]++;
            sum+=nums[we];
                
      
            if(mp[nums[we]]==2){
                while(mp[nums[we]]==2){
                    sum-=nums[ws];
                    mp[nums[ws]]-=1;
                    ws++;
                    
                }
            }
            
            we++;
            cout<<sum<<endl;
            ans=max(ans,sum);
            
        }
        return ans;
        
    }
};