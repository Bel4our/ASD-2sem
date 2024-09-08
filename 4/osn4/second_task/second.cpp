#include <iostream>

using namespace std;

int winner_1_value = 0, winner_2_value = 0, winner_3_value = 0;
int count1 = 1, count2 = 1, count3 = 1;

int main()
{
	setlocale(LC_ALL, "rus");
	int N;
	cout << "Введите число призёров от 3 и не более 10000: "; cin >> N;
	if (N <= 2 || N > 10000)
	{
		cout << "Вы ввели неправильное значение";
		return 0;
	}
	else
	{
		int* winners = new int[N];
		srand(time(0));
		for (int i = 0;i < N;i++)
		{
			winners[i] = rand() % 100 + 1;
			cout << winners[i] << " ";
		}
		for (int i = 0;i < N - 1;i++)
		{
			for (int j = 0; j < N - i - 1; j++)
			{
				if (winners[j] < winners[j + 1])
				{
					int temp = winners[j];
					winners[j] = winners[j + 1];
					winners[j + 1] = temp;
				}
			}
		}
		cout << endl << endl;
		for (int i = 0;i < N;i++)
		{
			cout << winners[i] << " ";
		}

		winner_1_value = winners[0];


		for (int i = 1; i < N; i++)
		{
			if (winners[i] == winner_1_value) {
				count1++;
			}
		}

		winner_2_value = winners[count1];

		for (int i = count1 + 1; i < N; i++)
		{
			if (winners[i] == winner_2_value) {
				count2++;
			}
		}

		winner_3_value = winners[count1 + count2];

		for (int i = count1 + count2 + 1; i < N; i++)
		{
			if (winners[i] == winner_3_value) {
				count3++;
			}
			 
		}
		cout << endl;
		cout << "Первых мест: " << count1 << endl;
		cout << "Вторых мест: " << count2 << endl;
		cout << "Третих мест: " << count3 << endl;
		cout << count1 + count2 + count3;
		return 0;
	}
}