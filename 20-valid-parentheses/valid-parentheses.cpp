#include <vector>
class Solution {
public:
    bool isValid(string s) {
        std::vector <char> open_paren;
        for (int i = 0; i < s.length(); i++) {
            switch(s[i]) {
                case '(':
                    open_paren.push_back('c');
                    break;
                case ')':
                    if ( open_paren.empty() || open_paren.back() != 'c') {
                        return false;
                    }
                    else {
                        open_paren.pop_back();
                    }
                    break;
                case '[':
                    open_paren.push_back('s');
                    break;
                case ']':
                    if( open_paren.empty() || open_paren.back() != 's') {
                        return false;
                    }
                    else {
                        open_paren.pop_back();
                    }
                    break;
                case '{':
                    open_paren.push_back('b');
                    break;
                case '}':
                    if (open_paren.empty() || open_paren.back() != 'b') {
                        return false;
                    }
                    else {
                        open_paren.pop_back();
                    }
                    break;
                default:
                    break;
            }
        }
        return open_paren.empty();

        
    }
};