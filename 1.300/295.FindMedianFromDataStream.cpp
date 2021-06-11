#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <functional>
#include <set>
using namespace std;

// 295. 数据流的中位数
/* 中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
    例如，
    [2,3,4] 的中位数是 3
    [2,3] 的中位数是 (2 + 3) / 2 = 2.5
    设计一个支持以下两种操作的数据结构：
    void addNum(int num) - 从数据流中添加一个整数到数据结构中。
    double findMedian() - 返回目前所有元素的中位数。
*/
struct ListNode {
    int Val{};
    ListNode* Next{};
    ListNode(int v) :Val(v) {
    }
};

//链表(超时)
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    ~MedianFinder(){
        while (head){
            auto* p = head->Next;
            delete head;
            head = p;
        }
    }

    void addNum(int num) {
        ++size;
        ListNode* p = new ListNode(num);
        if (!head) {
            head = p;
            return;
        }
        if (p->Val > head->Val) {
            p->Next = head;
            head = p;
        }
        else {
            ListNode* q = head;
            ListNode* k = head->Next;
            while (k) {
                if (k->Val < p->Val) {
                    q->Next = p;
                    p->Next = k;
                }
                q = k;
                k = k->Next;
            }
            if(!k){
                q->Next = p;
            }
        }
    }

    double findMedian() {
        bool even = true;
        if(size & 1){
            even = false;
        }
        int i = (size-1)/2;
        auto *p = head;
        while(i > 0){
            p = p->Next;
            --i;
        } 
        i = p->Val;
        if(even){
            i+= p->Next->Val;
            return i / 2.0;
        } 
        return i;
    }
private:
    ListNode* head{};
    int size{};
};

//数组 排序(超时)
class MedianFinder2 {
public:
    /** initialize your data structure here. */
    MedianFinder2() {

    }

    void addNum(int num) {
        data.push_back(num);
    }

    double findMedian() {
        sort(data.begin(), data.end());
        int size = data.size();
        int pos = (size-1)>>1;
        double ret = data[pos];
        if((size & 1) == 0){
            ret += data[pos+1];
            ret /= 2.0;
        }
        return ret;
    }
private:
    vector<int> data;
};

//插入 排序法(300ms)
class MedianFinder3 {
public:
    /** initialize your data structure here. */
    MedianFinder3() {

    }

    void addNum(int num) {
        if(data.empty()){
            data.push_back(num);
        }else{
            data.insert(lower_bound(data.begin(), data.end(), num), num);
        }
    }

    double findMedian() {
        int size =data.size();
        int pos = (size-1)/2;
        double i = data[pos];
        if((size & 1) == 0){
            i += data[pos+1];
            i /= 2.0;
        }
        return i;
    }
private:
    deque<int> data;
};

//双堆算法(132ms)
class MedianFinder4 {
public:
    /** initialize your data structure here. */
    MedianFinder4() {

    }

    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        if(lo.size() < hi.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        if(lo.size() == hi.size()){
            return (lo.top()+hi.top()) / 2.0;
        }
        return lo.top();
    }
private:
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;
};

//模拟红黑树(208ms)
class MedianFinder5 {
public:
    /** initialize your data structure here. */
    MedianFinder5()
    :lo(data.end())
    ,hi(data.end()) {

    }

    void addNum(int num) {
        auto n = data.size();
        data.insert(num);
        if(!n){ //n == 0
            lo = data.begin();
            hi = data.begin();
        }else if(n & 1){    //奇数(插入后为偶数)
            if(num < *lo){  //插在前面
                lo--;
            }else{
                hi++;   //插在后面
            }
        }else{  //偶数(插入后为基数)
            if(num > *lo && num < *hi){ //插在 lo 和 hi 中间
                lo++;
                hi--;
            }else if(num >= *hi){   //插在后面 lo = hi
                lo++;
            }else{      //插在前面 hi = lo
                lo = --hi;  // insertion at end of equal range spoils lo
            }
        }
    }

    double findMedian() {
        return (*lo + *hi) * 0.5;
    }
private:
    multiset<int> data;
    multiset<int>::iterator lo,hi;
};

int main(int argc, char const *argv[])
{
    MedianFinder5 cls;
    cls.addNum(1);
    cls.addNum(2);
    cout << cls.findMedian() << "-> 1.5" << endl;
    cls.addNum(3);
    cout << cls.findMedian() << "-> 2" << endl;
    return 0;
}
