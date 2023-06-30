class Solution {
public:
    int totalUnique(int n) {
        if(n==1)
            return 10;
        int ans=9,k=9;
        for(int i=2;i<=n;i++) {
            ans*=k;
            k--;
        }
        return ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        int sum = 0;
        for(int i=1;i<=n;i++) {
            sum += totalUnique(i);
        }
        return sum;
    }
};