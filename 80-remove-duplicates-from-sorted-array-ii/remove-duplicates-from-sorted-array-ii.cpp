class Solution {
public:
    // dimar's solution
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), awalDuplikat = 0, k = 1, banyakDuplikat = 0, angkaSama = 0;
        for (int x = 1; x < n; x++){
            if (banyakDuplikat == 2){
                break;
            }

            if (nums[x] == nums[x - 1]){
                banyakDuplikat++;
                //cout << "x = " << x << " " << nums[x] << " = " << nums[x - 1] << " -> bd = " << banyakDuplikat << "\n";
            }else{
                banyakDuplikat = 0;
            }

            awalDuplikat++;
            k++;
        }

        if (k < n){
            angkaSama = nums[k - 1];
            for (int x = awalDuplikat; x < n; x++){
                //cout << x << " angkaSama = " << angkaSama << " vs " << nums[x] << "\n";
                if (angkaSama != nums[x]){
                    nums[awalDuplikat] = nums[x];
                    awalDuplikat++;
                    angkaSama = nums[x];
                    banyakDuplikat = 0;
                    k++;
                }else{
                    banyakDuplikat++;
                    if (banyakDuplikat < 2){
                        nums[awalDuplikat] = nums[x]; 
                        awalDuplikat++;
                        k++;
                    }
                }
            }

            for (int x = 0; x < n; x++){
                cout << nums[x] << " ";
            }

            return k - 1;
        }
        
        if (n > 1 && nums[k - 1] == nums[k - 2] && banyakDuplikat == 2){
            k--;
        }

        return k;
    }
};