#include <iostream>
using namespace std;

bool isBadVersion(int version) {
    return version >= 4;
}

//278. 第一个错误的版本
class FirstBadVersion {
    /* 由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。 
    假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。
    你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。
    */
public:
    int firstBadVersion(int n) {
        int start = 0;
        int end = n;
        while(start < end){
            int mid = (end - start)/2 + start;
            if (isBadVersion(mid)){
                end = mid;
            }else{
                start = mid+1;
            }
        }
        return start;
    }
};

int main(int argc, char const* argv[]) {
    FirstBadVersion cls;
    cout << cls.firstBadVersion(5) << "->4"<<endl;
    return 0;
}
