class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums1;
        unordered_map<int, int> freq;
        freq.reserve(n);
        for (int x : nums) {
            freq[x]++;
            if (freq[x] <= 3) {
                nums1.push_back(x);
            }
        }


        n = nums1.size();
        sort(nums1.begin(), nums1.end());
        
        //cout << "nums1:\n";
        for (int x : nums1) {
            //cout << x << " ";
        }

        //cout << "\n";
        vector<vector<int>> res;
        int prevX = -INT_MAX;
        for (int x = 0; x < n; x++) {
            int l = x + 1;
            //cout << "prevX: " << prevX << "\n";
            //cout << "curr: " << nums1[x] << "\n";
            if (prevX == nums1[x]) {
                continue;
            }

            int r = n - 1;
            int t = -nums1[x];
            int prevL = -INT_MAX;
            int prevR = -INT_MAX;
            while (l < r) {
                if (l == x) {
                    l++;
                    continue;
                }

                if (r == x) {
                    r--;
                    continue;
                }

                int left = nums1[l];
                int right = nums1[r];
                int sum = left + right;
                //cout << "l: " << l << "\n";
                //cout << "r: " << r << "\n";
                //cout << "leftVal: " << left << "\n";
                //cout << "rightVal: " << right << "\n";
                if (prevL == left) {
                    //cout << "KIRI SAMA SEPERTI SEBELUM, SKIP\n";
                    l++;
                    continue;
                }

                if (prevR == right) {
                    //cout << "KANAN SAMA SEPERTI SEBELUM, SKIP\n";
                    r--;
                    continue;
                }

                //cout << "sum: " << sum << "\n";
                if (sum == t) {
                    //cout << "SAMA!\n";
                    vector<int> resSem = {nums1[x], left, right};
                    sort(resSem.begin(), resSem.end());
                    res.push_back(resSem);
                    prevL = left;
                    prevR = right;
                    l++;
                    //cout << "tambahkan: " << resSem[0] << ", " << resSem[1] << ", " << resSem[2] << "\n\n";
                    continue;
                }

                if (sum < t) {
                    //cout << "KURANG! L GESER KANAN\n\n";
                    prevL = left;
                    l++;
                    continue;
                }

                if (sum > t) {
                    //cout << "LEBIH! R GESER KIRI\n\n";
                    prevR = right;
                    r--;
                    continue;
                }
            }

            prevX = nums1[x];
        }

        return res;
    }
};