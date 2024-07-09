#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        vector<long long> candidates;

        // Edge case: one less digit and one more digit
        candidates.push_back(pow(10, len - 1) - 1);  // 999...999
        candidates.push_back(pow(10, len) + 1);      // 100...001

        // Get the prefix of the original number
        long long prefix = stoll(n.substr(0, (len + 1) / 2));

        // Generate palindromic candidates based on the prefix
        for (int i = -1; i <= 1; ++i) {
            string p = to_string(prefix + i);
            string palin = p + string(p.rbegin() + (len & 1), p.rend());
            candidates.push_back(stoll(palin));
        }

        long long num = stoll(n);
        long long closest = -1;
        for (long long cand : candidates) {
            if (cand != num) {
                if (closest == -1 ||
                    abs(cand - num) < abs(closest - num) ||
                    (abs(cand - num) == abs(closest - num) && cand < closest)) {
                    closest = cand;
                }
            }
        }

        return to_string(closest);
    }
};

int main() {
    Solution sol;
    string n = "80704505322479288";
    cout << "Nearest Palindromic: " << sol.nearestPalindromic(n) << endl;
    return 0;
}
