#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//306. 累加数
class AdditiveNumber {
    /*累加数是一个字符串，组成它的数字可以形成累加序列。一个有效的累加序列必须至少包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。给定一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是累加数。
    说明: 累加序列里的数不会以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。
    */
public:
    bool isAdditiveNumber(string num) {
        if (num.size() < 3)
            return false;
        string tmp(num.size(), '0');
        int posx = 0;
        int n = num.size() / 2 + 1; //第一个剪枝
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < num.size(); ++j) {
                if(j > i+1 && num[i+1] == '0'){  //去除以‘0’开始的数(除0外)
                    reset(tmp, posx);
                    break;
                }
                copy(tmp, num, i); //确定第一个数
                posx = i;
                posx = addTwoString(tmp, num, posx, i, j);    //确定第二个数
                if(num.size()-j <= posx){   //第二个剪枝
                    reset(tmp, posx);
                    break;
                }
                int k = j + 1;
                bool suc = true;
                int start = i;
                if (k >= num.size()) {
                    suc = false;
                }
                while (k < num.size()) {
                    if (!compare(tmp, num, posx, k)) {
                        suc = false;
                        break;
                    }
                    int op = posx;  //这里需要注意：因为posx可能变大 所以需要备份原来的posx
                    posx = addTwoString(tmp, num, posx, start, k - 1);
                    start = k - 1;
                    k += op + 1;
                }
                if (suc) {
                    return true;
                }
                //重置
                reset(tmp, posx);
            }
        }
        return false;
    }
private:
    void copy(string& tmp, string& num, int posx) {
        int i = 0;
        while (posx >= 0) {
            tmp[i] = num[posx];
            --posx;
            ++i;
        }
    }
    int addTwoString(string& tmp, string& num, int posx, int i, int j) {
        int k = 0;
        while (j > i) {
            tmp[k] += (num[j] - '0');
            if (tmp[k] > '9') {
                tmp[k] -= 10;
                tmp[k + 1] += 1;
            }
            --j;
            ++k;
        }
        if(k <= posx)
            return posx;
        if (tmp[k] > '0')
            return k;
        return k - 1;
    }
    bool compare(string& tmp, string& num, int posx, int k) {
        if (num.size() - k <= posx) {
            return false;
        }
        while (posx >= 0) {
            if (tmp[posx] != num[k])
                return false;
            ++k;
            --posx;
        }
        return true;
    }
    void reset(string& tmp, int posx) {
        while (posx >= 0) {
            tmp[posx] = '0';
            --posx;
        }
    }
};

int main(int argc, char const* argv[]) {
    AdditiveNumber cls;
    cout << boolalpha << cls.isAdditiveNumber("111122335588143") << " -> true" << endl; 
    cout << boolalpha << cls.isAdditiveNumber("199001200") << " -> false" << endl; 
    cout << boolalpha << cls.isAdditiveNumber("199111992") << " -> true" << endl; 
    cout << boolalpha << cls.isAdditiveNumber("199100199") << " -> true" << endl;
    cout << boolalpha << cls.isAdditiveNumber("10") << " -> false" << endl;
    cout << boolalpha << cls.isAdditiveNumber("112358") << " -> true" << endl;
    cout << boolalpha << cls.isAdditiveNumber("111") << " -> false" << endl;  
    cout << boolalpha << cls.isAdditiveNumber("111222333555888") << " -> true" << endl;  
    return 0;
}