class Solution {
public:
    vector<vector<int>> buildSparseTable(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> lookup(n + 1, vector<int>(log2(n) + 1));

        for (int i = 0; i < n; i++)
            lookup[i][0] = arr[i];

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; (i + (1 << j) - 1) < n; i++) {
                if (lookup[i][j - 1] < lookup[i + (1 << (j - 1))][j - 1])
                    lookup[i][j] = lookup[i][j - 1];
                else
                    lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1];
            }
        }

        return lookup;
    }

    int query(int L, int R, vector<vector<int>>& lookup) {
        int j = (int)log2(R - L + 1);
        if (lookup[L][j] <= lookup[R - (1 << j) + 1][j])
            return lookup[L][j];
        else
            return lookup[R - (1 << j) + 1][j];
    }

    int res = 0;
    unordered_map<int, vector<int>> idx;
    vector<vector<int>> lookup;

    void f(int l, int r, vector<int>& arr) {
        if (l > r) {
            return;
        }

        if (l == r) {
            res = max(res, arr[l]);
            return;
        }

        vector<pair<int, int>> nextLR;
        int prevIdx = l;
        int minVal = query(l, r, lookup);
        vector<int> idxMin = idx[minVal];
        int n = idxMin.size();
        int i = 0;
        res = max(res, minVal * (r - l + 1));
        while (i < n) {
            int curr = idxMin[i];
            if (curr == prevIdx) {
                break;
            }

            if (curr > prevIdx) {
                nextLR.push_back({prevIdx, curr - 1});
                prevIdx = curr;
                break;
            }

            i++;
        }

        int edge = r;
        i++;
        for (; i < n; i++) {
            int curr = idxMin[i];
            if (curr == r) {
                edge = r - 1;
                break;
            }

            if (curr > r) {
                break;
            }

            if (prevIdx + 1 <= curr - 1) {
                nextLR.push_back({prevIdx + 1, curr - 1});
            }

            prevIdx = curr;
        }

        nextLR.push_back({prevIdx + 1, edge});
        for (pair<int, int> p : nextLR) {
            f(p.first, p.second, arr);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        lookup = buildSparseTable(heights);
        int n = heights.size();
        idx.reserve(n);
        for (int x = 0; x < n; x++) {
            int curr = heights[x];
            idx[curr].push_back(x);
        }

        f(0, n - 1, heights);
        return res;
    }
};