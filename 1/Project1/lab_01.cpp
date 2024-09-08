#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int findFib(int N)
{

	if (N <= 2)
	{
		return N - 1;
	}
	else
	{
		return findFib(N - 1) + findFib(N - 2);
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	unsigned long long N, x1 = 0, x2 = 1, x;
	cout << "Введите N число ряда Фибаначчи: "; cin >> N;
	auto start_value = chrono::high_resolution_clock::now();
	if (N == 1)
	{
		x = x1;
	}
	else
	{
		if (N == 2)
		{
			x = x2;
		}
		else 
		{
			for (int i = 0;i < N - 2;i++)
			{
				x = x1 + x2;
				x1 = x2;
				x2 = x;
			}
		}
	}
	cout << x;
	auto end_value = chrono::high_resolution_clock::now();

	auto difference_value = duration_cast<seconds>(end_value - start_value);
	auto difference_value1 = duration_cast<seconds>(end_value - start_value);

	cout << '\n' << difference_value.count() << "мин" << difference_value1.count() <<"сек" << endl;


	auto start_value1 = chrono::high_resolution_clock::now();
	cout << findFib(N);
	auto end_value1 = chrono::high_resolution_clock::now();

	auto difference_value2 = duration_cast<minutes>(end_value1 - start_value1);
	auto difference_value3 = duration_cast<seconds>(end_value1 - start_value1);

	cout << '\n' << difference_value2.count() <<"мин" << difference_value3.count() <<"сек" << endl;

	return 0;
}
