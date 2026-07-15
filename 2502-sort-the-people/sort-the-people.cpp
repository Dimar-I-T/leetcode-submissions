class Solution {
public:
    // dimar's solution
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> tinggi;
        for (int x = 0; x < names.size(); x++){
            tinggi[heights[x]] = names[x];
        }

        sort(heights.begin(), heights.end());
        vector<string> hasil(names.size());
        int a = 0;
        for (int x = heights.size() - 1; x >= 0; x--){
            hasil[a] = tinggi[heights[x]];
            a++;
        }

        return hasil;
    }
};