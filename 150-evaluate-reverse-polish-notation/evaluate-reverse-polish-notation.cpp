#include <stack>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> nums;
        for (const auto& t : tokens) {
            if (isdigit(t[0]) || t[0] == '-' && isdigit(t[1])) nums.push(stoi(t));
            else {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                int result;
                if (t == "+") result = num1 + num2;
                else if (t == "-") result = num2 - num1;
                else if (t == "*") result = num1 * num2;
                else if (t == "/") result = num2 / num1;
                nums.push(result);
            }
        }
        return nums.top();    
    }
};