class Solution {
public:
    // dimar's solution
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<int, int>> banyakKiri(n);
        vector<int> banyakKanan(n);
        banyakKiri[0] = {1, 0};
        // buat non-decreasing
        for (int x = 1; x < n; x++){
            if (ratings[x] > ratings[x - 1]){
                banyakKiri[x].first = banyakKiri[x - 1].first + 1;
            }else{
                if (ratings[x] == ratings[x - 1]){
                    banyakKiri[x].first = 1;
                    if (banyakKiri[x - 1].second == 1){
                        banyakKiri[x - 1].first = 1;
                    }
                }else{
                    banyakKiri[x].second = 1;
                    if (banyakKiri[x - 1].second == 1){
                        banyakKiri[x - 1].first = 0; 
                    }

                    banyakKiri[x].first = 1;
                }
            }
        }
        
        for (int x = 0; x < n; x++){
            banyakKanan[x] = 1;
        }

        banyakKanan[n - 1] = 1;
        for (int x = n - 2; x >= 0; x--){
            if (ratings[x] > ratings[x + 1]){
                banyakKanan[x] = banyakKanan[x + 1] + 1;
            }else{
                if (ratings[x] == ratings[x + 1]){
                    banyakKanan[x] = 1;
                }else{
                    banyakKanan[x] = 1;
                }
            }
        }

        int hasil = 0;
        for (int x = 0; x < n; x++){
            hasil += max(banyakKiri[x].first, banyakKanan[x]);
            //cout << banyakKiri[x].first << " ";
        }

        //cout << "\n";

        // for (int x = 0; x < n; x++){
        //     cout << banyakKanan[x] << " ";
        // }

        return hasil;
    }
};