#include <iostream>
#include <string>

using namespace std;

//165. 比较版本号
class CompareVersionNumbers
{
    /*给你两个版本号 version1 和 version2 ，请你比较它们。版本号由一个或多个修订号组成，各修订号由一个 '.' 连接。每个修订号由 多位数字 组成，可能包含 前导零 。每个版本号至少包含一个字符。修订号从左到右编号，下标从 0 开始，最左边的修订号下标为 0 ，下一个修订号下标为 1 ，以此类推。例如，2.5.33 和 0.1 都是有效的版本号。
    比较版本号时，请按从左到右的顺序依次比较它们的修订号。比较修订号时，只需比较 忽略任何前导零后的整数值 。也就是说，修订号 1 和修订号 001 相等 。如果版本号没有指定某个下标处的修订号，则该修订号视为 0 。例如，版本 1.0 小于版本 1.1 ，因为它们下标为 0 的修订号相同，而下标为 1 的修订号分别为 0 和 1 ，0 < 1 。
    返回规则如下：
    如果 version1 > version2 返回 1，
    如果 version1 < version2 返回 -1，
    除此之外返回 0。
    */
public:
    int compareVersion(string version1, string version2) {
        int l = 0,r = 0;
        int i = 0, j = 0;
        while(true){
            if(i >= version1.size() && j >= version2.size())
                break;
            while(i < version1.size()){
                if(version1[i] == '.')
                    break;
                l = l * 10 + (version1[i] - '0');
                ++i;
            }
            while(j < version2.size()){
                if(version2[j] == '.')
                    break;
                r = r * 10 + (version2[j] - '0');
                ++j;
            }
            if(l > r)
                return 1;
            else if(l < r)
                return -1;
            ++i;
            ++j;
            l = r = 0;
        }
        return 0;
    }
};

int main(int argc, char const* argv[])
{
    CompareVersionNumbers cls;
    cout << cls.compareVersion("1.01", "1.001") << " -> 0" <<endl;
    cout << cls.compareVersion("1.0", "1.0.0") << " -> 0" <<endl;
    cout << cls.compareVersion("0.1", "1.1") << " -> -1" <<endl;
    cout << cls.compareVersion("1.0.1", "1") << " -> 1" <<endl;
    cout << cls.compareVersion("7.5.2.4", "7.5.3") << " -> -1" <<endl;
    return 0;
}
