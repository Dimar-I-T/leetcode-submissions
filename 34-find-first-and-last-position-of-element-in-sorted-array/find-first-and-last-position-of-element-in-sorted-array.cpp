class Solution {
public:
    // dimar's solution
    vector<int> searchRange(vector<int>& nums, int target) {
        int kiri = -1, kanan = -1;
        vector<int> hasil;

        if (nums.empty()){
            hasil = {kiri, kanan};
        }else{
            // cari kiri
            if (nums[0] != target){
                int l = 0, r = nums.size() - 1, ngulang = 0, tm = 0;
                while (l <= r){
                    int m = (l + r)/2;
                    if (tm == m){
                        ngulang++;
                    }

                    tm = m;
                    cout << m << " ";
                    if (ngulang == 2){
                        break;
                    }

                    if (nums[m] == target){
                        if (nums[m - 1] != target){
                            kiri = m;
                            break;
                        }
                        else{
                            r = m;
                        }
                    }else{
                        if (nums[m] < target){
                            l = m;
                        }else{
                            r = m;
                        }
                    }
                }   
            }else{
                kiri = 0;
            }

            // cari kanan
            if (nums[nums.size() - 1] != target){
                int l = 0, r = nums.size() - 1, ngulang = 0, tm = 0;
                while (l <= r){
                    int m = (l + r)/2;
                    if (tm == m){
                        ngulang++;
                    }

                    tm = m;
                    if (ngulang == 2){
                        break;
                    }

                    if (nums[m] == target){
                        if (nums[m + 1] != target){
                            kanan = m;
                            break;
                        }else{
                            l = m;
                        }
                    }else{
                        if (nums[m] < target){
                            l = m;
                        }else{
                            r = m;
                        }
                    }
                }
            }else{
                kanan = nums.size() - 1;
            }

            if ((kanan > 0 && kiri == -1) || (kiri > 0 && kanan == -1)){
                kiri = kanan;
            }

            hasil = {kiri, kanan};
        }
        
        return hasil;
    }
};