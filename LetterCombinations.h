#pragma once

//17 电话号码的字母组合
class CLetterCombinations {
	/*
	给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
	给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
	{
		2 -> {a,b,c}
		3 -> {d,e,f}
		4 -> {g,h,i}
		5 -> {j,k,l}
		6 -> {m,n,o}
		7 -> {p,q,r,s}
		8 -> {t,u,v}
		9 -> {w,x,y,z}
	}

	示例:
	输入："23"
	输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

	说明:
	尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
	*/
private:
	unordered_map<char, vector<char>> mDic{
		{ '2', { 'a','b','c' } },
		{ '3', { 'd','e','f' } },
		{ '4', { 'g','h','i' } },
		{ '5', { 'j','k','l' } },
		{ '6', { 'm','n','o' } },
		{ '7', { 'p','q','r','s' } },
		{ '8', { 't','u','v' } },
		{ '9', { 'w','x','y','z' } },
	};
	vector<string> mRet{};
public:
	vector<string> letterCombinations(string digits) {
		/*
			该题由于需要输出所有组合
			所以用递归比较简单
		*/
		buildStr(digits, "", 0);
		return mRet;
	}
	void buildStr(string& src, string dst, int index) {
		if (index >= src.size()) {
			if (!dst.empty())
				mRet.push_back(dst);
			return;
		}
		const char c = src[index];
		if (c < '2' || c > '9') {
			buildStr(src, dst, ++index);
		}

		for (auto d : mDic[c]) {
			buildStr(src, dst + d, index + 1);
		}
	}
public:
	static void Test() {
		CLetterCombinations cls;
		auto ret = cls.letterCombinations("23");
		cout << "[";
		for (auto &it : ret) {
			cout << it.c_str() << "\t";
		}
		cout << "]";
	}
};