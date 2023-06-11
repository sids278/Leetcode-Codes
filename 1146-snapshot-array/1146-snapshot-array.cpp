class SnapshotArray {
    vector<vector<pair<int, int>>> history; // pair<snap_id, val>
    int curSnap;
public:
    SnapshotArray(const int& length) { // O(length)
        history.resize(length, {{-1, 0}});
        curSnap = 0;
    }
    
    void set(const int& index, const int& val) { // amortized O(1)
        if (history[index].back().first < curSnap)
            history[index].push_back({curSnap, val});
        else
            history[index].back().second = val;
    }
    
    int snap() { // O(1)
        return curSnap++;
    }
    
    int get(const int& index, const int& snap_id) { // O(log curSnap)
        return (upper_bound(history[index].begin(), history[index].end(), make_pair(snap_id, INT_MAX)) - 1)->second;
    }
};