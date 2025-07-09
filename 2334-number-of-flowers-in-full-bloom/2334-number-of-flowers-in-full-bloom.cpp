class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        priority_queue<int, vector<int>, greater<int>> starts, ends;
        for (vector<int> &flower : flowers) {
            starts.push(flower[0]);
            ends.push(flower[1]);
        }
        vector<int> res(people.size());
        vector<pair<int, int>> per;
        per.reserve(people.size());
        for (int i = 0; i < people.size(); i++) {
            per.push_back({people[i], i});
        }
        sort(per.begin(), per.end());
        int cur = 0;
        for (pair<int, int> &p : per) {
            while (!starts.empty() && starts.top() <= p.first) {
                cur++;
                starts.pop();
            }
            while (!ends.empty() && ends.top() < p.first) {
                cur--;
                ends.pop();
            }
            res[p.second] = cur;
        }
        return res;
        // look at NeetCode Video, good explaination:https://www.youtube.com/watch?v=zY3Uty9IwvY

    }
};