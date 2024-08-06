class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>mp;
        for(auto x:word){
            mp[x]++;
        }
        vector<pair<int, char>> counts;
        for (auto x : mp) {
            counts.emplace_back(x.second, x.first);
        }

        // Sort the vector by count in descending order
        sort(counts.begin(), counts.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
            return a.first > b.first;
        });

        
        vector<int> buttonPresses(8, 0);  // Simulating buttons from index 2 to 9
        int ans = 0;

        for (int i = 0; i < counts.size(); ++i) {
            int buttonIndex = (i % 8) + 2;  // Map to buttons 2 through 9
            int pressesRequired = counts[i].first * (buttonPresses[i % 8] + 1);
            ans += pressesRequired;
            buttonPresses[i % 8]++;
            cout << "char " << counts[i].second << " pressed " << pressesRequired << " times" << endl;
        }

        return ans;
    }
};