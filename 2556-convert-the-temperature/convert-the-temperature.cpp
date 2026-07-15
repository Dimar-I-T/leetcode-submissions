class Solution {
public:
    // dimar's solution
    vector<double> convertTemperature(double celsius) {
        vector<double> hasil = {celsius + 273.15, celsius*1.80 + 32.00};
        return hasil;
    }
};