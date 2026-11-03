class Solution {
public:
    string customSortString(string order, string s) {
        int no = s.length();
        int ns = s.length();

        unordered_map<char, pair<int, bool>> freq;
        for (char c : s) {
            freq[c].first++;
        }

        string res = "";

        for (char c : order) {
            while (freq[c].first > 0) {
                res += c;
                freq[c].first--;
                freq[c].second = 1;
            }
        }

        for (char c : s) {
            if (!freq[c].second) {
                res += c;
            }
        }

        return res;
    }
};