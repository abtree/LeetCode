#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//166. 分数到小数
class FractionToRecurringDecimal
{
    /* 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。如果小数部分为循环小数，则将循环的部分括在括号内。如果存在多个答案，只需返回 任意一个 。
    */
public:
    string fractionToDecimal(int numerator, int denominator) {
        //先处理整数部分
        long long num = numerator;
        long long den = denominator;
        long long head = num/den;
        num %= den;
        string ret = to_string(head);
        if(num == 0)
            return ret; //没有小数部分
        ret.push_back('.');
        //特殊处理整数部分为0的情况
        if(head == 0){
            if(num > 0 && den < 0)
                ret = "-" + ret;
            else if(num < 0 && den > 0)
                ret = "-" + ret;
        }
        //再处理小数部分
        num = abs(num);
        den = abs(den);
        unordered_map<long long, int> his;
        his[num] = 0;
        string dec = "";
        int rep = -1;
        while (num != 0)
        {
            num *= 10;
            dec += to_string(num / den);
            num %= den;
            if(his.find(num) != his.end()){
                //重复了
                rep = his[num];
                break;
            }
            his[num] = dec.size();
        }
        
        if(rep >=0 ){
            //处理循环
            ret.resize(ret.size() + dec.size() + 2);
            int j = 0;
            while(ret[j] != '.'){
                ++j;
            }
            ++j;
            for(int i = 0; i< dec.size(); ++i){
                if(i == rep){
                    ret[j] = '(';
                    ++j;
                }
                ret[j] = dec[i];
                ++j;
            }
            ret[j] = ')';
        }else{
            //没有循环
            ret += dec;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    FractionToRecurringDecimal cls;
    cout << cls.fractionToDecimal(-2147483648, -1).c_str() << " -> 2147483648" << endl;
    cout << cls.fractionToDecimal(-1,-2147483648).c_str() << " -> 0.0000000004656612873077392578125" << endl;
    cout << cls.fractionToDecimal(7,-12).c_str() << " -> -0.58(3)" << endl;
    cout << cls.fractionToDecimal(-50,8).c_str() << " -> -6.25" << endl;
    cout << cls.fractionToDecimal(1,6).c_str() << " -> 0.1(6)" << endl;
    cout << cls.fractionToDecimal(1,2).c_str() << " -> 0.5" << endl;
    cout << cls.fractionToDecimal(2,1).c_str() << " -> 2" << endl;
    cout << cls.fractionToDecimal(2,3).c_str() << " -> 0.(6)" << endl;
    cout << cls.fractionToDecimal(4,333).c_str() << " -> 0.(012)" << endl;
    cout << cls.fractionToDecimal(1,5).c_str() << " -> 0.2" << endl;
    return 0;
}
