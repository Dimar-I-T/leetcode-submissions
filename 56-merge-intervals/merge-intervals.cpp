class Solution {
public:
    // dimar's solution
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        intervals.push_back({INT_MAX, INT_MAX});
        int n = intervals.size();
        vector<vector<int>> hasil;
        int start = intervals[0][0];
        int akhir = intervals[0][1];
        for (int x = 1; x < n; x++) {
            int start1 = intervals[x][0];
            int akhir1 = intervals[x][1];
            if (akhir < start1) {
                akhir = max(akhir, intervals[x - 1][1]);
                hasil.push_back({start, akhir});
                start = start1;
                akhir = akhir1;
            } else {
                akhir = max(akhir, akhir1);
            }
        }

        return hasil;
    }
};