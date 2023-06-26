//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
       set<char>s(a.begin(),a.end());
       for(int i=0;i<a.size(); i++){
           s.erase(a[i]);
           if(s.empty()) break;
           if(*s.begin()<a[i]){
               char l=*s.begin(); char r=a[i];
               for(int j=0;j<a.size();j++){
                   if(a[j]==l) a[j]=r;
                   else if(a[j]==r) a[j]=l;
               }
               break;
           }
       }
       return a;
   }
   

    
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends