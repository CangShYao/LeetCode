#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

class Solution
{
private:
    stack<char> brackets;
    map<char, int> b_map;

public:
    Solution()
    {
        brackets = stack<char>();
        b_map = map<char, int>();
        b_map.insert(pair<char, int>('(', 1));
        b_map.insert(pair<char, int>('[', 2));
        b_map.insert(pair<char, int>('{', 3));
        b_map.insert(pair<char, int>(')', -1));
        b_map.insert(pair<char, int>(']', -2));
        b_map.insert(pair<char, int>('}', -3));
    }

    bool isValid(string s)
    {
        if (s.size() % 2 == 1)
            return false;
        for (int i = 0; i < s.length(); i++)
        {
            if (b_map[s.at(i)] > 0)
            {
                brackets.push(s.at(i));
            }
            else
            {
                if (brackets.size() > 0)
                {
                    if (b_map[brackets.top()] == -b_map[s.at(i)])
                    {
                        brackets.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                    return false;
            }
        }
        if (brackets.size() > 0)
            return false;
        return true;
    }
};

int main()
{
    string input = "()))";
    Solution s;
    cout << s.isValid(input) << endl;
    system("pause");
}