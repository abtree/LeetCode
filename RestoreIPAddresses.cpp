#include <iostream>
#include <vector>
#include <string>

using namespace std;

//93. 复原 IP 地址
class RestoreIPAddresses
{
    /*
    给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。

    示例 1：
    输入：s = "25525511135"
    输出：["255.255.11.135","255.255.111.35"]

    示例 2：
    输入：s = "0000"
    输出：["0.0.0.0"]

    示例 3：
    输入：s = "1111"
    输出：["1.1.1.1"]

    示例 4：
    输入：s = "010010"
    输出：["0.10.0.10","0.100.1.0"]

    示例 5：
    输入：s = "101023"
    输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
    */
public:
    vector<string> restoreIpAddresses(string s) {
        segs.resize(SEG_CNT);
        check(s, 0, 0);
        return ans;
    }
private:
    void check(string& s, int seg, int pos){
        //seg已经到最后了
        if(seg == SEG_CNT){
            if(pos == s.size()){
                //满足条件
                string ip = "";
                for(auto i : segs){
                    ip += to_string(i)+'.';
                }
                ip.pop_back();
                ans.push_back(std::move(ip));
            }else{
                return; //不满足条件
            }
        }
        if(pos == s.size())
            return; //已经没有可分配的数字了
        if(s[pos] == '0'){
            segs[seg] = 0;
            check(s, seg+1, pos+1);
            return; //这段只能是0
        }
        int sec = 0;
        for(int c = pos; c < pos+3 && c < s.size();++c){    //常规情况 最多向后验证3位
            sec = sec*10 + (s[c]-'0');
            if(sec <= 0xFF){
                segs[seg] = sec;
                check(s, seg+1, c+1);
            }
        }
    }
public:
    void Clear(){
        ans.clear();
    }
private:
    static constexpr int SEG_CNT = 4; //ip地址的段数
    vector<int> segs;   //存放每一段ip的值
    vector<string> ans; //存放答案(满足条件的Ip)
};

int main(int argc, char const* argv[])
{
    RestoreIPAddresses cls;
    auto& ret = cls.restoreIpAddresses("25525511135");
    cout << "[";
    for(auto &it : ret){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;
    cls.Clear();

    auto& ret1 = cls.restoreIpAddresses("0000");
    cout << "[";
    for(auto &it : ret1){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;
    cls.Clear();

    auto& ret2 = cls.restoreIpAddresses("1111");
    cout << "[";
    for(auto &it : ret2){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;
    cls.Clear();

    auto& ret3 = cls.restoreIpAddresses("010010");
    cout << "[";
    for(auto &it : ret3){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;
    cls.Clear();

    auto& ret4 = cls.restoreIpAddresses("101023");
    cout << "[";
    for(auto &it : ret4){
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;
    cls.Clear();

    return 0;
}
