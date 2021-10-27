#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Data{
    int layer{};
    int maxsize{};
    bool isfile{};
};

class LongestAbsoluteFilePath{
public:
    int lengthLongestPath(string input) {
        stringstream ss(input);
        char buff[256];
        vector<Data> vec;
        while(ss.getline(buff, 256)){
            Data dat;
            for(int i = 0;i < 256;++i){
                if(buff[i] == '\0')
                    break;
                if(buff[i] == '\t')
                    dat.layer+=1;
                else{
                    dat.maxsize+=1;
                    if(buff[i] == '.')
                        dat.isfile = true;
                }
            }
            if(!dat.isfile){
                dat.maxsize+=1; //文件夹需要加上'/'
            }
            for(int i = vec.size()-1; i >= 0;--i){
                if(vec[i].layer == dat.layer-1){
                    dat.maxsize += vec[i].maxsize;
                    break;
                }
            }
            vec.push_back(std::move(dat));
        }
        int max = 0;
        for(auto &x : vec){
            if (x.isfile && x.maxsize > max)
                max = x.maxsize;
        }
        return max;
    }
};

int main(int argc, char const *argv[]){
    LongestAbsoluteFilePath cls;
    cout << cls.lengthLongestPath("a\n\tb1\n\t\tf1.txt\n\taaaaa\n\t\tf2.txt") << " -> 14" << endl;
    cout << cls.lengthLongestPath("a") << " -> 0" << endl;
    cout << cls.lengthLongestPath("a\n\tsubdir1") << " -> 0" << endl;
    cout << cls.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << " -> 32" << endl;
    cout << cls.lengthLongestPath("file1.txt\nfile2.txt\nlongfile.txt") << " -> 12" << endl;
    return 0;
}
