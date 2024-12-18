class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();
        int i = 0;
        int start = newInterval[0];
        int end = newInterval[1];

        while (i < n && intervals[i][1] < start) {
            result.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= end) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        result.push_back({start, end});

        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
