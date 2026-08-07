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
            //cout << "l: " << l << "\n";
            //cout << "prevC: " << s[l] << "\n";
            char c = s[r];
            //cout << "c: " << c << "\n";
            // kasus edge
            auto itr = um.find(c);
            bool isDuplicate = 0;
            if (itr != um.end()) {
                int p = itr->second;
                if (l == 0 && p == -1) {
                    //cout << "ADA DUPLIKAT DI P: " << p << "\n\n";
                    um[s[l]] = 0;
                    l++;
                }

                // ada duplikat
                if (p > 0) {
                    //cout << "ADA DUPLIKAT DI P: " << p << "\n";
                    while (l <= p) {
                        um[s[l]] = 0;
                        //cout << "CLEAR " << s[l] << "\n";
                        l++;
                    }
                    
                    //cout <<"\n";
                }
            }
            
            //cout << "MASUKKAN: " << r - l + 1 << "\n\n";
            res = max(res, r - l + 1);

            //cout << "AMAN";
            //cout << "\n\n";
            um[c] = r;
        }

        return res;
    }
};