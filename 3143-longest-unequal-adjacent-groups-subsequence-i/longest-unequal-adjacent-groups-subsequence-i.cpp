class Solution {
public:
    // dimar's solution
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int l = groups[0];
        vector<string> hasil;
        hasil.push_back(words[0]);
        for (int r = 1; r < groups.size(); r++){
            if (groups[r] != l){
                l = groups[r];
                hasil.push_back(words[r]);
            }
        }

        return hasil;
    }
};