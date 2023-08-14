#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class CountTheRepetitions{
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if(n1 == 0){
            return 0;
        }
        /*  s1cnt 记录当前用掉的s1个数
            s2cnt 记录当前完整匹配到的s2个数
            index 记录除s2cnt个完整匹配的s2外 还额外匹配的s2长度
        */
        int s1cnt =0,index = 0,s2cnt=0;
        /* 记录每匹配一次s1匹配的s2的总个数,如果出现index相同的情况，即找到了循环
           由于每匹配一个s1，s2的起始index都不同，所以每次结束的index也可能不同
        */
        unordered_map<int, pair<int, int>> recall;
        /* pre_loop 是循环之前用掉的s1cnt和匹配到的s2cnt
           in_loop 是循环中的s1cnt和s2cnt
        如 0.765123123123... 0.765为pre_loop后面循环的123为in_loop
        */
        pair<int, int> pre_loop, in_loop;
        while (true){
            ++s1cnt;
            for(char ch : s1){
                if (ch == s2[index]){
                    ++index;
                    if(index == s2.size()){
                        ++s2cnt;
                        index = 0;
                    }
                }
            }
            //s1已经用完了 所以没有循环节
            if(s1cnt == n1){
                //直接当前匹配的完整s2个数 / 一个完整str2包含的s2个数
                return s2cnt/n2;
            }
            //找到了循环节
            if(recall.count(index)){
                auto prime = recall[index];
                pre_loop = prime;
                in_loop = {s1cnt- prime.first,s2cnt-prime.second};
                break;
            }else{
                recall[index]={s1cnt,s2cnt};
            }
        }
        // 进入循环前匹配的完整s2个数 + (总s1个数 - 进入循环前用掉的s1个数)/每次循环需要用的s1个数*每次循环完整匹配的s2个数
        int ans =pre_loop.second + (n1-pre_loop.first)/in_loop.first*in_loop.second;
        // 剩余还未匹配的s1 = (总s1个数 - 进入循环前用掉的s1个数) % 每次循环需要用的s1个数
        int rest = (n1-pre_loop.first) % in_loop.first;
        //计算最后剩余的s1还能匹配多少完整的s2
        for(int i =0;i<rest;++i){
            for(char ch : s1){
                if(ch==s2[index]){
                    ++index;
                    if(index == s2.size()){
                        ++ans;
                        index= 0;
                    }
                }
            }
        }
        return ans / n2;
    }
};

int main(){
    CountTheRepetitions cls;
    cout << cls.getMaxRepetitions("acb", 4, "ab", 2) << " -> 2" << endl;
    cout << cls.getMaxRepetitions("acb", 1, "acb", 1) << " -> 1" << endl;
    return 0;
}
