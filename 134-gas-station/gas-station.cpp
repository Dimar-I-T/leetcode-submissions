class Solution {
public:
    // dimar's solution
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), idxAwal = 0, hasil = 0, berurut = 0;
        vector<int> sel(2*n);
        for (int x = 0; x < 2*n; x++){
            sel[x] = gas[x % n] - cost[x % n];
            //cout << sel[x] << " ";
        }

        if (n == 1 && sel[0] >= 0){
            return 0;
        }

        bool kurang = 1;
        //cout << "\n";
        if (sel[0] > 0){
            idxAwal = 0;
            hasil = sel[0];
            berurut = 1;
            kurang = 0;
        }

        bool bisa = 0;
        //cout << hasil << " ";
        for (int x = 1; x < 2*n; x++){
            if (hasil + sel[x] >= 0){
                if (kurang){
                    idxAwal = x;
                    kurang = 0;
                }

                hasil += sel[x];
                berurut++;
            }else{
                hasil = 0;
                berurut = 0;
                kurang = 1;
            }

            if (berurut >= n){
                bisa = 1;
                break;
            }
        }

        if (berurut >= n){
            bisa = 1;
        }

        if (bisa){
            hasil = idxAwal;
        }else{
            hasil = -1;
        }

        return hasil;
    }
};