#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class EncodeAndDecodeTinyurl
{
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        int cur = ++index;
        string tiny = "http://tinyurl.com/" + to_string(cur);
        database[tiny] = longUrl;
        return tiny;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return database[shortUrl];
    }

private:
    unordered_map<string, string> database;
    int index{};
};

int main()
{
    EncodeAndDecodeTinyurl cls;
    string url = cls.encode("https://leetcode.com/problems/design-tinyurl");
    cout << "Encode: " << url.c_str() << endl;
    cout << "Decode: " << cls.decode(url).c_str() << endl;
    return 0;
}
