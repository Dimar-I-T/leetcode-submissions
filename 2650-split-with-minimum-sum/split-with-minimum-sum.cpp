class Solution {
public:
    // dimar's solution
    int splitNum(int num) {
        vector<int> pisah;
        int p = to_string(num).length();
        string P = to_string(num);
        for (int x = 0; x < p; x++){
            pisah.push_back(P[x] - '0');
        }

        sort(pisah.begin(), pisah.end());
        vector<int> kiri;
        vector<int> kanan;
        for (int x = 0; x < p; x++){
            if (x % 2 == 0){
                kiri.push_back(pisah[x]);
            }else{
                kanan.push_back(pisah[x]);
            }
        }

        string kiriS = "", kananS = "";
        for (int x = 0; x < kiri.size(); x++){
            kiriS += to_string(kiri[x]);
        }

        for (int x = 0; x < kanan.size(); x++){
            kananS += to_string(kanan[x]);
        }

        int kiriN = stoi(kiriS), kananN = stoi(kananS);
        return kiriN + kananN;
    }
};