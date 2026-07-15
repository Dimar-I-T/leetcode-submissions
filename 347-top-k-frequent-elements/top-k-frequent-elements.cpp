class Solution {
public:
    // dimar's solution
    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        m.reserve(n);
        for (int x : nums) {
            m[x]++;
        }

        vector<pair<int, int>> v;
        for (auto& x : m) {
            v.push_back(x);
        }

        sort(v.begin(), v.end(), comp);
        vector<int> res;
        res.reserve(k);
        auto itr = v.begin();
        while (itr != v.end() && k > 0) {
            res.emplace_back(itr->first);
            itr++;
            k--;
        }

        return res;
    }
};