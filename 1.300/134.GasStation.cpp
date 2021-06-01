#include <iostream>
#include <vector>

using namespace std;

//134. 加油站
class GasStation
{
    /*在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
    说明: 
    如果题目有解，该答案即为唯一答案。输入数组均为非空数组，且长度相同。输入数组中的元素均为非负数。
    */
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0;
        while(i < gas.size()){
            int ret = cancircuit(gas, cost, i);
            if(ret < 0)
                return - 1;
            else if(ret == 0)
                return i;
            else
                i = ret;
        }
        return -1;
    }
private:
    int cancircuit(vector<int>& gas, vector<int>& cost, int start){
        int totalGet = 0;
        int totalUse = 0;
        int end = start;
        do{
            totalGet += gas[start];
            totalUse += cost[start];
            if(totalGet < totalUse){
                if(start < end)
                    return -1;
                else
                    return start+1;
            }  
            else{
                if(start + 1 >= gas.size()){
                    start = 0;
                }else{
                    ++start;
                }
            }
        }while(start != end);
        return 0;
    }
public:
    int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;
            while (cnt < n) {
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas) {
                    break;
                }
                cnt++;
            }
            if (cnt == n) {
                return i;
            } else {
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};

int main(int argc, char const* argv[])
{
    GasStation cls;
    cout << cls.canCompleteCircuit(vector<int>{5,8,2,8}, vector<int>{6,5,6,6}) << " -> 3" << endl;
    cout << cls.canCompleteCircuit(vector<int>{1,2,3,4,5}, vector<int>{3,4,5,1,2}) << " -> 3" << endl;
    cout << cls.canCompleteCircuit(vector<int>{2,3,4}, vector<int>{3,4,3}) << " -> -1" << endl;
    return 0;
}
