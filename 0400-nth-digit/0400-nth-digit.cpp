class Solution {
public:
     // numbr of single digits is 9
    // number of 2 digit numbers is 90
    // number of 3 digit number is 900
    int findNthDigit(int n) {
        if (n <= 9) return n;

        // Step 1: Calculate how many digits the number has.
        long base = 9, digits = 1;
        while (n - base * digits > 0) {
            n -= base * digits;
            base *= 10;
            digits++;
        }

        // Step 2: Calculate what the number is.
        int index = n % digits;
        if (index == 0) index = digits;
        long num = 1;
        for (int i = 1; i < digits; i++) num *= 10;
        num += (index == digits) ? n / digits - 1 : n / digits;

        // Step 3: Find out which digit in the number is wanted.
        string numStr = to_string(num);
        return numStr[index - 1] - '0';
    }
    
};