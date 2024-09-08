#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int N;
	cout << "Введите количество товаров не более 10000: "; cin >> N;
	if (N <= 0 || N > 10000)
	{
		cout << "Вы ввели неправильное значение";
		return 0;
	}
	int* prices = new int[N];
	srand(time(0));
	for (int i = 0;i < N;i++)
	{
		prices[i] = rand() % 100+1;
		cout << prices[i] << " ";
	}
	cout << endl<<endl;
	for (int i = 0;i < N - 1;i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (prices[j] > prices[j + 1])
			{
				int temp = prices[j];
				prices[j] = prices[j + 1];
				prices[j + 1] = temp;
			}
		}
	}
	for (int i = 0;i < N;i++)
	{
		cout << prices[i] << " ";
	}
	cout << endl << endl;
	int half = N / 2;
	int bufhalf = half;
	int sum = 0;
	if (N % 2 == 0)
	{
		for (int i = 0;i < bufhalf; i++, half++)
		{
			cout << prices[half] << " ";
			cout << prices[i] << " ";
			sum += prices[half];
		}
		
	}
	else
	{
		for (int i = 0;i < bufhalf;i++, half++)
		{
			cout << prices[half] << " ";
			cout << prices[i] << " ";
			sum += prices[half];
		}
		cout << prices[N-1];
		sum += prices[N-1];
	}
	cout << endl << "Максимальная сумма чека: " << sum;
	return 0;
}