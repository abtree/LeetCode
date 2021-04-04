#pragma once

//12 整数转罗马数字
class CIntToRoman {
public:
	string intToRoman(int num) {
		/*
			按表减法(贪心算法)
		*/
		if (num < 1 || num > 3999)
			return "error";

		vector<pair<int, string>> flags{
			{ 1000, "M" },
			{ 900, "CM" },
			{ 500, "D" },
			{ 400, "CD" },
			{ 100, "C" },
			{ 90, "XC"},
			{ 50, "L" },
			{ 40, "XL" },
			{ 10, "X" },
			{ 9, "IX" },
			{ 5, "V" },
			{ 4, "IV" },
			{ 1, "I" }
		};

		string str = "";
		auto it = flags.begin();
		while (num > 0)
		{
			if (num >= it->first) {
				num -= it->first;
				str += it->second;
			}
			else {
				++it;
			}
		}
		return str;
	}

	string intToRoman2(int num) {
		/*
			按位取值发 穷举每一位可能的取值(并不灵活)
			千位: ｛1， M｝,{2, MM}, {3, MMM}
			百位: ｛1， C｝,{2, CC},{3, CCC},{4, CD},{5, D},{6, DC},{7, DCC},{8, DCCC},{9, CM}
			十位: ｛1， X｝,{2, XX},{3, XXX},{4, XL},{5, L},{6, LX},{7, LXX},{8, LXXX},{9, XC}
			个位: ｛1， I｝,{2, II},{3, III},{4, IV},{5, V},{6, VI},{7, VII},{8, VIII},{9, IX}
		*/
		if (num < 1 || num > 3999)
			return "error";
		string thousands[3]{ "M", "MM", "MMM" };
		string hundreds[9]{ "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
		string tens[9]{ "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
		string ones[9]{ "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
		string ret = "";

		for (int i = 0; i < 4; ++i) {
			int pos = num % 10;
			if (pos > 0) {
				if(i == 0)
					ret = ones[pos - 1];
				else if(i == 1)
					ret = tens[pos - 1] + ret;
				else if (i == 2)
					ret = hundreds[pos - 1] + ret;
				else
					ret = thousands[pos - 1] + ret;
			}
			num /= 10;
			if(num <= 0)
				break;
		}
		return ret;
	}
public:
	static void Test() {
		CIntToRoman cls;
		cout << cls.intToRoman(3).c_str() << " -> 3" << endl;
		cout << cls.intToRoman(4).c_str() << " -> 4" << endl;
		cout << cls.intToRoman(9).c_str() << " -> 9" << endl;
		cout << cls.intToRoman(58).c_str() << " -> 58" << endl;
		cout << cls.intToRoman(1994).c_str() << " -> 1994" << endl;
		cout << cls.intToRoman(3986).c_str() << " -> 3986" << endl;
	}
};