#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//30. 串联所有单词的子串
class CFindSubString{
    /*
    给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
    注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

    示例 1：
    输入：
    s = "barfoothefoobarman",
    words = ["foo","bar"]
    输出：[0,9]
    解释：
    从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
    输出的顺序不重要, [9,0] 也是有效答案。

    示例 2：
    输入：
    s = "wordgoodgoodgoodbestword",
    words = ["word","good","best","word"]
    输出：[]
    */
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //比对数量发
		if (words.empty())
			return vector<int>{};
        //首先构造一个用于比对的map
		unordered_map<string, int> model;
		for (auto &itm : words) {
			model[itm] += 1;
		}
		//
		int L = s.size();
		int n = words.size() * words[0].size();
		vector<int> back;
		for (int i = 0; i <= L - n; ++i) {
			if (isMacth(s, i, words[0].size(), i + n, model) == 0) {
				back.push_back(i);
			}		
		}
		return back;
    }
private:
	int isMacth(string& s, int pos, int cell, int end, unordered_map<string, int>& model) {
		unordered_map<string, int> tmp;
		while (pos < end) {
			string sub = s.substr(pos, cell);
			int t = model.count(sub);
			if (t == 0)
				return 1;
			++tmp[sub];
			if (tmp[sub] > model[sub])
				return 1;
			pos += cell;
		}
		return 0;
	}
};

int main(int argc, char const *argv[])
{
	CFindSubString cls;
	auto ret2 = cls.findSubstring("wordgoodgoodgoodbestword", vector<string>{"word", "good", "best", "good"});
	cout << "[";
	for (auto& it2 : ret2) {
		cout << it2 << " ";
	}
	cout << "]" << endl;

	auto ret = cls.findSubstring("barfoothefoobarman", vector<string>{"foo", "bar"});
	cout << "[";
	for(auto& it : ret){
		cout << it << " ";
	}
	cout << "]" << endl;

	auto ret1 = cls.findSubstring("wordgoodgoodgoodbestword", vector<string>{"word", "good", "best", "word"});
	cout << "[";
	for (auto& it1 : ret1) {
		cout << it1 << " ";
	}
	cout << "]" << endl;
	return 0;
}
