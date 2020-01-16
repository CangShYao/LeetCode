#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    string left;
    string right;
    int count;
    int flag;
    string ans;
    vector<string> answer;

public:
    Solution()
    {
        left = "(";
        right = ")";
        count = 0;
        flag = 0;
        ans = "";
        answer = vector<string>();
    }

    vector<string> generateParenthesis(int n) {
        helper(n);
        return answer;
    }

    void helper(int n)
    {
        if(count < n && ans.size() < 2*n && flag >= 0)
        {
            push_ch(left);
            helper(n);
        }
        if(ans.size() < 2*n && flag >= 0 && flag >= 0)
        {
            push_ch(right);
            helper(n);
        }
        if(ans.size() == 2*n)
        {
            answer.push_back(ans);
        }
        pop_ch();
    }

    void push_ch(string ch)
    {
        ans += ch;
        if(ch == left)
        {
            flag++;
            count++;
        }
        if(ch == right)
        {
            flag--;
        }
    }

    void pop_ch()
    {
        if (ans.size() == 0)
            return;
        if(ans.at(ans.size() - 1) == '(')
        {
            flag--;
            count--;
        }
        if(ans.at(ans.size() - 1) == ')')
        {
            flag++;
        }
        ans.erase(ans.size() - 1);
    }

    void output()
    {
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer.at(i) << endl;
        }
    }
};

int main()
{
    int n = 1;
    Solution s;
    s.generateParenthesis(n);
    s.output();
    system("pause");
    getchar();
}