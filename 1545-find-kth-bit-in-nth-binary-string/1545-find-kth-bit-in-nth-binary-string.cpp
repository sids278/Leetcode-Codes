class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
    string invertBits(string s) {
        for (char &c : s) {
            if (c == '0')
                c = '1';
            else if (c == '1')
                c = '0';
        }
        return s;
    }
    string recursiveWork(int n){
        if(n==1)return "0";
        string prevString=recursiveWork(n-1);
        return prevString+"1"+reverseString(invertBits(prevString));

    }
    char findKthBit(int n, int k) {
        // string s1="0";
        // string si="1"+ reverse(invert(si-1));
        string x=recursiveWork(n);
        if(k==1)return '0';
        cout<<" string found is :"<<x;
        return x[k-1];
        
    }
};