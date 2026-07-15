class Solution {
public:
    // dimar's solution
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> belakang, hasil;
        int ganti = 0, idxAkhir = 0;
        bool bisa = false;
        for (int x = n - 1; x > 0; x--){
            if (nums[x - 1] < nums[x]){
                bisa = true;
                belakang.push_back(nums[x - 1]);
                belakang.push_back(nums[x]);
                ganti = nums[x - 1];
                idxAkhir = x - 2;
                break;
            }

            belakang.push_back(nums[x]);
        }

        sort(belakang.begin(), belakang.end());
        if (bisa){
            int pengganti = 0;
            for (int x = 0; x < belakang.size(); x++){
                if (belakang[x] > ganti){
                    pengganti = belakang[x];
                    belakang[x] = -1;
                    cout << pengganti;
                    break;
                }
            }

            for (int x = 0; x <= idxAkhir; x++){
                hasil.push_back(nums[x]);
            }

            hasil.push_back(pengganti);

            for (int x = 0; x < belakang.size(); x++){
                if (belakang[x] == -1){
                    continue;
                }

                hasil.push_back(belakang[x]);
            }

            for (int x = 0; x < n; x++){
                nums[x] = hasil[x];
            }
        }else{
            sort(nums.begin(), nums.end());
        }
    }
};