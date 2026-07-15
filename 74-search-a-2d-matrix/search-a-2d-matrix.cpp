class Solution {
public:
    // dimar's solution
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int lB = 0, rB = n - 1;
        bool adaB = false, hasil = false;
        // cek setiap ujung baris
        while (lB < rB){
            int tengah = (lB + rB)/2;
            if (target <= matrix[tengah][m - 1] && target >= matrix[tengah][0]){
                cout << tengah;
                lB = tengah;
                rB = tengah;
                adaB = true;
                break;
            }else{
                if (target < matrix[tengah][m - 1]){
                    rB = tengah - 1;
                }else{
                    lB = tengah + 1;
                }
            }
        }

        // cek di baris l
            int l = 0, r = m - 1;
            while (l < r){
                int tengah = (l + r)/2;
                if (target == matrix[lB][tengah]){
                    hasil = true;
                    break;
                }else{
                    if (target < matrix[lB][tengah]){
                        r = tengah - 1;
                    }else{
                        l = tengah + 1;
                    }
                }
            }

            if (target == matrix[lB][l]){
                hasil = true;
            }

        return hasil;
    }
};