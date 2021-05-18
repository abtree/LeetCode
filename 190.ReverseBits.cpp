#include <iostream>
#include <bitset>
#include <string>
using namespace std;

//190. 颠倒二进制位
class ReverseBits
{
    /* 颠倒给定的 32 位无符号整数的二进制位。
    进阶:如果多次调用这个函数，你将如何优化你的算法？
    */
private:
    union UBitUint32 {
        struct {
            uint32_t bit1 : 1;
            uint32_t bit2 : 1;
            uint32_t bit3 : 1;
            uint32_t bit4 : 1;
            uint32_t bit5 : 1;
            uint32_t bit6 : 1;
            uint32_t bit7 : 1;
            uint32_t bit8 : 1;
            uint32_t bit9 : 1;
            uint32_t bit10 : 1;
            uint32_t bit11 : 1;
            uint32_t bit12 : 1;
            uint32_t bit13 : 1;
            uint32_t bit14 : 1;
            uint32_t bit15 : 1;
            uint32_t bit16 : 1;
            uint32_t bit17 : 1;
            uint32_t bit18 : 1;
            uint32_t bit19 : 1;
            uint32_t bit20 : 1;
            uint32_t bit21 : 1;
            uint32_t bit22 : 1;
            uint32_t bit23 : 1;
            uint32_t bit24 : 1;
            uint32_t bit25 : 1;
            uint32_t bit26 : 1;
            uint32_t bit27 : 1;
            uint32_t bit28 : 1;
            uint32_t bit29 : 1;
            uint32_t bit30 : 1;
            uint32_t bit31 : 1;
            uint32_t bit32 : 1;
        } mAttrs;
        uint32_t mValue{};
    };
public:
    uint32_t reverseBits(uint32_t n) {
        UBitUint32 val;
        val.mValue = n;
        UBitUint32 ret;
        ret.mAttrs.bit32 = val.mAttrs.bit1;
        ret.mAttrs.bit31 = val.mAttrs.bit2;
        ret.mAttrs.bit30 = val.mAttrs.bit3;
        ret.mAttrs.bit29 = val.mAttrs.bit4;
        ret.mAttrs.bit28 = val.mAttrs.bit5;
        ret.mAttrs.bit27 = val.mAttrs.bit6;
        ret.mAttrs.bit26 = val.mAttrs.bit7;
        ret.mAttrs.bit25 = val.mAttrs.bit8;
        ret.mAttrs.bit24 = val.mAttrs.bit9;
        ret.mAttrs.bit23 = val.mAttrs.bit10;
        ret.mAttrs.bit22 = val.mAttrs.bit11;
        ret.mAttrs.bit21 = val.mAttrs.bit12;
        ret.mAttrs.bit20 = val.mAttrs.bit13;
        ret.mAttrs.bit19 = val.mAttrs.bit14;
        ret.mAttrs.bit18 = val.mAttrs.bit15;
        ret.mAttrs.bit17 = val.mAttrs.bit16;
        ret.mAttrs.bit16 = val.mAttrs.bit17;
        ret.mAttrs.bit15 = val.mAttrs.bit18;
        ret.mAttrs.bit14 = val.mAttrs.bit19;
        ret.mAttrs.bit13 = val.mAttrs.bit20;
        ret.mAttrs.bit12 = val.mAttrs.bit21;
        ret.mAttrs.bit11 = val.mAttrs.bit22;
        ret.mAttrs.bit10 = val.mAttrs.bit23;
        ret.mAttrs.bit9 = val.mAttrs.bit24;
        ret.mAttrs.bit8 = val.mAttrs.bit25;
        ret.mAttrs.bit7 = val.mAttrs.bit26;
        ret.mAttrs.bit6 = val.mAttrs.bit27;
        ret.mAttrs.bit5 = val.mAttrs.bit28;
        ret.mAttrs.bit4 = val.mAttrs.bit29;
        ret.mAttrs.bit3 = val.mAttrs.bit30;
        ret.mAttrs.bit2 = val.mAttrs.bit31;
        ret.mAttrs.bit1 = val.mAttrs.bit32;
        return ret.mValue;
    }
public:
    uint32_t reverseBits2(uint32_t n) {
        bitset<32> bc(n);
        string str = bc.to_string();
        reverse(str.begin(), str.end());
        bitset<32> ac(str);
        return ac.to_ulong();
    }
public:
    uint32_t reverseBits3(uint32_t n) {
        uint32_t val = 0;
        for (int i = 0;i < 32 && n > 0; ++i) {
            val |= (n & 1) << (31 - i);
            n >>= 1;
        }
        return val;
    }
public:
    uint32_t reverseBits4(uint32_t n) {
        //位运算分治法
        n = n >> 1 & M1 | (n & M1) << 1;
        n = n >> 2 & M2 | (n & M2) << 2;
        n = n >> 4 & M4 | (n & M4) << 4;
        n = n >> 8 & M8 | (n & M8) << 8;
        return n >> 16 | n << 16;
    }
private:
    const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
    const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
    const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
    const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111
};

int main(int argc, char const* argv[])
{
    ReverseBits cls;
    cout << cls.reverseBits4(4294967293) << " -> 3221225471" << endl;
    cout << cls.reverseBits4(43261596) << " -> 964176192" << endl;
    return 0;
}
