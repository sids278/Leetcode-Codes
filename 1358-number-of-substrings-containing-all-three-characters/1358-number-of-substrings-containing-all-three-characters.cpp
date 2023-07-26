class Solution {
public:
    int numberOfSubstrings(string s) {
          int i = 0;
        int j = 0;
        int n = s.length();
        int cnt = 0;

        // Initialize a, b, c based on the first character of the string
        int a = (s[i] == 'a') ? 1 : 0;
        int b = (s[i] == 'b') ? 1 : 0;
        int c = (s[i] == 'c') ? 1 : 0;

        while (i <= j && j < n) {
            bool cond = a >= 1 && b >= 1 && c >= 1;
            if (!cond) {
                j++;
                if (j < n) {
                    // Update a, b, c based on the current character
                    if (s[j] == 'a') a++;
                    if (s[j] == 'b') b++;
                    if (s[j] == 'c') c++;
                }
            } else {
                // Count the number of substrings satisfying the condition
                cnt += n - j;

                // Update a, b, c and move the window
                if (s[i] == 'a') a--;
                if (s[i] == 'b') b--;
                if (s[i] == 'c') c--;
                i++;
            }
        }
        return cnt;
    }
};