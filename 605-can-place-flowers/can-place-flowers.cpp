class Solution {
public:
    // dimar's solution
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();
        if (l > 1){
            // cek ujung kiri
            if (flowerbed[0] == 0 && flowerbed[1] == 0 && n > 0){
                flowerbed[0] = 1;
                n--;
            }

            // cek ujung kanan
            if (flowerbed[l - 2] == 0 && flowerbed[l - 1] == 0 && n > 0){
                flowerbed[l - 1] = 1;
                n--;
            }

            // cek tengah
            for (int x = 1; x < l - 1; x++){
                if (n > 0){
                    if (flowerbed[x - 1] != 1 && flowerbed[x + 1] != 1 && flowerbed[x] == 0){
                        flowerbed[x] = 1;
                        n--;
                    }
                }else{
                    break;
                }
            }

            return (n == 0);
        }else{
            if (n == 0){
                return true;
            }else{
                if (flowerbed[0] == 0){
                    n--;
                }

                return (n == 0);
            }
        }
    }
};