#include <iostream>
#include <string>
using namespace std;

class ValidateIPAddress{
public:
    string validIPAddress(string queryIP) {
        int last = -1;
        if(queryIP.find('.') != queryIP.npos){
            //IPv4
            for (int i =0;i<4;++i){
                int cur = (i==3?queryIP.size():queryIP.find('.', last+1));
                if(cur == queryIP.npos){
                    return "Neither";
                }
                if (cur - last-1 < 1 || cur-last-1 > 3){
                    return "Neither";
                }
                int addr = 0;
                for(int j =last+1;j<cur;++j){
                    if(!isdigit(queryIP[j])){
                        return "Neither";
                    }
                    addr = addr*10 +(queryIP[j] - '0');
                }
                if(addr > 255){
                    return "Neither";
                }
                if(addr > 0 && queryIP[last+1] == '0'){
                    return "Neither";
                }
                if(addr == 0 && cur-last-1 > 1){
                    return "Neither";
                }
                last = cur;
            }
            return "IPv4";
        }else{
            //IPv6
            for(int i =0;i<8;++i){
                int cur = (i==7?queryIP.size():queryIP.find(':', last+1));
                if (cur == queryIP.npos){
                    return "Neither";
                }
                if(cur-last-1<1 || cur-last-1>4){
                    return "Neither";
                }
                for(int j = last+1;j<cur;++j){
                    if(!isdigit(queryIP[j]) && (tolower(queryIP[j]) < 'a' || towlower(queryIP[j]) > 'f')){
                        return "Neither";
                    }
                }
                last = cur;
            }
            return "IPv6";
        }
    }
};

int main(){
    ValidateIPAddress cls;
    cout << cls.validIPAddress("172.16.254.1") << " -> IPv4" << endl; 
    cout << cls.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334") << " -> IPv6" << endl; 
    cout << cls.validIPAddress("256.256.256.256") << " -> Neither" << endl; 
    cout << cls.validIPAddress("2001:0db8:85a3::8A2E:037j:7334") << " -> Neither" << endl; 
    cout << cls.validIPAddress("02001:0db8:85a3:0000:0000:8a2e:0370:7334") << " -> Neither" << endl; 
    return 0;
}
