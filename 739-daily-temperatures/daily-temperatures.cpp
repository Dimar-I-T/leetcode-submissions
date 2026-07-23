class Solution {
public:
    struct Node {
        Node(int val, int idx) : val(val), idx(idx), left(nullptr), right(nullptr) {};
        int val;
        int idx;
        Node* left;
        Node* right;
    };

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<Node*> nodes(n);
        for (int x = 0; x < n; x++) {
            nodes[x] = new Node(temperatures[x], x);
        }

        Node* head = new Node(0, 0);
        head->right = nodes[0];
        nodes[0]->left = nullptr;
        for (int x = 1; x < n - 1; x++) {
            nodes[x - 1]->right = nodes[x];
            nodes[x]->left = nodes[x - 1];

            nodes[x + 1]->left = nodes[x];
            nodes[x]->right = nodes[x + 1];
        }

        nodes[n - 1]->right = nullptr;
        vector<int> answers(n);
        head = head->right;
        int prev = head->val;
        while (head != NULL) {
            if (head->left == NULL) {
                head = head->right;
                continue;
            }

            int curr = head->val;
            //cout << "prev: " << prev << "\n";
            //cout << "curr: " << curr << "\n";
            if (curr > prev) {
                //cout << "KE KIRI!\n";
                int sum = 0;
                Node* currTemp = head;
                currTemp = currTemp->left;
                while (currTemp != NULL) {
                    int currLeft = currTemp->val;
                    if (curr <= currLeft) {
                        //cout << "BERHENTI\n";
                        break;
                    }

                    answers[currTemp->idx] = head->idx - currTemp->idx;
                    //cout << "currLeft: " << currLeft << "\n";

                    currTemp = currTemp->left;
                }

                head->left = currTemp;
            }

            //cout << "\n";
            prev = curr;
            head = head->right;
        }

        //cout << "answers:\n";
        // for (int x : answers) {
        //     //cout << x << " ";
        // }

        return answers;
    }
};