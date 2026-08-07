class Solution {
public:
// dimar's solution
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0;
        int res = (n == 0) ? 0 : 1;
        // char -> position
        unordered_map<char, int> um;
        um.reserve(n);
        um[s[l]] = -1;
        for (int r = 1; r < n; r++) {
            char c = s[r];
            // kasus edge
            auto itr = um.find(c);
            bool isDuplicate = 0;
            if (itr != um.end()) {
                int p = itr->second;
                if (l == 0 && p == -1) {
                    um[s[l]] = 0;
                    l++;
                }

                // ada duplikat
                if (p > 0) {
                    while (l <= p) {
                        um[s[l]] = 0;
                        l++;
                    }
                }
            }
            
            res = max(res, r - l + 1);
            um[c] = r;
        }

        return res;
    }
};