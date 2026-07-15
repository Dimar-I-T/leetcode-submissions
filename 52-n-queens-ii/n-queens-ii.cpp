class Solution {
public:
    // dimar's solution
    void solve(vector<vector<pair<int, int>>> &hasilKoordinat, vector<pair<int, int>> xy, vector<bool> titikMakanNaik, vector<bool> titikMakanTurun, vector<bool> titikX, vector<bool> titikY,
               int x1, int xBaru, int yBaru, int n) {
        if (xBaru >= 0 && yBaru >= 0) {
            xy.push_back({xBaru, yBaru});
        }

        if (xy.size() == n) {
            hasilKoordinat.push_back(xy);
            return;
        }

        for (auto i : xy) {
            int naik = i.first + i.second;
            int turun = i.second - i.first;
            titikX[i.first] = 1;
            titikY[i.second] = 1;
            titikMakanNaik[naik + n] = 1;
            titikMakanTurun[turun + n] = 1;
        }

        bool bisa = 0;
        for (int x = x1; x < n; x++) {
            for (int y = 0; y < n; y++) {
                int naik = x + y + n;
                int turun = y - x + n;
                bool kenaX = titikX[x];
                bool kenaY = titikY[y];
                bool kenaNaik = titikMakanNaik[naik];
                bool kenaTurun = titikMakanTurun[turun];
                if (!(kenaX || kenaY || kenaNaik || kenaTurun)) {
                    bisa = 1;
                    solve(hasilKoordinat, xy, titikMakanNaik, titikMakanTurun, titikX, titikY, x + 1, x, y, n);
                }
            }

            if (!bisa) {
                return;
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<pair<int, int>>> hasilKoordinat;
        int hasil = 1;
        vector<pair<int, int>> xy;
        int isi = 4*n + 1;
        vector<bool> titikMakanNaik(isi);
        vector<bool> titikMakanTurun(isi);
        vector<bool> titikX(isi);
        vector<bool> titikY(isi);
        solve(hasilKoordinat, xy, titikMakanNaik, titikMakanTurun, titikX, titikY, 0, -1, -1, n);
        if (n == 1) {
            hasil = 1;
        }else {
            hasil = hasilKoordinat.size();
        }

        return hasil;
    }
};