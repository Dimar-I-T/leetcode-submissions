class Solution {
public:
    // dimar's solution
    bool plus(vector<int>& digits, int i) {
        if (digits[i] < 9) {
            digits[i]++;
            return 1;
        }

        digits[i] = 0;
        if (i == 0) {
            return 0;
        }

        return plus(digits, i - 1);
    }
    
    vector<int> push_front(vector<int>& digits, int k) {
        vector<int> front = {k};
        for (int d : digits) {
            front.push_back(d);
        }

        return front;
    }

    vector<int> plusOne(vector<int>& digits) {
        bool res = plus(digits, digits.size() - 1);
        vector<int> resV = {};
        if (!res) {
            resV = push_front(digits, 1);
        } else {
            resV = digits;
        }

        return resV;
    }
};