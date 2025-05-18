class Solution {
public:
    int mod = pow(10,9)+7;
    int get_prev_color(int num, int row){
        num = num >> (row*2);
        return num & 3;
    }
    int recurator(int& n, int& m, vector<vector<int>>& h, int prev_state, int curr_state, int ni, int mi){
        if(ni != 0 && h[ni-1][prev_state] != -1) return h[ni-1][prev_state];
        if(n == ni) return 1;
        if(m == mi) {
            h[ni][curr_state] = recurator(n,m,h,curr_state,0,ni+1,0);
            return h[ni][curr_state];
        }
        
        int ans = 0;
        
        for(int i = 1; i < 4; i++){
            int prev_row = get_prev_color(prev_state,m-mi-1);
            int prev_col = get_prev_color(curr_state,0);
            if(i != prev_row && i != prev_col) 
                ans = (ans%mod + recurator(n,m,h,prev_state,(curr_state<<2)+i,ni,mi+1)%mod)%mod;
        }
        return ans;
    }
    int colorTheGrid(int m, int n) {
        vector<vector<int>> h(n,vector<int>(1024,-1));
        return recurator(n,m,h,0,0,0,0);
    }

};