class Solution {
public:
    // dimar's solution
    int longestOnes(vector<int>& nums, int k) {
        vector<int> letakNol;
        int n = nums.size(), banyakNol = 0;
        for (int x = 0; x < n; x++){
            if (nums[x] == 0){
                letakNol.push_back(x);
                banyakNol++;
            }
        }

        vector<int> kum(n);
        int mulai = 0, l = 0, hasil = 0, hasil1 = 0;
        for (int x = 1; x < n; x++){
            if (nums[x - 1] == 1 && nums[x] == 1){
                kum[x] = kum[x - 1] + 1;
            }

            hasil1 = max(hasil1, kum[x]);
        }

        for (int x = 0; x < n; x++){
            cout << kum[x] << " ";
        }
        
        if (k > 0){
            if (k > banyakNol){
                return n;
            }

            while (mulai < n){
                if (l == k){
                    break;
                }

                if (nums[mulai] == 0){
                    l++;
                }
                hasil++;
                mulai++;
            }
            
            vector<int> H(n);
            H[mulai - 1] = hasil;
            int a = 0;
            for (int x = mulai; x < n; x++){
                if (nums[x] == 0){
                    H[x] = x - letakNol[a];
                    a++;
                }else{
                    H[x] = H[x - 1] + 1;
                }

                hasil = max(hasil, H[x]);
            }

            return hasil;
        }else{
            if (banyakNol == n){
                return 0;
            }
            
            return hasil1 + 1;
        }
         
    }
};