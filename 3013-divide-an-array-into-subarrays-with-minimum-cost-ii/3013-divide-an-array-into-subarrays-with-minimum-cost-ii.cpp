class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        set<pair<long long, long long>> kMinimum;       //(k-1) minimum elements since first element is known
        set<pair<long long, long long>> remaining;      

        long long sum = 0;

        int i = 1;
        while(i - dist < 1) {
            kMinimum.insert({nums[i], i});
            sum += nums[i];

            if(kMinimum.size() > k - 1) {
                pair<long long, long long> temp = *kMinimum.rbegin();
                sum -= temp.first;
                remaining.insert(temp);
                kMinimum.erase(temp);
            }

            i++;
        }

        long long result = LLONG_MAX;

        while(i < nums.size()) {
            kMinimum.insert({nums[i], i});
            sum += nums[i];

            if(kMinimum.size() > k - 1) {
                pair<long long, long long> temp = *kMinimum.rbegin();
                sum -= temp.first;
                remaining.insert(temp);
                kMinimum.erase(temp);
            }

            result = min(result, sum);

            // shift window
            pair<long long, long long> remove = {nums[i - dist], i - dist};
            if(kMinimum.count(remove)) {
                kMinimum.erase(remove);
                sum -= remove.first;

                if(!remaining.empty()) {
                    pair<long long, long long> temp = *remaining.begin();
                    kMinimum.insert(temp);
                    sum += temp.first;
                    remaining.erase(temp);
                }
            } else {
                remaining.erase(remove);
            }

            i++;
        }

        return nums[0] + result;
    }
};