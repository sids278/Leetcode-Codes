class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res=0;
        while(a||b||c){
            int ai=a%2;
            int bi=b%2;
            int ci=c%2;
            if(ci==1 && ai+bi==0){
                res++;
            }
            else if(ci==0)res+=ai+bi;
            a=a/2;
            b=b/2;
            c=c/2;
        }
        return res;
    }
};