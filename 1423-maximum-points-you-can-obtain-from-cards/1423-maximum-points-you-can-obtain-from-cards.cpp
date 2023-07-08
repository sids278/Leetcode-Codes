class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //last index that can be included is n-j
        int cnt=0;
        int sum=0;
        int ans=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        int i=k-1;
        ans=sum;
        int j=n-1;
        while(j>n-k-1){
            sum-=cardPoints[i];
            sum+=cardPoints[j];
            i--;
            j--;
             cout<<sum<<endl;
            ans=max(ans,sum);
           
            
        }
        
        return ans;
    }
};