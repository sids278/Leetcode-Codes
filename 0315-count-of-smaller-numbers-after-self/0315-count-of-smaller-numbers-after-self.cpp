class Solution {
public:
    int adder(int x, vector<int>& temp) {
        int l = 0;
        int r = temp.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (temp[mid] < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> v;
        vector<int> temp;
        int n = nums.size();
        if(n==0||n==1)return {0};
        temp.push_back(nums[n - 1]);
        v.push_back(0);

        for (int i = n - 2; i >= 0; i--) {
            int pos = adder(nums[i], temp);
            v.push_back(pos);
            temp.insert(temp.begin() + pos, nums[i]);
        }

        reverse(v.begin(), v.end());
        return v;
    }
};
