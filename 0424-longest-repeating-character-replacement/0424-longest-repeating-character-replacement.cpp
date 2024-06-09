class Solution {
public:
    
    int characterReplacement(string s, int k) {
         
         unordered_map<char,int>map;
         int left=0,right=0;
         int n=s.size();
         int maxcount,result=0;

        while(right<n)
        {
           map[s[right]]++;
           maxcount=max(maxcount,map[s[right]]);
           if(right-left+1-maxcount>k)
           {
          map[s[left]]--;

            left++;
           }

         result=max(result,right-left+1);
         right++;
 
        }
        return result;
    }
};