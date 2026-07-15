class Solution {
public:
    // dimar's solution
    bool isThree(int n) {
        bool hasil = false, prima = true;
        int akar = sqrt(n);
        int akar1 = sqrt(akar);
        if (akar1 != 2){
            // cek prima
            for (int x = akar1; x >= 2; x--){
                if (akar % x == 0){
                    prima = false;
                    break;
                }
            }
        }

        if (akar*akar == n && prima && n != 1 && akar1*akar1 != akar){
            hasil = true;
        }

        return hasil;
    }
};