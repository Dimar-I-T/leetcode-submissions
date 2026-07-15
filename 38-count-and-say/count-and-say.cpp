class Solution {
public:
    // dimar's solution
    string buat(string s, int banyak){
        int n = s.length();
        vector<pair<char, int>> banyakKar(n);
        banyakKar[0] = {s[0], 1};
        for (int x = 1; x < n; x++){
            if (s[x] == s[x - 1]){
                banyakKar[x] = {s[x], banyakKar[x - 1].second + 1};
                banyakKar[x - 1].second = -1;
            }else{
                banyakKar[x] = {s[x], 1};
            }
        }

        string baru = "";
        for (int x = 0; x < n; x++){
            if (banyakKar[x].second != -1){
                string tambah = to_string(banyakKar[x].second) + banyakKar[x].first;
                baru += tambah;
            }
        }
        
        if (banyak == 1){
            return "1"; 
        }

        if (banyak == 2){
            return baru;
        }else{
            return buat(baru, banyak - 1);
        }
    }
    
    string countAndSay(int n) {
        return buat("1", n);
    }
};