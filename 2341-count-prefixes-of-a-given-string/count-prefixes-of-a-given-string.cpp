class Solution {
public:
    // dimar's solution
    int countPrefixes(vector<string>& words, string s) {
        int n = words.size();
        int hasil = 0;
        for (int x = 0; x < n; x++){
            int len = words[x].length();
            if (words[x] == s.substr(0, len)){
                hasil++;
            }
        }

        return hasil;
    }
};