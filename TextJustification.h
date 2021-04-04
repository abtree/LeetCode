#pragma once

//68. 文本左右对齐
class TextJustification {
    /*
    给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。文本的最后一行应为左对齐，且单词之间不插入额外的空格。

    说明:
    单词是指由非空格字符组成的字符序列。
    每个单词的长度大于 0，小于等于 maxWidth。
    输入单词数组 words 至少包含一个单词。

    示例:
    输入:
    words = ["This", "is", "an", "example", "of", "text", "justification."]
    maxWidth = 16
    输出:
    [
       "This    is    an",
       "example  of text",
       "justification.  "
    ]

    示例 2:
    输入:
    words = ["What","must","be","acknowledgment","shall","be"]
    maxWidth = 16
    输出:
    [
      "What   must   be",
      "acknowledgment  ",
      "shall be        "
    ]
    解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
         因为最后一行应为左对齐，而不是左右两端对齐。
        第二行同样为左对齐，这是因为这行只包含一个单词。

    示例 3:
    输入:
    words = ["Science","is","what","we","understand","well","enough","to","explain",
             "to","a","computer.","Art","is","everything","else","we","do"]
    maxWidth = 20
    输出:
    [
      "Science  is  what we",
      "understand      well",
      "enough to explain to",
      "a  computer.  Art is",
      "everything  else  we",
      "do                  "
    ]
    */
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int size = words.size();
        int pos = 0;
        int len = 0;
        int total = 0;
        vector<string> rets;
        while (pos + len < size) {
            total += words[pos + len].size();
            if (total + len < maxWidth) {
                ++len;
                continue;   //尝试装入下一个字符串
            }
            if (total + len > maxWidth) {
                total -= words[pos + len].size();   //多了 要减去一个
            }
            else {
                ++len;  //刚好相等 要算上最后一个
            }

            if (len > 0) {
                --len;  //算空格需要少算1个
            }
            string add = "";
            if (len == 0) {
                add.append(words[pos]);
                if (maxWidth - total > 0) {
                    add.append(maxWidth - total, ' ');
                }
            }
            else {
                auto q = std::div(maxWidth - total, len);
                for (int i = 0; i < len;++i) {
                    add.append(words[pos + i]);
                    add.append(q.quot, ' ');
                    if (q.rem > 0) {
                        add.push_back(' ');
                        --q.rem;
                    }
                }
                add.append(words[pos + len]);
            }

            rets.push_back(add);
            pos += len + 1;
            total = 0;
            len = 0;
        }
        if (pos < size) {
            string add = "";
            while (pos < size) {
                add.append(words[pos]);
                add.push_back(' ');
                ++pos;
            }
            add.append(maxWidth - add.size(), ' ');
            rets.push_back(add);
        }
        return rets;
    }
public:
    static void Test() {
        TextJustification cls;
        auto ret1 = cls.fullJustify(vector<string>{
            "This", "is", "an", "example", "of", "text", "justification."
        }, 16);
        cout << "[" << endl;
        for (auto& it : ret1) {
            cout << it.c_str() << endl;
        }
        cout << "]" << endl << endl;

        auto ret2 = cls.fullJustify(vector<string>{
            "What", "must", "be", "acknowledgment", "shall", "be"
        }, 16);
        cout << "[" << endl;
        for (auto& it : ret2) {
            cout << it.c_str() << endl;
        }
        cout << "]" << endl << endl;

        auto ret3 = cls.fullJustify(vector<string>{
            "Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",
                "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"
        }, 20);
        cout << "[" << endl;
        for (auto& it : ret3) {
            cout << it.c_str() << endl;
        }
        cout << "]" << endl << endl;
    }
};