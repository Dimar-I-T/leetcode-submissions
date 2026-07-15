class Solution {
public:
    // dimar's solution
    string reverseVowels(string s) {
        string vokal = "aeiouAEIOU";
        map<char, bool> vok;
        for (int x = 0; x < 10; x++){
            vok[vokal[x]] = true;
        }

        vector<int> idxVok;
        for (int x = 0; x < s.length(); x++){
            if (vok[s[x]]){
                idxVok.push_back(x);
            }
        }

        int k = idxVok.size() - 1, batas = idxVok.size()/2;
        for (int x = 0; x < s.length(); x++){
            if (vok[s[x]] && batas > 0){
                char temp = s[idxVok[k]];
                s[idxVok[k]] = s[x];
                s[x] = temp;
                k--;
                batas--;
            }else if (batas == 0){
                break;
            }
        }

        return s;
    }
};