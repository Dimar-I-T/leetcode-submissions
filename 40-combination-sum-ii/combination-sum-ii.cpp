class Solution {
public:
    // dimar's solution
    int n, t;
    vector<int> ca;
    set<vector<int>> jawaban;
    void f(int i, int jumlah, vector<int> v){
        if (jumlah > t){
            return;
        }

        if (i == n){
            if (jumlah == t){
                sort(v.begin(), v.end());
                jawaban.insert(v);
            }

            return;
        }

        bool bisa = 1;
        for (auto x: v){
            if (ca[i] == x){
                bisa = 0;
                break;
            }
        }

        if (bisa){
            f(i + 1, jumlah, v);
        }

        v.push_back(ca[i]);
        f(i + 1, jumlah + ca[i], v);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ca = candidates;
        n = ca.size();
        t = target;
        f(0, 0, {});
        vector<vector<int>> hasil;
        for (auto x: jawaban){
            hasil.push_back(x);
        }

        return hasil;
    }
};