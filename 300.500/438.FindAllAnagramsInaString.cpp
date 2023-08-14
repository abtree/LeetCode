#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

class FindAllAnagramsInaString
{
public:
    vector<int> findAnagrams(string s, string p) {
        //通过比较数组相等
        int psize = p.size();
        vector<int> ret;
        if (psize > s.size())
            return ret;
        array<int, 26> sCount{};
        array<int, 26> pCount{};
        for (int i = 0;i < psize;++i) {
            sCount[s[i] - 'a']++;
            pCount[p[i] - 'a']++;
        }
        if (sCount == pCount) {
            ret.emplace_back(0);
        }
        int n = s.size() - psize;
        for (int i = 0;i < n;++i) {
            sCount[s[i] - 'a']--;
            sCount[s[i + psize] - 'a']++;
            if (sCount == pCount)
                ret.emplace_back(i + 1);
        }
        return ret;
    }
public:
    vector<int> findAnagrams1(string s, string p) {
        //通过比较差异数为0
        int psize = p.size();
        vector<int> ret;
        if (psize > s.size())
            return ret;
        array<int, 26> count{};
        for (int i = 0;i < psize;++i) {
            ++count[s[i] - 'a'];
            --count[p[i] - 'a'];
        }
        int differ = 0;
        for (int x : count) {
            if (x != 0)
                differ++;
        }
        if (differ == 0)
            ret.emplace_back(0);
        int n = s.size() - psize;
        for (int i = 0;i < n;++i) {
            int x = s[i] - 'a';
            if (count[x] == 1) {
                --differ;
            }
            else if (count[x] == 0) {
                ++differ;
            }
            --count[x];
            x = s[i + psize] - 'a';
            if (count[x] == -1) {
                --differ;
            }
            else if (count[x] == 0) {
                ++differ;
            }
            ++count[x];
            if (differ == 0)
                ret.emplace_back(i + 1);
        }
        return ret;
    }
};

void Print(vector<int>& ret) {
    cout << "[";
    for (int x : ret) {
        cout << x << ", ";
    }
    cout << "]" << endl;
}

int main(int argc, char const* argv[])
{
    FindAllAnagramsInaString cls;
    auto& ret4 = cls.findAnagrams1("aaaaaaaaaa", "aaaaaaaaaaaaa");
    Print(ret4);
    auto& ret3 = cls.findAnagrams1("af", "be");
    Print(ret3);
    auto& ret = cls.findAnagrams1("cbaebabacd", "abc");
    Print(ret);
    auto& ret1 = cls.findAnagrams1("abab", "ab");
    Print(ret1);
    auto& ret2 = cls.findAnagrams1("aa", "bb");
    Print(ret2);
    return 0;
}
