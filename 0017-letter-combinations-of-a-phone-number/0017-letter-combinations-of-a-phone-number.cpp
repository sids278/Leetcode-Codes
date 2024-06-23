class Solution {
public:
    unordered_map<string, vector<string>> mp = {
        {"2", {"a", "b", "c"}},
        {"3", {"d", "e", "f"}},
        {"4", {"g", "h", "i"}},
        {"5", {"j", "k", "l"}},
        {"6", {"m", "n", "o"}},
        {"7", {"p", "q", "r", "s"}},
        {"8", {"t", "u", "v"}},
        {"9", {"w", "x", "y", "z"}}
    };

    vector<string>ans;
    vector<string>f(string number){
        if(number.empty())return{};
        int n=number.length();
        if(n==1)return mp[number];
        char start=number[0];
        string noho(1, start);
        vector<string>v=mp[noho];
        vector<string>prev=f(number.substr(1));
        for(auto x:prev){
            for(auto y:v){
                string wow=y+x;
                if(wow.length()==n)ans.push_back(wow);
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i].length()!=n)ans.erase(ans.begin()+i);
        }
        return ans;
    }
    vector<string> letterCombinations(string number) {
        int n=number.size();
        vector<string>rs=f(number);
        vector<string>ans1;
        for(auto x:rs){
            if(x.length()==n)ans1.push_back(x);
        }
        return ans1;
    }
};