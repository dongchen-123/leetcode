#include <unordered_map>
#include <queue>
#include <functional>
#include <iostream>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        std::unordered_map<int, std::vector<std::vector<int>>> dist_map;
        for (const auto& p : points) {
            int dist = p[0]*p[0] + p[1]*p[1];
            minHeap.push(dist);
            dist_map[dist].push_back(p);
        }
        std::vector<std::vector<int>> out = {};
        for (int i = k; i > 0; i--){
            int min_dist = minHeap.top();
            minHeap.pop();
            std::vector<int> o = dist_map[min_dist].back();
            dist_map[min_dist].pop_back();
            out.push_back(o); 
        }
        return out;
    }
};