#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <bitset>

using namespace std;

//187. 重复的DNA序列
class RepeatedDNASequences
{
    /* 所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。
    */
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        unordered_map<string, int> repeated;
        int len = s.size() - 9;
        for (int i = 0; i < len; ++i) {
            string substr = s.substr(i, 10);
            int &c = repeated[substr];
            c += 1;
            if(c == 2){
                ret.push_back(substr);
            }
        }
        return ret;
    }
public:
    //用2进制代替字符串匹配(提高效率)
    vector<string> findRepeatedDnaSequences2(string s) {
        //对应二进制00, 01, 10, 11.那么10个组合只要20位就够了。
        unordered_map<char, int> m{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        vector<string> res;
        bitset<1 << 20> s1, s2; //那么所有组合的值将在0到(1 << 20 - 1)之间
        int val = 0, mask = (1 << 20) - 1; //mask等于二进制的20个1
        //类似与滑动窗口先把前10个字母组合
        for (int i = 0; i < 10; ++i) 
            val = (val << 2) | m[s[i]];
        s1.set(val); //置位
        for (int i = 10; i < s.size(); ++i) {
            val = ((val << 2) & mask) | m[s[i]]; //去掉左移的一个字符再加上一个新字符
            if (s2.test(val)) 
                continue; //出现过两次跳过
            if (s1.test(val)) {
                res.push_back(s.substr(i - 9, 10));
                s2.set(val);
            } else{ 
                s1.set(val);
            }
        }
        return res;
    }
};

int main(int argc, char const* argv[])
{
    RepeatedDNASequences cls;
    auto& ret = cls.findRepeatedDnaSequences2("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    cout << "[";
    for(auto &it : ret){
        cout << it.c_str() << " , ";
    }
    cout << "]" << endl;

    auto& ret1 = cls.findRepeatedDnaSequences2("AAAAAAAAAAA");
    cout << "[";
    for(auto &it : ret1){
        cout << it.c_str() << " , ";
    }
    cout << "]" << endl;

    auto& ret2 = cls.findRepeatedDnaSequences2("AAAAAAAAAAAAA");
    cout << "[";
    for(auto &it : ret2){
        cout << it.c_str() << " , ";
    }
    cout << "]" << endl;

    return 0;
}
