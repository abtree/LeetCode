#include <iostream>
#include <vector>
using namespace std;

class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger(){

    }
    // Constructor initializes a single integer.
    NestedInteger(int value){
        mValue = value;
    }
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const{
        return mValue > 0;
    }
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const{
        return mValue;
    }
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value){
        mValue = value;
    }
    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni){
        mList.push_back(ni);
    }
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const{
        return mList;
    }
private:
    int mValue{};
    vector<NestedInteger> mList;
};

class MiniParser{
public:
    NestedInteger deserialize(string s) {
        if(s[0] == '['){
            NestedInteger ret;
            decode(s, ret, 1);
            return ret;
        }
        return NestedInteger(atoi(s.c_str()));
    }
private:
    int decode(string& s,NestedInteger& ret, int i){
        while(i < s.size()){
            if(s[i] == '['){
                ++i;
                NestedInteger ret1;
                i = decode(s, ret1, i);
                ret.add(ret1);
                continue;
            }
            if(s[i]==']'){
                ++i;
                return i;
            }
            if(s[i]==','){
                ++i;
                continue;
            }
            int x = 0;
            int flag = 1;
            if(s[i] == '-'){
                flag = -1;
                ++i;
            }
            while(s[i] >='0' && s[i]<='9'){
                x = x*10+(s[i]-'0');
                ++i;
            }
            ret.add(NestedInteger(flag*x));
        }
        return i;
    }
};

int main(int argc, char const *argv[]){
    MiniParser cls;
    auto ret0 = cls.deserialize("[123,456,[788,799,833],[[]],10,[]]");
    auto ret1 = cls.deserialize("123");
    auto ret2 = cls.deserialize("[123,[456,[789]]]");
    auto ret3 = cls.deserialize("[123,[456,789]]");
    auto ret4 = cls.deserialize("[123,[456,789],789]");
    return 0;
}
