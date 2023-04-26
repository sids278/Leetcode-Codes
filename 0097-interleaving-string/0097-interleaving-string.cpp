class Solution {
public:
    bool solve(int i,int j,int k,string s1,string s2,string s3){
        if(k==s3.length()){return true;}
        if(i==s1.length()){
            while(j<s2.size() and k<s3.size()){
                if(s2[j++]!=s3[k++])
                return false;
            }
            return true;
        }
        if(j==s2.length()){
            while(i<s1.size() and k<s3.size()){
                if(s1[i++]!=s3[k++])
                return false;
            }
            return true;
        }
        
         if(s1[i]==s3[k] && s2[j]==s3[k]){return solve(i+1,j,k+1,s1,s2,s3) || solve(i,j+1,k+1,s1,s2,s3);}
        else if(s1[i]==s3[k]){return solve(i+1,j,k+1,s1,s2,s3);}
        else if(s2[j]==s3[k]){return solve(i,j+1,k+1,s1,s2,s3);}
        
        return false;
    }
    bool isPossibledp(string a, string b, string c){

        int m = a.size(), n = b.size(), p = c.size();

        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));

        for(int i=m;i>=0;i--){
            for(int j=n;j>=0;j--){

                int k = i+j;

                if(k == p)
                dp[i][j] = true;

                else if(i == m){
                        int flag=0;
                        int jj=j;
                    while(jj<b.size() and k<c.size()){
                        
                        if(b[jj++]!=c[k++])
                        flag = 1;
                    }
                    if(flag==0)
                    dp[i][j] = true;
                }

                else if(j == b.size()){
                    int flag=0;
                    int ii=i;
                    while(ii<a.size() and k<c.size()){
                        if(a[ii++]!=c[k++])
                        flag=1;
                    }
                    if(flag == 0)
                    dp[i][j] = true;
                }
                
                else if(a[i] == c[k] and b[j] == c[k]){

                    dp[i][j] = dp[i+1][j] or dp[i][j+1];

                }

                else if(a[i] == c[k])
                dp[i][j] = dp[i+1][j];

                else if(b[j] == c[k])
                dp[i][j] = dp[i][j+1];

                else
                dp[i][j] = false;


            }
        }
        return dp[0][0];
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length();
        int n2=s2.length();
        int n3=s3.length();
        if(n1+n2!=n3){
            return false;
        }
        return isPossibledp(s1,s2,s3);
        
    }
};