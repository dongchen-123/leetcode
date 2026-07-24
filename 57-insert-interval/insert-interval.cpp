class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) return {newInterval};
        std::vector<vector<int>> sorted_v = intervals;
        sorted_v.push_back(newInterval);
        std::sort(sorted_v.begin(), sorted_v.end());
        std::vector<vector<int>> out = {};
        for (const auto& i : sorted_v) {
            if (out.empty()) out.push_back(i);
            else {
                if (i[0] <= out.back()[1]) {
                    if (i[1] >= out.back()[1]) out.back()[1] = i[1];
                }
                else if (i[0] > out.back()[1]) out.push_back(i);
            }
        }
        return out;
    }
};