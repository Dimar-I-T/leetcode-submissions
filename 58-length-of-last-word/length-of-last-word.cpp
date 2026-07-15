class Solution {
public:
    // dimar's solution
    void trimLast(string &s) {
        int n = s.length();
        int banyakSpasiAkhir = 0;
        for (int x = n - 1; x >= 0; x--) {
            if (s[x] != ' '){
                break;
            }

            banyakSpasiAkhir++;
        }

        s = s.substr(0, n - banyakSpasiAkhir);
    }

    int lengthOfLastWord(string s) {
        trimLast(s);
        int hasil = 0;
        int n = s.length();
        for (int x = 0; x < n; x++) {
            if (s[x] == ' ') {
                hasil = 0;
            }else {
                hasil++;
            }
        }

        return hasil;
    }
};