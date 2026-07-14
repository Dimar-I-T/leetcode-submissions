class Solution {
public:
    // dimar's solution
    int reverse(int x) {
        long long maks = INT_MAX, minn = INT_MIN;
        string awal = to_string(abs((long long)x));
        long long hasil = 0;
        string rev = "";
        for (int i = awal.length() - 1; i >= 0; i--){
            rev += awal[i];
        }

        hasil = stoll(rev);
        if (to_string(x)[0] == '-'){
            hasil *= -1;
        }
        
        if (hasil > maks || hasil < minn){
            hasil = 0;
        }

        return hasil;
    }
};