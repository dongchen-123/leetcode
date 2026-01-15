#include <string>
class Solution {
public:
    bool isPalindrome(int x) {
        std::string y = std::to_string(x);
        int i = 0;
        while (y[i] == y[y.length() - 1 - i]) {
            if(i == y.length() / 2) {
                return true;
            }
            i += 1;
        }
        return false;
    }
};