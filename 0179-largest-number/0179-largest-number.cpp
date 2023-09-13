class Solution {
public:
    static bool compare(int a, int b){
            string s1 = to_string(a), s2=to_string(b);
            return s1+s2 > s2+s1;
    }

    string largestNumber(vector<int>& nums) {
        
        vector<pair<int,int>>v;
        sort(nums.begin(),nums.end(),compare);
        
        string str="";
        
        for(auto n:nums){
            
            str+=to_string(n);
        }
        if(nums[0]==0)return "0";

        return str;
    }
};