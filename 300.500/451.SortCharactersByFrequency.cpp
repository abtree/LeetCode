#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

class SortCharactersByFrequency {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char c : s){
            mp[c]++;
        }
        vector<pair<char, int>> vec;
        for(auto &kv : mp){
            vec.emplace_back(kv);
        }
        sort(vec.begin(), vec.end(), [](const pair<char, int> &a,const pair<char, int> &b){
            return a.second > b.second;
        });
        string ret = "";
        for(auto &p : vec){
            for(int i =0;i< p.second;++i){
                ret.push_back(p.first);
            }
        }
        return ret;
    }
public:
    string frequencySort1(string s) {
        int maxf = 0;
        unordered_map<char, int> mp;
        for(char c : s){
            maxf = max(maxf, ++mp[c]);
        }
        //注意这里 相同出现次数的字符 可能会有多个
        vector<string> bucket(maxf+1, "");
        for(auto &kv : mp){
            bucket[kv.second].push_back(kv.first);
        }
        string ret = "";
        for(int i= maxf; i > 0;--i){
            string &b = bucket[i];
            for(char c : b){
                for(int j =0;j<i;++j){
                    ret.push_back(c);
                }
            }
        }
        return ret;
    }
};

int main(){
    SortCharactersByFrequency cls;
    cout << "tree -> " << cls.frequencySort("tree").c_str() << endl;
    cout << "cccaaa -> " << cls.frequencySort("cccaaa").c_str() << endl;
    cout << "Aabb -> " << cls.frequencySort("Aabb").c_str() << endl;

    cout << "tree -> " << cls.frequencySort1("tree").c_str() << endl;
    cout << "cccaaa -> " << cls.frequencySort1("cccaaa").c_str() << endl;
    cout << "Aabb -> " << cls.frequencySort1("Aabb").c_str() << endl;
    return 0;
}