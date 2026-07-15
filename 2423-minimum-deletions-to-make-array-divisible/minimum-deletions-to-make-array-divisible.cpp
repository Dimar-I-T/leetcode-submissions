class Solution {
public:
    int FPB(vector<int> a){
        // Dimar's Algorithm
        int mulai = 0;
        int minn = 0;
        int maks = 0;
        int indeks = 0;
        for (int x = 0; x < a.size(); x++){
            if (a[x] != 0){
                minn = a[x];
                maks = a[x];
                indeks = x;
                mulai = x;
                break;
            }
        }

        for (int x = mulai + 1; x < a.size(); x++){
            if (minn > a[x] && a[x] != 0){
                minn = a[x];
                indeks = x;
            }
            if (maks < a[x]){
                maks = a[x];
            }
        }

        if (minn == 1){
            return 1;
        }else{
            if (minn == maks){
                return minn;
            }else{
                for (int x = 0; x < a.size(); x++){
                    if (x != indeks){
                        a[x] %= minn;
                    }
                }
                return FPB(a);
            }
        }
    }

    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int fpb = FPB(numsDivide);
        sort(nums.begin(), nums.end());
        int hasil = 0;
        bool bisa = false;
        for (int x = 0; x < nums.size(); x++){
            if (fpb % nums[x] == 0){
                bisa = true;
                break;
            }

            hasil++;
        }
        
        if (!bisa){
            hasil = -1;
        }
        
        return hasil;
    }
};