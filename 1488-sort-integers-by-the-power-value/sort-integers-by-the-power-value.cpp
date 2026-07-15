class Solution {
public:
    // dimar's solution
    int memo[1000001] = {0}; // untuk banyak power
    void Power(int n){
        if (memo[n] == 0 && n != 1){
            if (n % 2 == 0){
                Power(n / 2);
                memo[n] = memo[n / 2] + 1;
            }else{
                Power(3*n + 1);
                memo[n] = memo[3*n + 1] + 1;
            }
        }
    }

    int getKth(int lo, int hi, int k) {
        int a = 0;
        priority_queue<pair<int, int>> q;
        for (int x = 1; x <= hi; x *= 2){
            memo[x] = a;
            a++;
        }
        
        for (int x = lo; x <= hi; x++){
            Power(x);
            q.emplace(make_pair(-memo[x], -x));
        }

        int hasil = 0, ke = 0;
        while (!q.empty()){
            pair<int, int> p = q.top();
            //cout << -p.second << "=>" << -p.first << "\n";
            if (ke == k - 1){
                hasil = -p.second;
            }
            q.pop();
            ke++;
        }

        return hasil;
    }
};