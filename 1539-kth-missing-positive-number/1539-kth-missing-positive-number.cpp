class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int l=0;
        int r=n-1;
        int mi;
        int missing=0;
        while(l<=r){
            mi=(l+r)/2;
            if( mi>0 && arr[mi]-mi-1>=k && arr[mi-1]-mi<k){
                return arr[mi-1]+k-(arr[mi-1]-mi);
            }
            else if(arr[mi]-mi-1<k){
                missing=arr[mi]-mi-1;
                l=mi+1;
            }
            else{
                
                r=mi-1;
            }
        }
        
        if(arr[0]-k>0)return k;
        return arr[n-1]+k-missing;
        
    }
};