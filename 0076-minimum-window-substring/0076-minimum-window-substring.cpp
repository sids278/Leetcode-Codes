class Solution {
public:
    bool isValid(unordered_map<char , int> &ofstr, unordered_map<char , int>&oftemp){
        for(auto x : oftemp){
            if(ofstr[x.first] < oftemp[x.first])return false;
        }
        return true;
    }
    pair<int,int> solve(string &str , string &temp){
             unordered_map<char , int> ofstr;
             unordered_map<char , int> oftemp;
             for(auto x : temp)oftemp[x]++;
             int i = -1;
             int j = -1;
             int n = str.size();
             int index = -1;
             int size = INT_MAX;
             while(true){
                 bool flag1 = false;
                 bool flag2 = false;
                 while(i+1<n){
                     flag1 = true;
                     i++;
                     ofstr[str[i]]++;
                     if(isValid(ofstr , oftemp)){
                         break;
                     }
                 }
                 cout<<i<<"  "<<j<<endl;
                 while(j+1<n && isValid(ofstr , oftemp)){
                    flag2 = true;
                    if(size > (i - j)){
                             size = (i - j);
                             index = j + 1;
                     }
                     j++;
                     ofstr[str[j]]--;
                 }
                 if(flag1 == false && flag2==false)break;
             }
             return {index , size};
    }
    string minWindow(string s, string t) {
        pair<int,int> temp = solve(s , t);
        if(temp.first == -1) return "";
        int index = temp.first;
        int size = temp.second;
        return s.substr(index , size);
    }
};