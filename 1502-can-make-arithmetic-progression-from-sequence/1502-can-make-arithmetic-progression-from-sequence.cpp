class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();
        if(n==1||n==2)return true;
        sort(arr.begin(),arr.end());
        int d=arr[1]-arr[0];
        for(int i=0;i<n;i++){
            if(arr[i]!=arr[0]+d*i)return false;
        }
        return true;
    }
};