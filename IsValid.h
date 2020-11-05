#pragma once

//20 有效的括号
class CIsValid {
	/*
	给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

	有效字符串需满足：
	左括号必须用相同类型的右括号闭合。
	左括号必须以正确的顺序闭合。
	注意空字符串可被认为是有效字符串。

	示例 1:
	输入: "()"
	输出: true

	示例 2:
	输入: "()[]{}"
	输出: true

	示例 3:
	输入: "(]"
	输出: false

	示例 4:
	输入: "([)]"
	输出: false

	示例 5:
	输入: "{[]}"
	输出: true
	*/
public:
	bool isValid(string s) {
		if (s.empty())
			return true;

		stack<char> stacks;
		unordered_map<char, char> change{
			{ ')', '(' },
			{ ']', '[' },
			{ '}', '{' }
		};
		for (char c : s) {
			switch (c)
			{
			case '(':
			case '[':
			case '{':
				stacks.push(c);
				break;
			case ')':
			case ']':
			case '}':
			{
				if (stacks.empty())
					return false;
				if (stacks.top() != change[c])
					return false;
				stacks.pop();
			}
				break;
			default:
				break;
			}
		}
		return stacks.empty();
	}

	bool isValid2(string s) {
		if (s.size() % 2 == 1)
			return false;	//基数个元素一定是不合法的

		stack<char> stacks;
		unordered_map<char, char> change{
			{ ')', '(' },
			{ ']', '[' },
			{ '}', '{' }
		};
		for (char c : s) {
			if (change.count(c)) {
				if (stacks.empty() || stacks.top() != change[c])
					return false;
				stacks.pop();
			}
			else {
				stacks.push(c);
			}
		}
		return stacks.empty();
	}
public:
	static void Test() {
		CIsValid cls;
		cout << boolalpha << cls.isValid("((") << " -> false" << endl;
		cout << boolalpha << cls.isValid("()[]{}") << " -> true" << endl;
		cout << boolalpha << cls.isValid("(]") << " -> false" << endl;
		cout << boolalpha << cls.isValid("([)]") << " -> false" << endl;
		cout << boolalpha << cls.isValid("{[]}") << " -> true" << endl;
	}
};