class Solution {
public:
    // dimar's solution
    int maxVowels(string s, int k) {
        map<char, bool> vokal;
        string vok = "aeiou";
        for (int x = 0; x < 5; x++){
            vokal[vok[x]] = true;
        }

        int hasil = 0, h = 0;
        for (int x = 0; x < k; x++){
            if (vokal[s[x]]){
                hasil++;
            }
        }

        int hasil1 = 0, hasil2 = hasil;
        for (int x = 0; x < s.length() - k; x++){
            hasil1 = max(hasil1, hasil);
            if (vokal[s[x]]){
                hasil--;
            }

            if (vokal[s[x + k]]){
                hasil++;
            }

            hasil1 = max(hasil1, hasil);
        }

        return max(hasil1, hasil2);
    }
};