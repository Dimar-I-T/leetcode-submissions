class Solution {
public:
    // dimar's solution
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1, h = 0;
        bool ada = false;
        while (l < r){
            int m = (l + r)/2;
            if (nums[m] == target){
                h = m;
                ada = true;
                break;
            }else{
                if (nums[m] > target){
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }
        }

        if (!ada){
            if (nums[l] >= target){
                h = l;
            }else{
                h = l + 1;
            }
        }

        return h;
    }
};