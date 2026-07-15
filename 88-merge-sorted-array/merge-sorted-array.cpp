class Solution {
public:
    // dimar's solution
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> hasil;
        queue<int> q1, q2;
        for (int x = 0; x < n; x++){
            q2.push(nums2[x]);
        }

        for (int x = 0; x < m; x++){
            q1.push(nums1[x]);
        }
    
        int kiri1 = 0, kiri2 = 0;
        while (!q1.empty() || !q2.empty()){
            if (q1.empty()){
                break;
            }
            
            if (q2.empty()){
                break;
            }
            if (q1.front() <= q2.front()){
                hasil.push_back(q1.front());
                q1.pop();
                kiri1++;
            }else{
                hasil.push_back(q2.front());
                q2.pop();
                kiri2++;
            }
        }

        if (q1.empty()){
            for (int x = kiri2; x < n; x++){
                hasil.push_back(nums2[x]);
            }
        }
        
        if (q2.empty()){
            for (int x = kiri1; x < m; x++){
                hasil.push_back(nums1[x]);
            }
        }

        for (int x = 0; x < m; x++){
            nums1[x] = hasil[x];
        }

        for (int x = m; x < n + m; x++){
            nums1[x] = hasil[x];
        }
    }
};