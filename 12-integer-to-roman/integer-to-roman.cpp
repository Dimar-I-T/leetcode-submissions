class Solution {
public:
    // dimar's solution
    // k untuk urutan dan a untuk nilai
    unordered_map<int, vector<string>> hurup;
    string Pasang(int k, int a){
        hurup[1] = {"I", "X", "C", "M"};
        hurup[5] = {"V", "L", "D"};
        string hasil = "";
        if (k == 4){
            for (int x = 0; x < a; x++){
                hasil += "M";
            }
        }else{
            //cout << a << "\n";
            // 1 -- 5
            if (a < 4){
                for (int x = 0; x < a; x++){
                    hasil += hurup[1][k - 1];
                }
            }else if (a == 4){
                hasil = hurup[1][k - 1] + hurup[5][k - 1];
            }
            // 5 -- 9
            else if (a > 4 && a < 9){
                hasil = hurup[5][k - 1];
                for (int x = 5; x < a; x++){
                    hasil += hurup[1][k - 1];
                }
            }
            else if (a == 9){
                hasil = hurup[1][k - 1] + hurup[1][k];
            }
        }

        //cout << hasil << "\n";
        return hasil;
    }
    string intToRoman(int num) {
        string s = to_string(num);
        string hasil = "";
        for (int x = s.length(); x > 0; x--){
            hasil += Pasang(x, s[s.length() - x] - '0');
        }

        return hasil;
    }
};