#include <stack>
#include <vector>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> temp_stack;
        std::vector<int> out;
        out.assign(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            if (temp_stack.size() == 0) temp_stack.push(i);
            else {
                while (!temp_stack.empty() && temperatures[i] > temperatures[temp_stack.top()]) {
                    out[temp_stack.top()] = i - temp_stack.top();
                    temp_stack.pop();
                }
                temp_stack.push(i);
            }
        }
        return out;
    }
};