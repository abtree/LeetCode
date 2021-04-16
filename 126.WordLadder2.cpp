#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

// 126. 单词接龙 II
class WordLadder2 {
    /*
    给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：每次转换只能改变一个字母。转换后得到的单词必须是字典中的单词。

    说明:如果不存在这样的转换序列，返回一个空列表。所有单词具有相同的长度。所有单词只由小写字母组成。字典中不存在重复的单词。你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
    */
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        /* 通过构造图来寻找最短路径(会超时)
        */
        mRet.clear();
        wordToId.clear();
        idToWord.clear();
        tope.clear();
        //给单词编号(主要为了提高性能)
        int i = 0;
        for(auto &it : wordList){
            if(wordToId.find(it) != wordToId.end())
                continue;
            wordToId[it] = i;
            idToWord[i] = it;
            ++i;
        }
        if(wordToId.find(endWord) == wordToId.end())
            return mRet;
        if(wordToId.find(beginWord) == wordToId.end()){
            wordToId[beginWord] = i;
            idToWord[i] = beginWord;
        }
        maxSize = wordToId.size();
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
        //遍历图 查找最短路径
        int layer = 1;
        unordered_map<int, int> except;  //防止圈循环
        except[wordToId[beginWord]] = layer;
        vector<string> tmp;
        tmp.push_back(beginWord);
        road(wordToId[beginWord], except, tmp, endWord, layer+1);
        return mRet;
    } 
private:
    void road(int id, unordered_map<int, int>& except, vector<string>& tmp, string& endWord, int layer){
        if(layer > maxSize)
            return;
        auto& cur = tope[id];
        for(auto it : cur){
            if(except[it] > 0)
                continue;
            except[it] = layer;
        }
        for(auto it : cur){
            if(except[it] > 0 && except[it] < layer)
                continue;
            tmp.push_back(idToWord[it]);
            if(idToWord[it] == endWord){
                if(layer < maxSize){
                    mRet.clear();
                    maxSize = layer;
                }
                mRet.emplace_back(tmp.begin(), tmp.end());
                tmp.pop_back();
                return;
            }
            road(it, except, tmp, endWord, layer+1);
            tmp.pop_back();
        }
        for(auto it : cur){
            if(except[it] == layer)
                except[it] = 0;
        }
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
    vector<vector<string>> mRet;    //返回值
    unordered_map<string, int> wordToId;    //单词与索引的转换
    unordered_map<int, string> idToWord;    //索引与单词的转换
    vector<vector<int>> tope;   //图
    int maxSize{};  //最大深度(最少到达结束字符串的深度)
    unordered_map<int, int> layers;  //记录单词最早出现的层数，倒推路径时用
public:
    vector<vector<string>> findLadders1(string beginWord, string endWord, vector<string>& wordList) {
        /* 通过构造图来寻找最短路径(改进版)
           先确定至少在哪层可以找到结束字符串，在倒推路径
        */
        mRet.clear();
        wordToId.clear();
        idToWord.clear();
        tope.clear();
        layers.clear();
        //给单词编号(主要为了提高性能)
        int i = 0;
        for(auto &it : wordList){
            if(wordToId.find(it) != wordToId.end())
                continue;
            wordToId[it] = i;
            idToWord[i] = it;
            ++i;
        }
        if(wordToId.find(endWord) == wordToId.end())
            return mRet;
        if(wordToId.find(beginWord) == wordToId.end()){
            wordToId[beginWord] = i;
            idToWord[i] = beginWord;
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
        maxSize = countLayers(wordToId[beginWord], wordToId[endWord]);
        if(maxSize <= 0)
            return mRet;
        vector<string> tmp(maxSize, "");
        buildRet(tmp, wordToId[endWord], maxSize-1);
        return mRet;
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
    //根据标出的单词出现的层数 倒推路径
    void buildRet(vector<string>& tmp, int start, int layer){
        tmp[layer] = idToWord[start];
        if(layer < 1){
            mRet.emplace_back(tmp.begin(), tmp.end());
            return;
        }
        auto& cur = tope[start];
        for(auto i : cur){
            if(layers[i] != layer)
                continue;
            buildRet(tmp, i, layer-1);
        }
    }
};

int main(int argc, char const* argv[])
{
    WordLadder2 cls;
    auto& ret = cls.findLadders1("hit", "cog", vector<string>{"hot","dot","dog","lot","log","cog"});
    cout << "[";
    for(auto &it : ret){
        cout << "[";
        for(auto &str : it){
            cout << str.c_str() << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    auto& ret1 = cls.findLadders1("hit", "cog", vector<string>{"hot","dot","dog","lot","log"});
    cout << "[";
    for(auto &it : ret1){
        cout << "[";
        for(auto &str : it){
            cout << str.c_str() << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    auto& ret2 = cls.findLadders1("cet", "ism", vector<string>{"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"});
    cout << "[";
    for(auto &it : ret2){
        cout << "[";
        for(auto &str : it){
            cout << str.c_str() << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
    return 0;
}
