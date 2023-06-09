class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int tar=target-'a';
        for(int i=0;i<n;i++){
            int x=letters[i]-'a';
            if(x>tar)return letters[i];
        }
        return letters[0];
    }
};