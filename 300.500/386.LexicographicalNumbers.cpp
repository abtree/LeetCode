#include <iostream>
#include <vector>
using namespace std;

class LexicographicalNumbers{
public:
    vector<int> lexicalOrder(int n) {
        ret.clear();
        ret.resize(n, 0);
        end = n;
        pos = 0;
        for(int i = 1;i<10;++i){
            if(i>end)
                break;
            ret[pos++] = i;
            loop(i);
        }
        return ret;
    }
private:
    void loop(int b){
        b*=10;
        for(int i = 0; i<10;++i){
            if(b+i>end)
                break;
            ret[pos++]=b+i;
            loop(b+i);
        }
    }
private:
    vector<int> ret;
    int end{};
    int pos{};
};

int main(int argc, char const *argv[]){
    LexicographicalNumbers cls;
    auto& ret = cls.lexicalOrder(13);
    auto& ret1 = cls.lexicalOrder(2);
    auto& ret2 = cls.lexicalOrder(200);
    return 0;
}
