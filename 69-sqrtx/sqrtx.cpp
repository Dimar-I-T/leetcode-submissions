class Solution {
public:
    // dimar's solution
    int mySqrt(int x) {
        int i = 1;
        unsigned long long sq = 4;
        unsigned long long k = 2;
        if (x == 0) {
            k = 1;
        } else {
            while (x >= sq) {
                k++;
                sq = k * k;   
            }
        }

        return k - 1;
    }
};