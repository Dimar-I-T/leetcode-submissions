class Solution {
public:
    // dimar's solution
    int maxRepeating(string sequence, string word) {
        int n = sequence.length(), m = word.length();
        vector<pair<int, char>> As, Bs;
        int t = 0, hasil = 0, hasilSementara = 0;
        As.push_back({1, sequence[0]});
        for (int x = 1; x < n; x++){
            if (sequence[x] == sequence[x - 1]){
                As[t].first++;
            }else{
                As.push_back({1, sequence[x]});
                t++;
            }
        }
        
        t = 0;
        Bs.push_back({1, word[0]});
        for (int x = 1; x < m; x++){
            if (word[x] == word[x - 1]){
                Bs[t].first++;
            }else{
                Bs.push_back({1, word[x]});
                t++;
            }
        }
        
        int nS = As.size(), mS = Bs.size();
        if (mS > 1){
            int k = 0;
            bool lanjut = 0;
            for (int x = 0; x < nS; x++){
                cout << "x: " << x << " k: " << k << "\n";
                cout << "A first: " << As[x].first << " B first: " << Bs[k].first << "\n";
                cout << "A second: " << As[x].second << " B second: " << Bs[k].second << "\n";
                if (As[x].second == Bs[k].second && As[x].first >= Bs[k].first){
                    if (As[x].first == Bs[k].first){
                        k++;
                        if (k == mS){
                            k = 0;
                            cout << "nambah" << "\n";
                            hasilSementara++;
                            hasil = max(hasil, hasilSementara);
                            lanjut = 0;
                        }
                    }else{
                        cout << "lebih \n";
                        hasil = max(hasil, hasilSementara);
                        if (k == 0){
                            if (As[x].first - Bs[k].first != Bs[0].first || !lanjut){
                                hasilSementara = 0;
                            }

                            k++;
                        }else{
                            if (k == mS - 1){
                                cout << As[x].first << " - " << Bs[k].first << "==" << As[x].first - Bs[k].first << "\n";
                                hasilSementara++;
                                cout << "hasilS = " << hasilSementara << "\n";
                                hasil = max(hasil, hasilSementara);
                                cout << "nambah \n";
                                if (As[x].second != Bs[0].second){
                                    k = 0;
                                    cout << "reset \n\n";
                                    hasil = max(hasil, hasilSementara);
                                    hasilSementara = 0;
                                    continue;
                                }
                                
                                if (As[x].first - Bs[k].first != Bs[0].first){
                                    k = 0;
                                    cout << "reset \n";
                                    hasil = max(hasil, hasilSementara);
                                    hasilSementara = 0;
                                    if (As[x].second == Bs[0].second && As[x].first >= Bs[0].first){
                                        k++;
                                    }
                                }else{
                                    if (As[x].second == Bs[0].second){
                                        k = 1;
                                        lanjut = 1;
                                    }else{
                                        lanjut = 0;
                                        hasil = max(hasil, hasilSementara);
                                        hasilSementara = 0;
                                    }
                                }
                            }else{
                                cout << "reset\n";
                                k = 0;
                                hasil = max(hasil, hasilSementara);
                                hasilSementara = 0;
                            }
                        }
                    }
                }else{
                    cout << "reset \n";
                    k = 0;
                    hasil = max(hasil, hasilSementara);
                    hasilSementara = 0;
                }
                
                cout << "hasilSem = " << hasilSementara << "\n";
                cout << "\n";
                hasil = max(hasil, hasilSementara);
            }
        }else{
            for (int x = 0; x < nS; x++){
                cout << As[x].second << " " << Bs[0].second << "\n";
                cout << As[x].first << " " << Bs[0].first << "\n";
                if (As[x].second == Bs[0].second){
                    hasilSementara += (As[x].first / Bs[0].first);
                }else{
                    hasil = max(hasil, hasilSementara);
                    hasilSementara = 0;
                }
            }

            hasil = max(hasil, hasilSementara);
        }

        return hasil;
    }
};