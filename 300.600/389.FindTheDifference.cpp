#include <iostream>
#include <array>
#include <string>
using namespace std;

class FindTheDifference{
public:
    char findTheDifference(string s, string t) {
        array<int, 26> used{};
        for(char c : s){
            used[c-'a']+=1;
        }
        for(char c: t){
            if(used[c-'a'] == 0)
                return c; 
            used[c-'a']-=1;   
        }
        return t.back();
    }
    char findTheDifference1(string s, string t) {
        //异或
        char x = 0;
        for(char c : s){
            x ^= c;
        }
        for(char c: t){
            x ^= c;
        }
        return x;
    }
};

int main(int argc, char const *argv[]){
    FindTheDifference cls;
    cout << cls.findTheDifference1("xpmssbwloowxibtwvhabflaoqgoyswznxepaoevvqohhamkucbcfsonazfnmcoqechnyigsbuvzrligprykurwahetwjmdknmearurflryhligaptsdqrlgapoyzocwwnavcsdiuqpbzmedzsvifcqzjjqqjshqmxczobymhwwiojfcvfjvaygupgacyvhnckmdasgspxoijltxebfspwlpjbzpoonalwujttowlsiagmcgfqwxoznuehztvuvpgzrvrjnybfcolufwgwsgmuxdqfgcisxgeibinqxacrtwznwvmxximhhhdehxrftpcczubiabgkbscrundidaqzcbmzpiqecfruiffzuajxjnnwipeivtswffizywisuvhkkcjwgxazntusebfbaawflsazleudgmhyzgfspyqmqanozvksrougiypcmiokgdhmkwyngmrynkekfjogjpgannxdtczvgxmatirlfcsphzouosyknxigetrpzudjaxcepvdfmqfyjpvxifntszpbzfkrlxgodjecpvtljolottyhaonpvatwhynicfusbrcnfhkpglaouhmljaavvguoiyiynpqykhaqsbbdroszpawpzgjtnzmqeiuvbwhyphrhqzbaqnnusbiopkzbsovqtykfioyurtqqnspkhnllmsvkgewpslshrambdokxhrelsehvvgitcwyrhivarxjagtsgfnhudizcbmvncgjfa", "wsxqlutrifhyejgmohyvlkjobelupizpgbgavnltzspgvmthdhioonnilqshpsvyejddnitnxrpmdvkudqhoajzupcxrwghhyhudsqrszojzwpcbontwdbfbqncysqzgoayjxbqkieamizzsoaqksqwjmjawwmkltcfzffruhaarhcexhenrgizwvnqfkrfhthbovxuynxoltrtagsceiiphsombaqcztfookpepwymnsxtlspgbdkmyezlzdvinemwibvsggnyfoabsfqxtgzecfiwpyqzsiilnrmugnbczsouczgfmkhunqfhpzqgyurrzpqccmvfjnbwgwrlclnvvsgbhkdfipnsinmasvryegdzuiazoisrcbgpyohvhvpujjxxtoruxpomxmjwuockcwjgpnhlfojvapaxnablqhujdtsofuiapfcjcdvxsavkavmrptqptpnxaasazuolwcltbysmezytwvmzislbasghogaqhhjqryzmbubsewcyustwguyiyvgswcefbpgrzjgvwezzmzfatatksonevbcupwtoxcjxaivqxciuklycbacoonuvvmuaazmrgguiuzyrhjbipwjpurofecklonpldgofikgijfiknaqisrmxfnvlqbwwifykjogtdqocdpffetagavwrchfiskwwecmrhhnpvlifaxkhbdapyafighonnxeamgpqnazvsnkbzrdcwyfyssseagfhlixn") << " -> s" << endl;
    cout << cls.findTheDifference1("", "y") << " -> y" << endl;
    cout << cls.findTheDifference1("a", "aa") << " -> a" << endl;
    cout << cls.findTheDifference1("ae", "aea") << " -> a" << endl;
    return 0;
}
