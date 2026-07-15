class Solution {
public:
    // dimar's solution
    int deleteAndEarn(vector<int>& nums) {
        set<int> numsS;
        int n = nums.size();
        map<int, int> B;
        sort(nums.begin(), nums.end());
        for (int x = 0; x < n; x++){
            numsS.insert(nums[x]);
            B[nums[x]] += nums[x];
        }

        vector<int> numV, bV;
        for (auto itr = numsS.begin(); itr != numsS.end(); ++itr){
            numV.push_back(*itr);
            bV.push_back(B[*itr]);
        }

        int b = bV.size();
        vector<int> DP(b + 1);
        DP[1] = bV[0];
        for (int x = 2; x < b + 1; x++){
            if (numV[x - 2] == numV[x - 1] - 1){
                DP[x] = max(DP[x - 1], DP[x - 2] + bV[x - 1]);
            }else{
                DP[x] = DP[x - 1] + bV[x - 1]; 
            }
        }

        return DP[b];
    }
};