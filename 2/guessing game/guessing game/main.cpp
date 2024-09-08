#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int N;
    cout << "������� ����� N: "; cin >> N;
    if (N < 1)
    {
        cout << "������!";
        return 0;
    }
    int fnumb = 1, lnumb = N;
    int answer;
    int guess;
    int variants[100];
    int max_steps = log2(N) + 1;
    int step=0;
    while (fnumb <= lnumb)
    {
        guess = fnumb + (lnumb - fnumb) / 2;
        cout << "�� �������� �����: " << guess << "? (1 - ����, 2 - �����, 3 - ������): "; cin >> answer;
        variants[step] = guess;
        step++;
        if (answer == 3)
        {
            break;
        }
        else
        {
            if (answer == 2)
            {
                lnumb = guess - 1;
            }
            else
            {
                if (answer == 1)
                {
                    fnumb = guess + 1;
                }
                else
                {
                    cout << "�� ����� ������������ ��������!"<<endl;
                    continue;
                }
            }
        }
    }
        cout << "������������ ���������� ����� = " << max_steps << endl;
        for (int i = 0; i < step; i++)
        {
            cout << variants[i] << endl;
        }
    return 0;
}