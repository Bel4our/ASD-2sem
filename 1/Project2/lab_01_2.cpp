#include <iostream>
#include <chrono>

using namespace std;

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
    int N;
    cout << "¬ведите номер числа: ";
    cin >> N;
    auto start_value = chrono::high_resolution_clock::now();
    cout << findFib(N);
    auto end_value = chrono::high_resolution_clock::now();

    chrono::duration<double> difference_value = end_value - start_value;

    cout << '\n' << difference_value.count() << endl;
    return 0;
}
