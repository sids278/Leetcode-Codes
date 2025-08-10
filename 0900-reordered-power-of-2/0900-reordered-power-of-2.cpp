class Solution {
public:
    string countDigits(int x) {
        string s = to_string(x);
        sort(s.begin(), s.end());
        return s;
    };
    // here the countDigits function is doing something like if 2>xis eqaul to some rearrangement of n then if we sort all the characters of both strings then they should be same
    // the maximum we can go 2^31 till 10^9 so till then we see signatures-> fancy name of sorted string of digites of a number to see if it matches the signature of n also if it does true otherwise not
    bool reorderedPowerOf2(int n) {
        
        string target = countDigits(n);
        for (int i = 0; i < 31; i++) {
            if (countDigits(1 << i) == target) return true;
        }
        return false;
    }
    // here
};