class Solution {
public:
    // dimar's solution
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0"){
            return "0";
        }

        string s1 = num1, s2 = num2;
        if (s1.length() < s2.length()){
            s1 = num2;
            s2 = num1;
        }

        int n1 = s1.length(), n2 = s2.length();
        vector<vector<char>> c(n2);
        int a = 0, k = 0;
        for (int x = n2 - 1; x >= 0; x--){
            int bawah = s2[x] - '0';
            int kanan = 0;
            int co = 0;
            vector<char> c1(n1 + n2, '0');
            for (int y = n1 + n2 - a - 1; y >= 0; y--){
                if (co == n1 + 1 || y + a - n2 < 0){
                    break;
                }
                
                int atas = s1[y + a - n2] - '0';
                int kali = atas * bawah + kanan;
                string kaliS = to_string(kali);
                int ka = kaliS.length();

                if (ka == 2){
                    kanan = kaliS[0] - '0';
                    if (co == n1 - 1){
                        c1[y - 1] = kaliS[0];
                    }

                    c1[y] = kaliS[1];
                }else{
                    kanan = 0;
                    c1[y] = kaliS[0];
                }

                co++;
            }

            c[k] = c1;
            k++;
            a++;
        }

        string hasil = "";
        for (int x = n1 + n2 - 1; x >= 0; x--){
            int jumlah = 0;
            for (int y = 0; y < n2; y++){
                jumlah += c[y][x] - '0';
            }

            string jumlahS = to_string(jumlah);
            int js = jumlahS.length();
            hasil += jumlahS[js - 1];
            int i = x - 1;
            if (i < 0){
                continue;
            }

            for (int y = js - 2; y >= 0; y--){
                int s = c[0][i] - '0';
                s += jumlahS[y] - '0';
                c[0][i] = s + '0';
                i--;
            }
        }

        string hasilAkhir = "";
        for (int x = hasil.length() - 1; x >= 0; x--){
            if (x == hasil.length() - 1 && hasil[x] == '0'){
                continue;
            }

            hasilAkhir += hasil[x];
        }

        return hasilAkhir;
    }
};