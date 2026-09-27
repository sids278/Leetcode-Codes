class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        int n=knowledge.size();
        for(int i=0;i<n;i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        
        int sSize=s.length();
        for(int i=0;i<sSize;i++){
            if(s[i]=='('){
                cout<<"got start at: "<<i<<endl;
                int start=i;
                while(i<sSize && s[i]!=')'){
                    i++;
                }
                if(s[i]==')'){
                    string inside=s.substr(start+1,i-start-1);
                    cout<<" index : "<<start<<" the end is "<<i<<" string to map "<<inside<<endl;
                    string getMap="?";
                    if(mp.find(inside)!=mp.end()){
                        getMap=mp[inside];
                    }
                    s.replace(start,i-start+1,getMap);
                    sSize = s.length();
                    i = start + getMap.length() - 1;
                }
            }
        }
        return s;
    }
};