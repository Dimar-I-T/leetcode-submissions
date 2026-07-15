class Solution {
public:
    // dimar's solution
    int removeElement(vector<int>& nums, int val) {
        // cari val pertama
        int l = 0, n = nums.size(), k = 0;
        for (int x = 0; x < n; x++){
            if (nums[x] == val){
                k++;
                break;
            }

            l++;
        }

        int idx = l;
        for (int x = l + 1; x < n; x++){
            if (nums[x] != val){
                nums[idx] = nums[x];
                idx++;
            }else{
                k++;
            }
        }

        for (int x = 0; x < n; x++){
            cout << nums[x] << " ";
        }

        return n - k;
    }
};