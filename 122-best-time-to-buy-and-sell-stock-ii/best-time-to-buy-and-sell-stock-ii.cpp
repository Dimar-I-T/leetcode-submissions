class Solution {
public:
    // dimar's solution
    int maxProfit(vector<int>& prices) {
        vector<int> lembahBukit, td;
        int n = prices.size(), hasil = 0;

        td.push_back(prices[0]);
        for (int x = 1; x < n; x++){
            if (prices[x] != prices[x - 1]){
                td.push_back(prices[x]);
            }
        }

        if (td.size() < 2){
            return 0;
        }

        if (td[0] < td[1]){
            lembahBukit.push_back(td[0]);
        }

        for (int x = 1; x < td.size() - 1; x++){
            if ((td[x] < td[x - 1] && td[x] < td[x + 1]) ||
                 (td[x] > td[x - 1] && td[x] > td[x + 1])){
                    lembahBukit.push_back(td[x]);
            }
        }   

        if (td[td.size() - 1] > td[td.size() - 2]){
            lembahBukit.push_back(td[td.size() - 1]);
        }

        for (int x = 0; x < lembahBukit.size(); x++){
            cout << lembahBukit[x] << " ";
        }

        if (lembahBukit.size() == 0){
            return 0;
        }

        for (int x = 0; x < lembahBukit.size() - 1; x += 2){
            hasil += (lembahBukit[x + 1] - lembahBukit[x]);
        }

        return hasil;
    }
};