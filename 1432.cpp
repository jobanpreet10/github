#include <string>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string max_s = s;
        string min_s = s;

        // Calculate maximum number
        char max_replace = 0;
        for (char c : s) {
            if (c != '9') {
                max_replace = c;
                break;
            }
        }
        if (max_replace) {
            for (int i = 0; i < max_s.size(); i++) {
                if (max_s[i] == max_replace) {
                    max_s[i] = '9';
                }
            }
        }

        // Calculate minimum number
        if (s[0] != '1') {  // First digit isn't 1
            char replace_char = s[0];
            for (int i = 0; i < min_s.size(); i++) {
                if (min_s[i] == replace_char) {
                    min_s[i] = '1';
                }
            }
        } else {  // First digit is 1
            char replace_char = 0;
            // Find first non-0/1 after first character
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    replace_char = s[i];
                    break;
                }
            }
            if (replace_char) {
                for (int i = 0; i < min_s.size(); i++) {
                    if (min_s[i] == replace_char) {
                        min_s[i] = '0';
                    }
                }
            }
        }

        return stoi(max_s) - stoi(min_s);
    }
};
