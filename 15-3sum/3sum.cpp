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
        //d << "nums1:\n";
        for (int x : nums1) {
            //d << x << " ";
        }

        //d << "\n";
        set<vector<int>> resS;
        for (int x = 0; x < n; x++) {
            int l = 0;
            int r = n - 1;
            int t = -nums1[x];
            //d << "curr val: " << nums1[x] << "\n";
            //d << "target two sum: " << t << "\n";
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
                //d << "l: " << l << "\n";
                //d << "r: " << r << "\n";
                //d << "left: " << left << "\n";
                //d << "right: " << right << "\n";
                //d << "sum: " << sum << "\n";
                if (sum == t) {
                    //d << "SESUAI TARGET!\n";
                    vector<int> resSem = {nums1[x], left, right};
                    sort(resSem.begin(), resSem.end());
                    //d << "MASUKKAN: " << "{" << resSem[0] << ", " << resSem[1] << ", " << resSem[2] << "}\n";
                    resS.insert(resSem);
                    l++;
                    //d << "\n";
                    continue;
                }

                if (sum < t) {
                    //d << "KURANG DARI t!\n";
                    //d << "\n";
                    l++;
                    continue;
                }

                if (sum > t) {
                    //d << "LEBIH DARI t!\n";
                    //d << "\n";
                    r--;
                    continue;
                }

                l++;
                r--;

            }
        }

        vector<vector<int>> res;
        for (vector<int> v : resS) {
            res.push_back(v);
        }

        return res;
    }
};