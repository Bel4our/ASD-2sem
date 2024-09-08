#include <iostream>
#include <chrono>

using namespace std;

void qsortRecursive(int* mas, int size) 
{
	int i = 0;
	int j = size - 1;
	int mid = mas[size / 2];
	do 
	{
		while (mas[i] < mid) 
		{
			i++;
		}
		while (mas[j] > mid) {
			j--;
		}
		if (i <= j) 
		{
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);


	if (j > 0) 
	{
		qsortRecursive(mas, j + 1);
	}
	if (i < size) 
	{
		qsortRecursive(&mas[i], size - i);
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int N;
	cout << "Введите количество элементов: "; cin >> N;
	if (N > 0)
	{
		int* A = new int[N];
		int* B = new int[N];
		int* C = new int[N];
		int* D = new int[N];
		int* E = new int[N];

		cout << endl << "Неотсортированный массив: " << endl;
		for (int i = 0;i < N;i++)
		{
			*(A + i) = rand() % 201 - 100;
			*(B + i) = *(A + i);
			*(C + i) = *(A + i);
			*(D + i) = *(A + i);
			*(E + i) = *(A + i);
			cout << *(A + i) << " ";
		}
		cout << endl << endl << "Пузырьковая сортировка:" << endl << endl;
		auto start_value = chrono::high_resolution_clock::now();
		for (int i = 0;i < N - 1;i++)
		{
			for (int j = 0; j < N - i - 1; j++)
			{
				if (B[j] > B[j + 1])
				{
					int temp = B[j];
					B[j] = B[j + 1];
					B[j + 1] = temp;
				}
			}
		}
		auto end_value = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> difference_value = end_value - start_value;
		for (int i = 0;i < N;i++)
		{
			cout << *(B + i) << " ";
		}
		cout << endl << "Затраченное время: " << difference_value.count() << endl;
		auto start_value2 = chrono::high_resolution_clock::now();
		for (int i = 1;i < N;i++)
		{
			for (int j = i;j > 0 && C[j - 1] > C[j];j--)
			{
				int tmp = C[j - 1];
				C[j - 1] = C[j];
				C[j] = tmp;
			}
		}
		cout << endl << "Сортировка вставкой:" << endl << endl;
		auto end_value2 = chrono::high_resolution_clock::now();
		for (int i = 0;i < N;i++)
		{
			cout << *(C + i) << " ";
		}
		chrono::duration<double, milli> difference_value2 = end_value2 - start_value2;
		cout << endl << "Затраченное время: " << difference_value2.count() << endl;
		auto start_value3 = chrono::high_resolution_clock::now();
		int min;
		for (int i = 0; i < N; i++)
		{
			int min = i;
			for (int j = i + 1; j < N; j++)
			{
				if (D[j] < D[min])
				{
					min = j;
				}
			}
			if (i != min)
			{
				int temp = D[i];
				D[i] = D[min];
				D[min] = temp;
			}
		}
		auto end_value3 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> difference_value3 = end_value3 - start_value3;
		cout << endl << "Сортировка выбором:" << endl << endl;
		for (int i = 0;i < N;i++)
		{
			cout << *(D + i) << " ";
		}
		cout << endl << "Затраченное время: " << difference_value3.count() << endl;

		auto start_value4 = chrono::high_resolution_clock::now();
		qsortRecursive(E, N);
		auto end_value4 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> difference_value4 = end_value4 - start_value4;
		cout << endl << "Быстрая сортировка:" << endl << endl;
		for (int i = 0; i < N; i++)
		{
			cout << *(E + i) << " ";
		}
		cout << endl << "Затраченное время: " << difference_value4.count() << endl;

		return 0;
	}
	else
	{
		cout << "Вы ввели неправильное значение!";
	}
}
