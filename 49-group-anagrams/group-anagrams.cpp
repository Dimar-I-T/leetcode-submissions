class Solution {
public:
    // dimar's solution
    string sortedString(string s) {
        vector<char> c;
        for (auto x : s) {
            c.push_back(x);
        }

        sort(c.begin(), c.end());
        string baru = "";
        for (char cc : c) {
            baru += cc;
        }

        return baru;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sorted;
        int n = strs.size();
        for (string s : strs) {
            string sortedS = sortedString(s);
            sorted.push_back(sortedS);
        }

        unordered_map<string, vector<string>> grup;
        for (int x = 0; x < n; x++) {
            grup[sorted[x]].push_back(strs[x]);
        }

        vector<vector<string>> hasil;
        for (auto i : grup) {
            hasil.push_back(i.second);
        }

        return hasil;
    }
};