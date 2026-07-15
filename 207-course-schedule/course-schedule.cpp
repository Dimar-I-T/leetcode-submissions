class Solution {
public:
    // dimar's solution
    vector<vector<int>> koneksi = vector<vector<int>>(20001); 
    vector<int> sudah = vector<int>(20001);
    int bisa = 1;
    void DFS(int sek){
        sudah[sek] = 1;
        vector<int> kon = koneksi[sek];
        for (int x = 0; x < kon.size(); x++){
            int sel = kon[x];
            if (sudah[sel] == 1){
                bisa = 0;
                break;
            }

            if (sudah[sel] == 0){
                DFS(sel);
            }
        }

        sudah[sek] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        for (int x = 0; x < n; x++){
            koneksi[prerequisites[x][1]].push_back(prerequisites[x][0]);
        }

        for (int x = 0; x < numCourses; x++){
            if (sudah[x] == 0){
                DFS(x);
            }
        }

        return bisa;
    }
};