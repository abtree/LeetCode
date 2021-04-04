#pragma once

//49. 字母异位词分组
class CGroupAnagrams {
    /*
    给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

    输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
    输出:
    [
        ["ate","eat","tea"],
        ["nat","tan"],
        ["bat"]
    ]

    说明：
        所有输入均为小写字母。
        不考虑答案输出的顺序。
    */
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> tmp;
        for (auto& it : strs) {
            string key = it;
            std::sort(key.begin(), key.end());  //排序后作为key
            tmp[key].push_back(it);
        }
        vector<vector<string>> ret;
        for (auto& it1 : tmp) {
            ret.push_back(std::move(it1.second));
        }
        return ret;
    }
public:
    static void Test() {
        vector<string> dat{ "eat", "tea", "tan", "ate", "nat", "bat" };
        CGroupAnagrams cls;
        auto ret = cls.groupAnagrams(dat);
        cout << "[" << endl;
        for (auto& it : ret) {
            cout << "[";
            for (auto& it2 : it) {
                cout << it2.c_str() << ",";
            }
            cout << "]" << endl;
        }
        cout << "]" << endl;
    }
};