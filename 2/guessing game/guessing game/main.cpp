#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int N;
    cout << "Введите число N: "; cin >> N;
    if (N < 1)
    {
        cout << "Ошибка!";
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
        cout << "Вы загадали число: " << guess << "? (1 - мало, 2 - много, 3 - угадал): "; cin >> answer;
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
                    cout << "Вы ввели неправильное значение!"<<endl;
                    continue;
                }
            }
        }
    }
        cout << "Максимальное количество шагов = " << max_steps << endl;
        for (int i = 0; i < step; i++)
        {
            cout << variants[i] << endl;
        }
    return 0;
}