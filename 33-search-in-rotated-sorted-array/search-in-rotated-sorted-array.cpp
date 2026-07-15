class Solution {
public:
    // dimar's solution
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, hasil = -1;
        while (l <= r){
            int m = (l + r)/2;
            if (target == nums[r]){
                hasil = r;
                break;
            }

            if (l == m){
                if (target == nums[m]){
                    hasil = m;
                }

                break;
            }

            cout << m << " ";
            if (target < nums[l]){
                if (target == nums[m]){
                    hasil = m;
                    break;
                }else{
                    if (nums[m] < nums[l]){
                        if (target > nums[m]){
                            l = m;
                        }else{
                            r = m;
                        }
                    }else{
                        if (target < nums[m]){
                            l = m;
                        }else{
                            r = m;
                        }
                    }
                }
            }else{
                if (target == nums[m]){
                    hasil = m;
                    break;
                }else{
                    if (nums[m] < nums[l]){
                        if (target > nums[m]){
                            r = m;
                        }else{
                            l = m;
                        }
                    }else{
                        if (target > nums[m]){
                            l = m;
                        }else{
                            r = m;
                        }
                    }
                }
            }
        }

        return hasil;
    }
};