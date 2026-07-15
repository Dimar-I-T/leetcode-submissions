class Solution {
public:
    // dimar's solution
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maks = 0;
        for (int x = 0; x < candies.size(); x++){
            maks = max(maks, candies[x]);
        }

        vector<bool> hasil(candies.size());
        for (int x = 0; x < candies.size(); x++){
            if (candies[x] + extraCandies >= maks){
                hasil[x] = true;
            }
        }

        return hasil;
    }
};