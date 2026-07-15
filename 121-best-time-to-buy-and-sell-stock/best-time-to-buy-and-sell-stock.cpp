class Solution {
public:
    // dimar's solution
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> tidakBersebalahan;
        tidakBersebalahan.push_back(prices[0]);
        for (int x = 1; x < n; x++){
            if (prices[x] != prices[x - 1]){
                tidakBersebalahan.push_back(prices[x]);
            }
        }

        int nB = tidakBersebalahan.size();
        vector<int> pricesBaru(nB);
        for (int x = 0; x < nB; x++){
            pricesBaru[x] = -1;
        }

        pricesBaru[0] = prices[0];
        pricesBaru[nB - 1] = tidakBersebalahan[nB - 1];
        for (int x = 1; x < nB - 1; x++){
            if ((tidakBersebalahan[x] > tidakBersebalahan[x - 1] && tidakBersebalahan[x] > tidakBersebalahan[x + 1])||
                (tidakBersebalahan[x] < tidakBersebalahan[x - 1] && tidakBersebalahan[x] < tidakBersebalahan[x + 1])){
                    pricesBaru[x] = tidakBersebalahan[x];
            }
        }

        vector<int> asli;
        for (int x = 0; x < nB; x++){
            if (pricesBaru[x] != -1){
                asli.push_back(pricesBaru[x]);
            }
        }

        int hasil = 0;
        priority_queue<int> maks;
        unordered_map<int, int> idx;
        for (int x = 0; x < asli.size(); x++){
            maks.push(asli[x]);
            idx[asli[x]] = max(idx[asli[x]], x);
        }

        while (!maks.empty()){
            if (maks.top() <= hasil){
                break;
            }

            int idks = idx[maks.top()], sel = 0;
            for (int x = idks; x >= 0; x--){
                hasil = max(hasil, maks.top() - asli[x]);
            }

            maks.pop();
        }

        return hasil;
    }
};