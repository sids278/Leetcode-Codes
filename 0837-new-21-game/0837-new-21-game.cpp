class Solution {
public:
    // basically if we reached a case i then f(i) would be possible only if greater than k --> before that game cant stop
    // so f(i)=f(i-1)+f(i-2)---f(k)
    //max jump we can make is maxpts so we can go to i-maxpts
    //thinking of a dp solution dp[i]=dp[i-1].1/maxpts+dp[i-2]/maxpts+---dp[i-maxpts]/maxpts
    //now above works correctly but there are corner cases to consider:
    //i>k eg i==21 ,k=18 here we cannot use 20 becuuase game stops at all values greaater than 18 so we say
    //dp[21]=dp[18].P(3)+dp[17]*P(4)+-----uptil maxpts consider
    // if i<maxpts 
    //gave tle if done simply:do by sliding window: one term is beinmg added when comparing dp[i+1] and dp[i] adn one term is removed
    double new21Game(int n, int k, int maxPts) {
       if (k == 0 || n >= k + maxPts) return 1.0;
        vector<double> dp(n + 1);
        dp[0] = 1.0;
        double sum = 1.0, res = 0.0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = sum / maxPts;
            if (i < k) sum += dp[i]; else res += dp[i];
            if (i - maxPts >= 0) sum -= dp[i - maxPts];
        }
        return res;
    }
};