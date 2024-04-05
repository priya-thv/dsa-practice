#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int r = 0;
        unordered_map<char, int> mp;
        int cnt = 0;
        int sindex = -1;
        int minlen = INT_MAX;
        
        // Initialize frequency map for characters in string t
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
        }
        
        while (r < s.length()) {
            char ch = s[r];
            if (mp.find(ch) != mp.end() && mp[ch] > 0) {
                cnt++;
            }
            mp[ch]--;  // Decrement count for the current character
            
            while (cnt == t.size()) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sindex = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return sindex == -1 ? "" : s.substr(sindex, minlen);
    }
};
