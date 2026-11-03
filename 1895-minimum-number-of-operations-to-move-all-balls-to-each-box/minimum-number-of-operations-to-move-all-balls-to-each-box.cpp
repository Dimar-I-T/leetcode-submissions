class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<pair<int, int>> v(n);
        for (int x = 0; x < n; x++) {
            if (boxes[x] == '1') {
                v[x].first = x;
                v[x].second = 1;
            }
        }

        vector<pair<int, int>> prefLeft(n);
        prefLeft[0].first = v[0].first;
        prefLeft[0].second = v[0].second;
        for (int x = 1; x < n; x++) {
            prefLeft[x].first = prefLeft[x - 1].first + v[x].first;
            prefLeft[x].second = prefLeft[x - 1].second + v[x].second;
        } 

        vector<pair<int, int>> prefRight(n);
        vector<pair<int, int>> v1(n);
        for (int x = 0; x < n; x++) {
            if (boxes[x] == '1') {
                v1[x].first = n - x - 1;
                v1[x].second = 1;
            }
        }

        prefRight[n - 1].first = v1[n - 1].first;
        prefRight[n - 1].second = v1[n - 1].second;
        for (int x = n - 2; x >= 0; x--) {
            prefRight[x].first = prefRight[x + 1].first + v1[x].first;
            prefRight[x].second = prefRight[x + 1].second + v1[x].second;
        } 
        
        vector<int> ans(n);
        for (int x = 0; x < n; x++) {
            int kiri = 0;
            if (x > 0) {
                kiri = prefLeft[x - 1].first;
            }

            int kkiri = ((prefLeft[n - 1].first - kiri) - x * prefRight[x].second);
            int b = 0;
            if (x > 0) {
                b = (n - x - 1) * prefLeft[x - 1].second;
            }

            int kkanan = ((prefRight[0].first - prefRight[x].first) - b);
            ans[x] = kkiri + kkanan;
        }

        return ans;
    }
};