#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;

        int maxLen = 1, start = 0;

        for (int i = 1; i < n; ++i) {
            // Check for odd-length palindrome centered at i
            int l = i - 1;
            int r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                --l;
                ++r;
            }

            // Check for even-length palindrome centered between i-1 and i
            l = i - 1;
            r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                --l;
                ++r;
            }
        }
        
        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;
    string s = "babad";
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s) << endl;
    return 0;
}
