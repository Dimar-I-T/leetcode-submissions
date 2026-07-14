class Solution {
public:
    // dimar's solution
    int myAtoi(string s) {
        bool minus = false, adaNol = false;
        int i = 0;
        char dig[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        bool lanjut = true;
        for (int x = 0; x < s.length(); x++){
            if (s[x] != '0' && s[x] != ' '){
                break;
            }

            if (s[x] == '0'){
                adaNol = true;
            }

            if (adaNol && s[x] == ' '){
                lanjut = false;
                break;
            }
            i++;
        }

        if (s[i] == '-' || s[i] == '+'){
            if (adaNol){
                lanjut = false;
            }

            if (s[i] == '-'){
                minus = true;
            }

            i++;
        }

        map<char, bool> digit;
        for (int x = 0; x < 10; x++){
            digit[dig[x]] = true; 
        }

        string hasil = "";
        int a = 0;
        bool selainNol = false;
        if (lanjut){
            for (int x = i; x < s.length(); x++){
                if ((!digit[s[x]]) || a == 12){
                    break;
                }

                if (s[x] != '0'){
                    selainNol = true;
                }

                if (!selainNol){
                    if (s[x] == '0'){
                        continue;
                    }
                }

                a++;
                hasil += s[x];
            }
        }

        //cout << hasil;
        long long hasilL = 0;
        if (hasil != ""){
            hasilL = stoll(hasil);
        }

        if (minus){
            hasilL *= -1;
        }

        if (hasilL > INT_MAX){
            hasilL = INT_MAX;
        }

        if (hasilL < INT_MIN){
            hasilL = INT_MIN;
        }

        return hasilL;
    }
};