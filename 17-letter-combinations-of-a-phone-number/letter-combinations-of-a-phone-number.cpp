class Solution {
public:
    // dimar's solution
    vector<string> kali(string s1, string s2) {
        vector<string> hasil;
        int n2 = s2.length();
        for (int y = 0; y < n2; y++) {
            char c2 = s2[y];
            string str2(1, c2);
            string gabung = s1 + str2;
            hasil.push_back(gabung);
        }   

        return hasil;
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> letters;
        letters['1'] = "";
        letters['2'] = "abc";
        letters['3'] = "def";
        letters['4'] = "ghi";
        letters['5'] = "jkl";
        letters['6'] = "mno";
        letters['7'] = "pqrs";
        letters['8'] = "tuv";
        letters['9'] = "wxyz";

        queue<vector<string>> hasil;
        vector<string> pertama;
        string pert = letters[digits[0]];
        for (char cs : pert) {
            string ss(1, cs);
            pertama.push_back(ss);
        }

        hasil.push(pertama);
        int n = digits.length();
        for (int x = 1; x < n; x++) {
            vector<string> sek = hasil.front();
            vector<string> sel;
            for (string s : sek) {
                vector<string> h = kali(s, letters[digits[x]]);
                sel.insert(sel.end(), h.begin(), h.end());
            }
            
            hasil.push(sel);
            hasil.pop();
        }

        return hasil.front();
    }
};