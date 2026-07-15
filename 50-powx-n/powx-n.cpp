class Solution {
public:
    // dimar's solution
    double myPow(double x, int n) {
        double hasil = 1;
        double pengali = x;
        long long pangkat;
        if (n < 0) {
            pangkat = (long long) (n);
        }else {
            pangkat = n;
        }

        if (pangkat < 0) {
            pangkat = -pangkat;
        }

        while (pangkat > 0) {
            if (pangkat % 2 == 1) {
                hasil *= pengali;
            }

            pengali *= pengali;
            pangkat /= 2;
        }

        if (n < 0) {
            hasil = 1 / hasil;
        }

        return hasil;
    }
};