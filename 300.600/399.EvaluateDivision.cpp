#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;

class EvaluateDivision {
private:
    struct SData {
        double value{};
        int group{};
    };
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int gid = 1;
        unordered_map<int, SData> datas;
        //先处理分组
        for (int i = 0; i < equations.size(); ++i) {
            int k1 = stringtokey(equations[i][0]);
            int k2 = stringtokey(equations[i][1]);
            SData& d1 = datas[k1];
            SData& d2 = datas[k2];
            if (d1.group == 0 && d2.group == 0) {
                //两个都没进组
                d2.value = 1;
                d1.value = values[i];
                d1.group = gid;
                d2.group = gid;
                ++gid;
            }if (d1.group == 0 && d2.group > 0) {
                d1.group = d2.group;
                d1.value = d2.value * values[i];
            }if (d1.group > 0 && d2.group == 0) {
                d2.group = d1.group;
                d2.value = d1.value / values[i];
            }if (d1.group > 0 && d2.group > 0 && d1.group != d2.group) {
                //合并两个分组
                int og = d1.group;
                d1.group = d2.group;
                double t = d2.value * values[i] / d1.value;
                d1.value = d2.value * values[i];
                for (auto& c : datas) {
                    if (c.second.group == og) {
                        c.second.group = d2.group;
                        c.second.value *= t;
                    }
                }
            }
        }
        //计算值
        vector<double> ret(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++i) {
            int k1 = stringtokey(queries[i][0]);
            int k2 = stringtokey(queries[i][1]);
            if (datas.find(k1) == datas.end() || datas.find(k2) == datas.end()) {
                continue;   //没有找到
            }
            if (datas[k1].group != datas[k2].group) {
                continue;   //不在一个组
            }
            ret[i] = datas[k1].value / datas[k2].value;
        }
        return ret;
    }
private:
    //将string转换为int
    int stringtokey(string& s) {
        int key = 0;
        for (int i = 0; i < s.size();++i) {
            if (isalpha(s[i])) {
                key += pow(37, i) * (s[i] - 'a'+1);
            }
            else {
                key += pow(37, i) * (s[i] - '0' + 27);
            }
        }
        return key;
    }
};

int main(int argc, char const* argv[]) {
    EvaluateDivision cls;
    auto& ret = cls.calcEquation(vector<vector<string>>{ {"a", "b"}, { "b","c" }}, vector<double>{2, 3},
        vector<vector<string>>{ {"a", "c"}, { "b","a" }, { "a","e" }, { "a","a" }, { "x","x" }});
    cout << "[";
    for (auto x : ret) {
        cout << x << " , ";
    }
    cout << "]" << endl;
    
    auto& ret1 = cls.calcEquation(vector<vector<string>>{ {"a", "b"}, { "b","c" }, { "bc","cd" }}, vector<double>{1.5, 2.5, 5},
        vector<vector<string>>{ {"a", "c"}, { "c","b" }, { "bc","cd" }, { "cd","bc" }});
    cout << "[";
    for (auto x : ret1) {
        cout << x << " , ";
    }
    cout << "]" << endl;

    auto& ret2 = cls.calcEquation(vector<vector<string>>{ {"a", "b"}}, vector<double>{0.5},
        vector<vector<string>>{ {"a", "b"}, { "b","a" }, { "a","c" }, { "x","y" }});
    cout << "[";
    for (auto x : ret2) {
        cout << x << " , ";
    }
    cout << "]" << endl;
    return 0;
}
