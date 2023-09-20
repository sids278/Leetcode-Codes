class Solution {
public:
    int reverse(int x) {
        string s=to_string(x);
        
        std::reverse(s.begin(), s.end());
        
        
        try {
        int reversed = std::stoi(s);
        return x < 0 ? -reversed : reversed;
    } catch (const std::out_of_range& e) {
        return 0;
    }
    }
};