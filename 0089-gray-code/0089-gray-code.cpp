class Solution {
public:

    vector<int> grayCode(int n) {
        if(n==1)return {0,1};
        if(n==2)return {0,1,3,2};
        vector<int>prev=grayCode(n-1);
        vector<int>ans;
        int counter=0;
        for(auto x:prev){
            if(counter%2==0){
                ans.push_back(x<<1);
                ans.push_back((x<<1)+1);
            }
            else{
                ans.push_back((x<<1)+1);
                ans.push_back(x<<1);
            }
            counter++;
        }
        return ans;
        
        
    }
};