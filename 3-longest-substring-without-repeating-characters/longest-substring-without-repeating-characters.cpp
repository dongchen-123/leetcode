#include <string>
#include <map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_l = 0;
        for (int i = 0; i < s.length(); i++) {
            int j = i;
            map <char, bool> c_map;
            while(j < s.length() && !c_map[s[j]]) {
                c_map[s[j]] = true;
                j++;
            }
            max_l = (j - i > max_l) ? j - i: max_l;
        }
        return max_l;
    }
};