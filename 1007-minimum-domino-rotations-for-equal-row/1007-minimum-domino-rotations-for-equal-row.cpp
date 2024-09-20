class Solution {
public:
    int f(int x,vector<int>&tops,vector<int>&bottoms){
        int n=tops.size();
        
        int ops=0;
        // first for top
        for(int i=0;i<n;i++){
            if(tops[i]==x)continue;
            else if(bottoms[i]==x)ops++;
            else {
                ops=1e9;
                break;
            }
        }
        int ops2=0;
        for(int i=0;i<n;i++){
            if(bottoms[i]==x)continue;
            else if(tops[i]==x)ops2++;
            else{
                ops2=1e9;
                break;
            }
        }
        ops=min(ops,ops2);
        return ops;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans=1e9;
        for(int i=1;i<=6;i++){
            ans=min(ans,f(i,tops,bottoms));
        }
        return ans==1e9?-1:ans;
    }
};