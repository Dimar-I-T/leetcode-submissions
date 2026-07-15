class Solution {
public:
    // dimar's solution
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int x = 0; x < n; x++){
            while (nums[x] != x + 1 && (nums[x] > 0 && nums[x] <= n)){
                int temp = nums[x];
                if (temp == nums[temp - 1]){
                    break;
                }

                nums[x] = nums[temp - 1];
                nums[temp - 1] = temp;
            }
        }

        int hasil = 0;
        for (int x = 0; x < n; x++){
            if (nums[x] != x + 1){
                hasil = x + 1;
                break;
            }
        }

        hasil = (hasil == 0) ? nums[n - 1] + 1 : hasil;

        return hasil;
    }
};