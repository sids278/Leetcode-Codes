
class Solution {
public:
    // s1 holds the xsum elements, remanining goes to s2
    set<pair<int,int>> s1, s2;

    long long getXSum(unordered_map<int,int>& cnt, int x) {
        long long res = 0;
        for(auto [num, c]: cnt) {
            s2.insert({c, num});
        }

        while(!s2.empty() && s1.size() < x) {
            auto itr = s2.rbegin();
            // cout<<itr->first<<" "<<itr->second<<endl;
            res += (long long)(itr->first)*(itr->second);
            s1.insert(*itr);
            s2.erase(prev(s2.end()));
        }

        return res;
    }

    void updateSets(int x, long long& xsum) {
        // Just adjusting the s1 size and inserting one extra element (x+1) from s2 to s1 to remove the single element anomaly.
        // make sure to update the xsum as well.
        while(s1.size() < x+1 && !s2.empty()) {
            s1.insert(*s2.rbegin());
            xsum += (long long)(s2.rbegin()->first) * (s2.rbegin()->second);
            s2.erase(prev(s2.end()));
        }
        // Now remove the extra element to make the s.size() <= x
        // make sure to update the xsum as well.
        while(s1.size() > x) {
            s2.insert(*s1.begin());
            xsum -= (long long)(s1.begin()->first) * (s1.begin()->second);
            s1.erase(s1.begin());
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        unordered_map<int,int> cnt;
        vector<long long> res;

        for(int i = 0; i < k; i++) {
            ++cnt[nums[i]];
        }
        long long xsum = getXSum(cnt, x);
        res.push_back(xsum);

        // showSets();
        for(int i = k; i < n; i++) {
            int a = nums[i-k];
            int b = nums[i];
            if(a == b){
                res.push_back(xsum);
                // showSets();
                continue;
            }
            int cntA = cnt[a];
            int cntB = cnt[b];
            auto itrA1 = s1.find({cntA, a});
            auto itrA2 = s2.find({cntA, a});
            auto itrB1 = s1.find({cntB, b});
            auto itrB2 = s2.find({cntB, b});

            --cnt[a];
            ++cnt[b];

            // remove left num (a) and update xsum
            if(itrA1 != s1.end()) {
                s1.erase(itrA1);
                xsum -= a;
                if(cntA > 1) {
                    s1.insert({cntA-1, a});
                }
            } else if(itrA2 != s2.end()){
                s2.erase(itrA2);
                if(cntA > 1) {
                    s2.insert({cntA-1, a});
                }
            }
            
            // insert right num (b) and update xsum
            if(itrB1 != s1.end()) {
                s1.erase(itrB1);
                xsum += b;
                s1.insert({cntB+1, b});
            } else if(itrB2 != s2.end()){
                s2.erase(itrB2);
                s2.insert({cntB+1, b});
            } else {
                s2.insert({cntB+1, b});
            }
            
            // this is crucial to correct the s1 set (holding xsum elements)
            updateSets(x, xsum);

            res.push_back(xsum);
            // showSets();
        }

        return res;
    }

    // void showSets() {
    //     for(auto s: s1){
    //         cout<<s.second<<" "<<s.first<<"; ";
    //     }
    //     cout<<"    ";
    //     for(auto s: s2){
    //         cout<<s.second<<" "<<s.first<<"; ";
    //     }
    //     cout<<endl;
    // }

};