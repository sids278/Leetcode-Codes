class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        if(k==0){
            vector<int>ans(n,0);
            return ans;
        }
        vector<int>ans(n,0);
        if(k>0){
                int sum=0;
            for(int i=1;i<=k;i++){
                sum+=code[i];
            }

           
             ans[0]=sum;
            for(int i=1;i<n;i++){
                sum+=code[(i+k)%n];
                sum-=code[i];
                ans[i]=sum;

            }
        }
        if(k<0){
            int sum=0;
            k*=-1;
            
            for(int i=n-1;i>n-1-k;i--){
                sum+=code[i];
            }
            ans[0]=sum;
            for(int i=1;i<n;i++){
                if(i-k<1){
                    sum-=code[n-1-(k-i)];
                    
                }
                else sum-=code[i-k-1];
                sum+=code[i-1];
                ans[i]=sum;
            }
        }
        return ans;
    }
};