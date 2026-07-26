class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> ps(n);
        for (int x = 0; x < n; x++) {
            ps[x] = {target - position[x], speed[x]};
        }

        sort(ps.begin(), ps.end(), cmp);
        // for (pair<int, int> p : ps) {
        //     cout << p.first << ":" << p.second << " ";
        // }

        vector<float> pos(n);
        for (int x = 0; x < n; x++) {
            pos[x] = ((float)ps[x].first)/((float)ps[x].second); 
        }

        // cout << "\n";
        // for (float x : pos) {
        //     cout << x << " ";
        // }

        float prev = pos[0];
        stack<float> st;
        st.push(prev);
        for (float x = 1; x < n; x++) {
            float top = st.top();
            float curr = pos[x];
            if (curr > top) {
                st.push(curr);
            }
        }

        return st.size();
    }
};