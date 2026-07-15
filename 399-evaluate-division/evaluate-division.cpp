class Solution {
public:
    // dimar's solution
    map<string, vector<string>> tetangga;
    map<pair<string, string>, double> Nil;

    double BFS(string dari, string ke){
        double hasil = -1;
        map<string, bool> pernah;
        map<string, double> Kali;
        bool ada = false;
        queue<string> q;
        q.push(dari);
        Kali[dari] = 1.0;
        pernah[dari] = true;
        while (!q.empty() && !ada){
            string di = q.front();
            for (int x = 0; x < tetangga[di].size(); x++){
                string ke1 = tetangga[di][x];
                if (!pernah[ke1]){
                    pernah[ke1] = true;
                    Kali[ke1] = Kali[di]*Nil[{di, ke1}];
                    q.push(ke1);
                }

                if (ke1 == ke){
                    ada = true;
                    break;
                }
            }

            q.pop();
        } 

        if (ada){
            hasil = Kali[ke];
        }

        return hasil;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size(), qu = queries.size();
        vector<double> Hasil(qu);
        for (int x = 0; x < n; x++){
            string kiri = equations[x][0], kanan = equations[x][1];
            double nilai = values[x];
            tetangga[kiri].push_back(kanan);
            Nil[{kiri, kanan}] = (double)nilai;
            tetangga[kanan].push_back(kiri);
            Nil[{kanan, kiri}] = (double)1/nilai;
        }

        for (int x = 0; x < qu; x++){
            Hasil[x] = BFS(queries[x][0], queries[x][1]);
        }

        return Hasil;
    }
};