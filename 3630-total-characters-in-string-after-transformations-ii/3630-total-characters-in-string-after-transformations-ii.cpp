// Best approach--> we need to use matrix exponentiation

using Matrix = vector<vector<int>>;
const int MOD = 1e9 + 7;
const int ALPHABET = 26;
Matrix multiply(const Matrix &a, const Matrix &b) {
    Matrix res(ALPHABET, vector<int>(ALPHABET, 0));
    for (int i = 0; i < ALPHABET; ++i) {
        for (int k = 0; k < ALPHABET; ++k) {
            if (a[i][k] == 0) continue;
            for (int j = 0; j < ALPHABET; ++j) {
                res[i][j] = (res[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return res;
}

Matrix power(Matrix base, int exp) {
    Matrix res(ALPHABET, vector<int>(ALPHABET, 0));
    for (int i = 0; i < ALPHABET; ++i) res[i][i] = 1; 
    while (exp > 0) {
        if (exp % 2) res = multiply(res, base);
        base = multiply(base, base);
        exp /= 2;
    }
    return res;
}

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Matrix T(ALPHABET, vector<int>(ALPHABET, 0));
        for (int i = 0; i < ALPHABET; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                T[i][(i + j) % ALPHABET] = (T[i][(i + j) % ALPHABET] + 1) % MOD;
            }
        }

        Matrix T_exp = power(T, t);

        vector<int> freq(ALPHABET, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        vector<int> result(ALPHABET, 0);
        for (int i = 0; i < ALPHABET; ++i) {
            for (int j = 0; j < ALPHABET; ++j) {
                result[i] = (result[i] + 1LL * T_exp[j][i] * freq[j]) % MOD;
            }
        }

        int totalLength = 0;
        for (int count : result) {
            totalLength = (totalLength + count) % MOD;
        }
        return totalLength;
    }
};
// best approach understand this--> this is matrxi exponentiation