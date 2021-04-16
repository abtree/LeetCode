#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

// 127. 单词接龙
class WordLadder {
    /*字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列：序列中第一个单词是 beginWord 。序列中最后一个单词是 endWord 。每次转换只能改变一个字母。转换过程中的中间单词必须是字典 wordList 中的单词。给你两个单词 beginWord 和 endWord 和一个字典 wordList ，找到从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0。
    */
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /* 在126的基础上改进得
        */
        wordToId.clear();
        tope.clear();
        //给单词编号(主要为了提高性能)
        int i = 0;
        for(auto &it : wordList){
            if(wordToId.find(it) != wordToId.end())
                continue;
            wordToId[it] = i;
            ++i;
        }
        if(wordToId.find(endWord) == wordToId.end())
            return 0;
        if(wordToId.find(beginWord) == wordToId.end()){
            wordToId[beginWord] = i;
        }
        //构建图
        tope.resize(i+1);
        for(auto it = wordToId.begin(); it != wordToId.end(); ++it){
            auto it1 = it;
            for(++it1; it1 != wordToId.end(); ++it1){
                if(isVaild(it->first, it1->first)){
                    tope[it->second].push_back(it1->second);
                    tope[it1->second].push_back(it->second);
                }
            }
        }
        //修建图 并设置每一个单词的最小层数
        return countLayers(wordToId[beginWord], wordToId[endWord]);
    }
private:
    //找到目标单词出现的层数，并标记路过的单词最早出现的层数
    int countLayers(int start, int end){
        queue<int> q;
        q.push(start); 
        int layer = 1;
        layers[start] = 1;
        while(!q.empty()){
            ++layer;
            int size = q.size();
            for(int i =0;i< size;++i){
                int cur = q.front();
                q.pop();
                auto& cut = tope[cur];
                for(int j : cut){
                    if(j == end)
                        return layer;
                    if(layers[j] == 0){
                        layers[j] = layer;
                        q.push(j);
                    }
                } 
            }
        }
        return 0;
    }
    //判断两个单词只差一个字符
    bool isVaild(const string &left, const string &right){
        int size = left.size();
        if(size != right.size())
            return false;
        int d = 0;
        for(int i =0;i< size;++i){
            if(left[i] != right[i])
                ++d;
        }
        return d == 1;
    }
private:
    unordered_map<string, int> wordToId;    //单词与索引的转换
    vector<vector<int>> tope;   //图
    unordered_map<int, int> layers;
public:
    int ladderLength1(string beginWord, string endWord, vector<string>& wordList) {
        //双向BFS
        unordered_set<string> begin, end, visit; 
        unordered_set<string> worddict(wordList.begin(), wordList.end()); //将字典转为set方便查找
        
        if (worddict.find(endWord) == worddict.end()) return 0;

        //初始化
        int ans = 1;
        begin.insert(beginWord); //从开始端搜索
        end.insert(endWord); //从结束端搜索

        //两个集合不为空
        while(!begin.empty() && !end.empty()) {
            if (begin.size() > end.size()) {
                swap(begin, end);             //交替进行搜索
            }
            unordered_set<string> temp;
            //标准的bfs
            for (string s : begin) {
                for (int j = 0; j < s.size(); j++) {
                    char old = s[j];
                    for (char new_char = 'a'; new_char <= 'z'; new_char++) {
                        s[j] = new_char;
                        if (end.find(s) != end.end()) {
                            return ++ans;   //如果在结束端发现了该值，说明二者相遇
                        }

                        if (worddict.find(s) != worddict.end() && visit.find(s) == visit.end()) {
                            temp.insert(s);
                            visit.insert(s);
                            worddict.erase(s);
                        }
                    }
                    s[j] = old;
                }
            }
            begin = temp; //更新队列
            ans ++;  //跟新步长
        }
        return 0;
    }
};

int main(int argc, char const* argv[])
{
    WordLadder cls;
    cout << cls.ladderLength1("hit", "cog", vector<string>{"hot","dot","dog","lot","log","cog"}) << " -> 5" << endl;
    cout << cls.ladderLength1("hit", "cog", vector<string>{"hot","dot","dog","lot","log"}) << " -> 0" << endl;

    cout << cls.ladderLength1("cet", "ism", vector<string>{"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"}) << " -> 11" << endl;
    return 0;
}
