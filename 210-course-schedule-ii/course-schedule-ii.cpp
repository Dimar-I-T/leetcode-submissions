class Solution {
public:
    // dimar's solution
    vector<vector<int>> koneksi = vector<vector<int>>(2001);
    vector<int> hasilKebalik;
    vector<int> sudah = vector<int>(2001);
    int bisa = 1;

    void DFS(int sek) {
        sudah[sek] = 1;
        vector<int> kon = koneksi[sek];
        for (int x = 0; x < kon.size(); x++) {
            if (sudah[kon[x]] == 1) {
                bisa = 0;
                break;
            }

            if (sudah[kon[x]] == 0) {
                DFS(kon[x]);
            }
        }

        hasilKebalik.push_back(sek);
        sudah[sek] = 2;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> hasil;
        for (int x = 0; x < n; x++) {
            koneksi[prerequisites[x][1]].push_back(prerequisites[x][0]);
        }

        for (int x = 0; x < numCourses; x++) {
            if (sudah[x] == 0) {
                DFS(x);
            }
        }

        for (int y = 0; y < hasilKebalik.size(); y++) {
            hasil.push_back(hasilKebalik[hasilKebalik.size() - 1 - y]);
        }

        if (bisa == 0) {
            hasil.clear();
        }

        return hasil;
    }
};