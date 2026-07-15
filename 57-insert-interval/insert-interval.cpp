class Solution {
public:
    // dimar's solution
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        intervals.insert(intervals.begin() + 0, 1, {0, 0});
        intervals.push_back({INT_MAX, INT_MAX});
        int n = intervals.size();
        vector<vector<int>> hasil;
        int kiriNew = newInterval[0];
        int kananNew = newInterval[1];
        int merging = 0;
        vector<int> mergedInterval;
        for (int x = 1; x < n; x++) {
            int kiriSek = intervals[x][0];
            int kananSek = intervals[x][1];
            if (!merging && kiriNew < kiriSek) {
                merging = 1;

                if (kiriNew <= intervals[x - 1][1]) {
                    if (hasil.size() > 0) {
                        hasil.pop_back();
                    }

                    mergedInterval.push_back(intervals[x - 1][0]);
                    if (kananNew <= intervals[x - 1][1]) {
                        mergedInterval.push_back(intervals[x - 1][1]);
                        hasil.push_back(mergedInterval);
                        merging = 2;
                    }
                }else {
                    mergedInterval.push_back(kiriNew);
                }
            }

            if (merging == 1) {
                if (kananNew < kiriSek) {
                    merging = 2;
                    mergedInterval.push_back(kananNew);
                    hasil.push_back(mergedInterval);
                } else if (kananNew <= kananSek) {
                    merging = 2;
                    mergedInterval.push_back(kananSek);
                    hasil.push_back(mergedInterval);
                    continue;
                }
            }

            if (!merging || merging > 1) {
                hasil.push_back(intervals[x]);
            }
        }

        hasil.pop_back();
        if (n == 1) {
            hasil.push_back({kiriNew, kananNew});
        }

        return hasil;
    }
};