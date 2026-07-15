class Solution {
public:
    // dimar's solution
    int Hitung(int n, int mB){
        if (n < 7){
            return ((n)*(n + 1))/2 + n*mB;
        }else{
            return Hitung(n - 7, mB + 1) + 28 + 7*mB;
        }
    }
    
    int totalMoney(int n) {
        return Hitung(n, 0);
    }
};