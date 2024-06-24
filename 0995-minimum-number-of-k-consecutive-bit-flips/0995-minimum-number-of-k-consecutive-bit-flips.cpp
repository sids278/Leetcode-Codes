class Solution {
public:
    int minKBitFlips(vector<int>& arr, int k) {
        int flips = 0 ,ans= 0 ;
        int  i, n = arr.size();
        vector<int>flipped(n,false);
        //flipped[i] --i th index is flipped or nt
        for(i=0;i<n;i++)
        {
            //window change hono pe last result minus karege 
            if(i>=k)
            flips -= flipped[i-k];
            if((arr[i]==0 &&flips%2==0 ) ||(arr[i]==1 &&flips%2==1))
            {
                if(i+k>n)
                return -1;
                ans++;
                flips++;
                flipped[i] = 1;
            }

    
        }
        return ans;
    }
};