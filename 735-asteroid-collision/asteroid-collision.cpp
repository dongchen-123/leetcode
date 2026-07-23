#include <algorithm>
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::vector<int> out;
        for (const auto& a : asteroids) {
            if (out.empty()) out.push_back(a);
            else {
                if ((out.back() > 0 && a > 0 ) || (out.back() < 0 && a < 0)) {
                    out.push_back(a);
                }
                else {
                    if (out.back() < 0 && a > 0) out.push_back(a);
                    else {
                        while (!out.empty() && out.back() > 0 && abs(a) > out.back()) {
                            out.pop_back();
                        }
                        if (!out.empty() && out.back() == -a) out.pop_back();
                        else if (out.empty() || out.back() < 0) out.push_back(a);
                    }
                }
            }
        }
        return out;
    }
};