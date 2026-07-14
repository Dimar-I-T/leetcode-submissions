class Solution {
public:
    // dimar's solution
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        bool selesai = false;
        bool kosong = false;
        string hasil = "";
        while (!selesai) {
            bool sama = true;
            if (i >= strs[0].length()) {
                break;
            }

            char c = strs[0][i];
            for (string s : strs) {
                int ns = s.length();
                if (i >= ns) {
                    selesai = 1;
                    sama = false;
                    break;
                }

                if (s[i] != c) {
                    sama = false;
                    break;
                }
            }

            if (sama) {
                hasil += c;
                i++;
            } else {
                selesai = 1;
            }
        }

        return hasil;
    }
};