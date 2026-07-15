class Solution {
public:
    // dimar's solution
    bool bisa = true;

    void Cek(string s1, string s2){
        string besar = "", kecil = "";
        int batas = min(s1.length(), s2.length());
        if (s1.length() > s2.length()){
            besar = s1;
            kecil = s2;
        }else{
            besar = s2;
            kecil = s1;
        }

        if (batas > 0){
            for (int x = 0; x < batas; x++){
                if (s1[x] != s2[x]){
                    bisa = false;
                    return;
                }
            }

            Cek(kecil, besar.substr(batas, besar.length() - batas));
        }
    }

    string gcdOfStrings(string str1, string str2) {
        int batas = min(str1.length(), str2.length());

        Cek(str1, str2);
        if (bisa){
            int hasilL = gcd(str1.length(), str2.length());
            return str1.substr(0, hasilL);
        }else{
            return "";
        }
    }
};