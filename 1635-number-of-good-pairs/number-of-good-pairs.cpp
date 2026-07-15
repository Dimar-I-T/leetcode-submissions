class Solution {
public:
    // dimar's solution
    int Kom(int n){
        return (n*n - n)/2;
    }

    int numIdenticalPairs(vector<int>& num) {
        map<int, int> banyak;
        map<int, bool> sudah;
        int hasil = 0;
        for (int x = 0; x < num.size(); x++){
            banyak[num[x]]++;
        }

        for (int x = 0; x < num.size(); x++){
            if (!sudah[num[x]]){
                hasil += Kom(banyak[num[x]]);
                sudah[num[x]] = true;
            }
        }

        return hasil;
    }
};