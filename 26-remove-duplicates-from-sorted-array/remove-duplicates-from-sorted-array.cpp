class Solution {
public:
    // dimar's solution
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), awalDuplikat = 1, nilaiSama = 0, k = 0;
        for (int x = 1; x < n; x++){
            if (nums[x] == nums[x - 1]){
                nilaiSama = nums[x];
                break;
            }

            awalDuplikat++;
        }
        
        for (int x = awalDuplikat; x < n; x++){
            if (nums[x] != nilaiSama){
                nums[awalDuplikat] = nums[x];
                awalDuplikat++;
                nilaiSama = nums[x];
            }else{
            }
        }

        unordered_map<int, bool> sudah;
        for (int x = 0; x < n; x++){
            if (sudah[nums[x]]){
                break;
            }

            sudah[nums[x]] = 1;
            k++;
        }

        return k;
    }
};