#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class ReconstructOriginalDigistsFromEnglish {
public:
    string originalDigits(string s) {
        /*
            数字中字母使用情况如下
            e   0,1,3,5,7,8,9
            f   4,5
            g   8
            h   3,8
            i   5,6,8,9
            n   1,7,9
            o   0,1,2,4
            r   0,3,4
            s   6,7
            t   2,3,8
            u   4
            v   5,7
            w   2
            x   6
            z   0
        由此可知：0出现的次数 == z出现的次数;
                 2出现的次数 == w出现的次数;
                 4出现的次数 == u出现的次数;
                 6出现的次数 == x出现的次数;
                 8出现的次数 == g出现的次数;
                 3出现的次数 == h出现的次数 - 8出现的次数
                 5出现的次数 == f出现的次数 - 4出现的次数
                 7出现的次数 == s出现的次数 - 6出现的次数
                 1出现的次数 == o出现的次数 - 0,2,4出现的次数
                 9出现的次数 == i出现的次数 - 5,6,8出现的次数
        */
        unordered_map<char, int> dp;
        for (char c : s) {
            dp[c] += 1;
        }
        vector<int> ret(10);
        ret[0] = dp['z'];
        ret[2] = dp['w'];
        ret[4] = dp['u'];
        ret[6] = dp['x'];
        ret[8] = dp['g'];
        ret[3] = dp['h']-ret[8];
        ret[5] = dp['f']-ret[4];
        ret[7] = dp['s']-ret[6];
        ret[1] = dp['o']-ret[0] -ret[2]-ret[4];
        ret[9] = dp['i'] - ret[5] - ret[6] - ret[8];
        string str = "";
        for (int i = 0; i < 10;++i) {
            if(ret[i] > 0)
                str.append(ret[i], i + '0');
        }
        return str;
    }
};

int main(int argc, char const* argv[]) {
    ReconstructOriginalDigistsFromEnglish cls;
    cout << cls.originalDigits("owoztneoer").c_str() << " -> 012" << endl;
    cout << cls.originalDigits("fviefuro").c_str() << " -> 45" << endl;
    return 0;
}
