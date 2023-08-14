#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <array>
using namespace std;

class MinimumGeneticMutation {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<bool> used(bank.size(), false);
        layer = 0;
        mend = end;
        minlayer = bank.size() + 1;
        mutation(start, bank, used);
        if (minlayer > bank.size())
            return -1;
        return minlayer;
    }
private:
    void mutation(string& start, vector<string>& bank, vector<bool>& used) {
        if (layer >= minlayer) {
            return;
        }
        layer += 1;
        for (int i = 0;i < bank.size();++i) {
            if (used[i])
                continue;   //已经使用过了
            if (oneDifferent(start, bank[i])) {
                //cout << " cur choose: " << i << " layer: " << layer;
                if (mend.compare(bank[i]) == 0) {
                    //cout << " end layer:" << layer << endl;
                    minlayer = layer;
                    layer -= 1;
                    return;
                }
                used[i] = true;
                mutation(bank[i], bank, used);
                used[i] = false;
            }
        }
        layer -= 1;
    }
    bool oneDifferent(string& left, string& right) {
        int cnt = 0;
        for (int i = 0; i < 8;++i) {
            if (left[i] != right[i])
                ++cnt;
        }
        return cnt == 1;
    }
private:
    int layer{};
    int minlayer{};
    string mend{};
};

int main(int argc, char const* argv[]) {
    MinimumGeneticMutation cls;
    cout << cls.minMutation("AAAACCCC", "CCCCCCCC", vector<string>{"AAAACCCA","AAACCCCA","AACCCCCA","AACCCCCC","ACCCCCCC","CCCCCCCC","AAACCCCC","AACCCCCC"}) << " -> 4" << endl;
    cout << cls.minMutation("AACCGGTT", "AAACGGTA", vector<string>{"AACCGGTA", "AACCGCTA", "AAACGGTA"}) << " -> 2" << endl;
    cout << cls.minMutation("AACCGGTT", "AAACGGTA", vector<string>{"AACCGATT", "AACCGATA", "AAACGATA", "AAACGGTA"}) << " -> 4" << endl;
    cout << cls.minMutation("AACCGGTT", "AACCGGTA", vector<string>{"AACCGGTA"}) << " -> 1" << endl;
    cout << cls.minMutation("AACCTTGG", "AATTCCGG", vector<string>{"AATTCCGG", "AACCTGGG", "AACCCCGG", "AACCTACC"}) << " -> -1" << endl;
    cout << cls.minMutation("AAAAACCC", "AACCCCCC", vector<string>{"AAAACCCC", "AAACCCCC", "AACCCCCC"}) << " -> 3" << endl;
    return 0;
}
