#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class StrongPasswordChecker{
public:
    int strongPasswordChecker(string password) {
        int size = password.size();
        int lack = 0;
        if (size < 6) {
            lack = 6 - size;
        }
        else if(size > 20) {
            lack = 20 - size;   //这里是负数
        }
        else {
            lack = 0;
        }
        //先统计个数
        vector<pair<char, int>> cnts;
        vector<int> typs(3, 0);    //type 0 小写字母 1 大写字母 2 数字
        cnts.push_back({ password[0], 1 });
        typcr(password[0], typs, 1);
        for (int i = 1; i < size;++i) {
            char c = password[i];
            typcr(c, typs, 1);
            if (password[i - 1] == c) {
                cnts.back().second += 1;
            }
            else {
                cnts.push_back({ c, 1 });
            }
        }
        //如果需要删除
        int add = lack < 0 ? -lack : 0;   
        while (lack < 0) {
            int biggest = 0;
            //优先删除3的倍数的部分
            for (auto& it : cnts) {
                if (it.second > 0 && it.second % 3 == 0) {
                    it.second -= 1;
                    typcr(it.first, typs, -1);
                    lack += 1;
                    if (lack >= 0)
                        break;
                }
                biggest = max(biggest, it.second);
            }
            if (lack < 0) {
                //如果有数量大于等于3的 优先删除数量大于等于3的
                if (biggest > 3) {
                    bool gonext = true;
                    //优先删除余数为1的
                    for (auto& it : cnts) {
                        if (it.second > 2 && it.second % 3 == 1) {
                            typcr(it.first, typs, -1);
                            it.second -= 1;
                            lack += 1;
                            gonext = false;
                            break;
                        }
                    }
                    if (gonext) {
                        //没有余数为1的 再删除余数为2的
                        for (auto& it : cnts) {
                            if (it.second > 2 && it.second % 3 == 2) {
                                typcr(it.first, typs, -1);
                                it.second -= 1;
                                lack += 1;
                                break;
                            }
                        }
                    }
                }
                else {
                    for (auto& it : cnts) {
                        if (it.second > 0 && typcnt(it.first, typs) > 1) {
                            typcr(it.first, typs, -1);
                            it.second -= 1;
                            lack += 1;
                            break;
                        }
                    }
                } 
            }
        }
        //找出需要替换的个数
        int repeat = 0;
        for (auto& it : cnts) {
            repeat += it.second / 3;
        }
        //找出需要补充的类型
        int typ = 0;
        for (auto cnt : typs) {
            if (cnt == 0)
                typ += 1;
        }
        return max(lack, max(repeat, typ)) + add;
    }
private:
    void typcr(char c, vector<int>& typs, int val) {
        if (c >= 'a' && c <= 'z') {
            typs[0] += val;
        }else if (c >= 'A' && c <= 'Z') {
            typs[1] += val;
        }else {
            typs[2] += val;
        }
    }
    int typcnt(char c, vector<int>& typs) {
        if (c >= 'a' && c <= 'z') {
            return typs[0];
        }else if (c >= 'A' && c <= 'Z') {
            return typs[1];
        }else {
            return typs[2];
        }
    }
};

int main(int argc, char const* argv[]) {
    StrongPasswordChecker cls;
    cout << cls.strongPasswordChecker("aaaaabbbb1234567890ABA") << " -> 3" << endl;
    cout << cls.strongPasswordChecker("1Abababcaaaabababababa") << " -> 2" << endl;
    cout << cls.strongPasswordChecker("FFFFFFFFFFFFFFF11111111111111111111AAA") << " -> 23" << endl;
    cout << cls.strongPasswordChecker("bbaaaaaaaaaaaaaaacccccc") << " -> 8" << endl;
    cout << cls.strongPasswordChecker("a") << " -> 5" << endl;
    cout << cls.strongPasswordChecker("aA1") << " -> 3" << endl;
    cout << cls.strongPasswordChecker("1337C0d3") << " -> 0" << endl;
    cout << cls.strongPasswordChecker("ABABABABABABABABABAB1") << " -> 2" << endl;
    return 0;
}
