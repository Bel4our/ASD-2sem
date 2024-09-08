#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    stack<char> steck;
    string str;
    bool f = false;

    cout << "������� ������: "; getline(cin, str);

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            steck.push(str[i]);
            f = true;

        }
        if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (steck.empty())
            {
                cout << "������ ����������� �� �����";
                return 0;
            }
            else
            {
                if ((str[i] == ')' && steck.top() == '(') || (steck.top() == '{' && str[i] == '}') || (str[i] == ']' && steck.top() == '['))
                {
                    steck.pop();
                }
                else
                {
                    cout << "������ ����������� �� �����";
                    return 0;
                }
            }
        }
    }
    if (f)
    {
        cout << "������ ����������� �����";
    }
    else {
        cout << "������ ����������� �� �����";
    }
    return 0;
}