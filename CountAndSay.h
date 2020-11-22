#pragma once

//38. �������
class CountAndSay {
	/*
	����һ�������� n �����������еĵ� n �
	��������С���һ���������У������� 1 ��ʼ�������е�ÿһ��Ƕ�ǰһ���������
	����Խ����������ɵݹ鹫ʽ����������ַ������У�
	countAndSay(1) = "1"
	countAndSay(n) �Ƕ� countAndSay(n-1) ��������Ȼ��ת������һ�������ַ�����
	ǰ�������£�
	1.     1
	2.     11
	3.     21
	4.     1211
	5.     111221
	��һ�������� 1
	����ǰһ�������� 1 �� �� һ �� 1 �������� "11"
	����ǰһ�������� 11 �� �� �� �� 1 �� ������ "21"
	����ǰһ�������� 21 �� �� һ �� 2 + һ �� 1 �� ������ "1211"
	����ǰһ�������� 1211 �� �� һ �� 1 + һ �� 2 + �� �� 1 �� ������ "111221"
	Ҫ ���� һ�������ַ���������Ҫ���ַ����ָ�Ϊ ��С �������飬ÿ���鶼����������� ��ͬ�ַ� ��ɡ�Ȼ�����ÿ���飬�������ַ���������Ȼ�������ַ����γ�һ�������顣Ҫ������ת��Ϊ�����ַ������Ƚ�ÿ���е��ַ������������滻���ٽ���������������������
	
	ʾ�� 1��
	���룺n = 1
	�����"1"
	���ͣ�����һ������������

	ʾ�� 2��
	���룺n = 4
	�����"1211"
	���ͣ�
	countAndSay(1) = "1"
	countAndSay(2) = �� "1" = һ �� 1 = "11"
	countAndSay(3) = �� "11" = �� �� 1 = "21"
	countAndSay(4) = �� "21" = һ �� 2 + һ �� 1 = "12" + "11" = "1211"

	��ʾ��1 <= n <= 30
	*/
public:
	string countAndSay(int n) {
		if (n == 1)
			return "1";
		string dst = countAndSay(n - 1);
		string ret = "";
		char count = '1';
		char last = '.';
		for (auto c : dst) {
			if (c == last) {
				++count;
				continue;
			}
			if (last != '.') {
				ret.push_back(count);
				ret.push_back(last);
			}
			last = c;
			count = '1';
		}
		ret.push_back(count);
		ret.push_back(last);
		return ret;
	}
	string countAndSay2(int n) {
		return say("1", n - 1);
	}
private:
	string say(const string& src, int n) {
		if (n == 0)
			return src;
		string ret = "";
		char count = '1';
		char last = '.';
		for (auto c : src) {
			if (c == last) {
				++count;
				continue;
			}
			if (last != '.') {
				ret.push_back(count);
				ret.push_back(last);
			}
			last = c;
			count = '1';
		}
		ret.push_back(count);
		ret.push_back(last);
		return say(ret, n - 1);
	}
public:
	static void Test() {
		CountAndSay cls;
		cout << cls.countAndSay2(1).c_str() << endl;
		cout << cls.countAndSay2(2).c_str() << endl;
		cout << cls.countAndSay2(3).c_str() << endl;
		cout << cls.countAndSay2(4).c_str() << endl;
		cout << cls.countAndSay2(5).c_str() << endl;
		cout << cls.countAndSay2(6).c_str() << endl;
	}
};