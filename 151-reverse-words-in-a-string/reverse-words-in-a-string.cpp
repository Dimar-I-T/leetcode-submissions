class Solution {
public:
    // dimar's solution
    string reverseWords(string s) {
        vector<string> kata;
        kata.push_back("");
        string hasil = "";
        int k = 0, a = 0;
        for (int x = 0; x < s.length(); x++){
            if (s[x] == ' '){
                kata.push_back("");
                a++;
            }else{
                kata[a] += s[x];
            }
        }

        for (int x = kata.size() - 1; x >= 0; x--){
            if (kata[x].length() > 0){
                hasil += kata[x];
                hasil += " ";
            }
        }

        return hasil.substr(0, hasil.length() - 1);
    }
};