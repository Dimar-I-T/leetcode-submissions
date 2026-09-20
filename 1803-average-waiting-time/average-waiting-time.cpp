class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        vector<double> waits(n);
        double prev = customers[0][0];
        for (int x = 0; x < n; x++) {
            if (prev < customers[x][0]) {
                prev = customers[x][0];
            }

            double next = prev + customers[x][1];
            waits[x] = next - customers[x][0];
            prev = next;
        }

        double avg = 0;
        for (double w : waits) {
            avg += w;
        }

        return avg / n;
    }
};