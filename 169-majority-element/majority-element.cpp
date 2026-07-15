class Solution {
public:
    // dimar's solution
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), hasil = 1, maks = 1;
        unordered_map<int, int> banyak;
        banyak[nums[0]]++;
        hasil = nums[0];
        for (int x = 1; x < n; x++){
            if (banyak[nums[x]] == 0){
                banyak[nums[x]]++;
            }

            if (nums[x] == nums[x - 1]){
                banyak[nums[x]]++;
            }

            maks = max(maks, banyak[nums[x]]);
        }
        
        for (int x = 0; x < n; x++){
            if (banyak[nums[x]] == maks){
                hasil = nums[x];
                break;
            }
        }

        return hasil;
    }
};