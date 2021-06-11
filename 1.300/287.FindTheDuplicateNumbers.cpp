#include <iostream>
#include <vector>

using namespace std;

// 287. 寻找重复数
class FindTheDuplicateNumbers
{
    /* 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设 nums 只有 一个重复的整数 ，找出 这个重复的数 。你设计的解决方案必须不修改数组 nums 且只用常量级 O(1) 的额外空间。
    */
public:
    int findDuplicate(vector<int>& nums) {
        //快慢指针法 （实际上是链表找环发）
        /*  如 ：值  1 3 4 2 2
                下标 0 1 2 3 4
                我们可以构造如下链表 0->1->3->2<->4 此时再2节点形成环 
                我们就可以通过找环法找到重复节点
        */
       int slow =0,fast = 0;
       do{
            slow = nums[slow];       //slow走一步
            fast = nums[nums[fast]];  //fast走两步
       }while(slow != fast);
       slow = 0;
       while(slow != fast){
           slow = nums[slow];   //slow走一步
           fast = nums[fast];    //fast走一步
       }
       return slow;
    }
public:
    int findDuplicate2(vector<int>& nums) {
        //二进制发
        int n = nums.size();
        //先确定最高位
        int bits = 31;
        while(!((n-1)>>bits)){  //这里最大可能的数字是n-1
            --bits;
        }
        //确定ret为1的位数
        int ret = 0;
        while(bits >= 0){
            int x = 0, y = 0;
            for(int i = 0; i< n;++i){
                if(nums[i] & (1 << bits)){  //统计 数组中 第bits位为1的个数
                    ++x;
                }
                if(i > 0 && (i & (1<<bits))){   //统计 1..n 第bits位为1的个数
                    ++y;
                }
            }
            if(x > y){
                ret |= (1 << bits); //满足这个表达式的 结果在这位为1（其余情况为0）
            }
            --bits;
        }
        return ret;
    }

public:
    int findDuplicate3(vector<int>& nums) {
        //二分查找
        /*  例： 数组:   1   2  3   4 2
                <=i的数:   1   3   4  5
            由此可见 从重复数开始 前面的都是 <= i;后面的都>=i
        */      
        int n = nums.size();
        int start = 0, end = n; 
        while(start < end){
            int mid = (start + end) >> 1;
            int cnt = 0;
            for(int i : nums){
                if(i <= mid){
                    ++cnt;
                }
            }
            if(cnt <= mid){
                start = mid+1;
            }else{
                end = mid;
            }
        }
        return start;
    }
};

int main(int argc, char const *argv[]){
    FindTheDuplicateNumbers cls;
    cout << cls.findDuplicate3(vector<int>{1,3,4,2,2}) << " -- "  << cls.findDuplicate(vector<int>{1,3,4,2,2}) << " -- " << cls.findDuplicate2(vector<int>{1,3,4,2,2}) << " -> 2" << endl;
    cout << cls.findDuplicate3(vector<int>{3,1,3,4,2}) << " -- "  << cls.findDuplicate(vector<int>{3,1,3,4,2}) << " -- " << cls.findDuplicate2(vector<int>{3,1,3,4,2}) << " -> 3" << endl;
    cout << cls.findDuplicate3(vector<int>{1,1}) << " -- "  << cls.findDuplicate(vector<int>{1,1}) << " -- " << cls.findDuplicate2(vector<int>{1,1}) << " -> 1" << endl;
    cout << cls.findDuplicate3(vector<int>{1,1,2}) << " -- "  << cls.findDuplicate(vector<int>{1,1,2}) << " -- " << cls.findDuplicate2(vector<int>{1,1,2}) << " -> 1" << endl;
    cout << cls.findDuplicate3(vector<int>{2,2,2,2,2}) << " -- "  << cls.findDuplicate(vector<int>{2,2,2,2,2}) << " -- " << cls.findDuplicate2(vector<int>{2,2,2,2,2}) << " -> 2" << endl;
    return 0;
}
