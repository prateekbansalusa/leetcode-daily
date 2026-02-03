#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Dictionary to store the last position of each character
        // Using vector<int> size 256 for ASCII
        vector<int> dict(256, -1);
        int maxLen = 0;
        int start = -1; // Position just before the start of the current window

        for (int i = 0; i < s.length(); i++) {
            // If the character was seen after 'start', move 'start'
            if (dict[s[i]] > start) {
                start = dict[s[i]];
            }
            
            // Update the last seen position of the character
            dict[s[i]] = i;
            
            // Calculate current window length: i - start
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

int main() {
    Solution solution;
    
    vector<string> testCases = {
        "abcabcbb",
        "bbbbb",
        "pwwkew",
        "",
        " "
    };

    for (const string& s : testCases) {
        cout << "Input: \"" << s << "\"" << endl;
        cout << "Output: " << solution.lengthOfLongestSubstring(s) << endl;
        cout << "-----------------" << endl;
    }

    return 0;
}
