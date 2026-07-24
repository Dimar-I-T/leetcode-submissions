class StockSpanner {
public:
    stack<pair<int, int>> st;
    int idx = 0;
    StockSpanner() {
    }

    int getSpan() {
        if (idx == 1) {
            //cout << "YANG PERTAMA\n";
            //cout << "\n";
            return 1;
        }

        pair<int, int> mostTop = st.top();
        int mostTopVal = mostTop.first;
        int mostTopInd = mostTop.second;
        int idxLater = mostTopInd;
        st.pop();

        //cout << "mostTopVal = " << mostTopVal << "\n";
        //cout << "mostTopInd = " << mostTopInd << "\n";
        pair<int, int> prev = st.top();
        int prevVal = prev.first;
        int prevInd = prev.second;
        
        //cout << "prevVal = " << prevVal << "\n";
        //cout << "prevInd = " << prevInd << "\n";
        int res = 0;
        if (mostTopVal < prevVal) {
            //cout << "Tidak Ke kiri!\n";
            // res = mostTopInd - prevInd;
            // //cout << "res = " << mostTopInd << " - " << prevInd << " = " << res << "\n"; 
            //cout << "\n";
            st.push(mostTop);
            return 1;
        }

        // mostTopVal >= prevVal (Ke kiri)
        //cout << "Ke kiri!\n";
        while (!st.empty()) {
            pair<int, int> currLeft = st.top();
            int currLeftVal = currLeft.first;
            int currLeftInd = currLeft.second;
            if (currLeftVal > mostTopVal) {
                //cout << "BERHENTI!\n\n";
                break;
            }

            //cout << "currLeftVal = " << currLeftVal << "\n";
            //cout << "currLeftInd = " << currLeftInd << "\n";
            res = mostTopInd - currLeftInd + 1;
            //cout << "res = " << mostTopInd << " - " << currLeftInd << " = " << res << "\n"; 
            idxLater = currLeftInd;

            st.pop();
        }

        if (st.empty()) {
            //cout << "HABIS!\n";
        }

        //cout << "\n";
        st.push({mostTopVal, idxLater});
        return res;
    }
    
    int next(int price) {
        //cout << "INPUT: " << price << "\n";
        idx++;
        //cout << "INDEX: " << idx << "\n";
        st.push({price, idx});
        return getSpan();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */