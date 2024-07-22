class Solution {
public:
    //-->[0,0,4,4]
    
    //binary search on answer types question hai
    bool possible(int x,vector<int>&c){
        int ans=0;
        for(auto v:c){
            if(v>=x)ans++;
            if(ans>=x)return true;
        }
        if(ans>=x)return true;
        return false;
    }
    
    
    int hIndex(vector<int>& c) {
        int minV=INT_MAX;
        int maxV=-1;
        for(auto x:c){
            minV=min(minV,x);
            maxV=max(maxV,x);
        }
        int ans;
        int m;
        int n=c.size();
        while(minV<=maxV){
            m=(minV+maxV)/2;
            if(possible(m,c)){
                ans=m;
                minV=m+1;
            }
            else{
                cout<<"came here "<<m<<endl;
                maxV=m-1;
            }
        }
        
        return min(ans,n);
        
        
    }
};