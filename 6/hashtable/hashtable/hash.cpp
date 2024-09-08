#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Node {
    int key;
    string lastName;
    string firstName;
    string patronymic;
    Node* next;
    Node(int k, const string& l, const string& f, const string& p) : key(k), lastName(l), firstName(f), patronymic(p), next(nullptr) {}
};

class HashTable {
private:
    Node** table;
    int TABLE_SIZE;

    int hash(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable(int size) : TABLE_SIZE(size) {
        table = new Node * [TABLE_SIZE];

        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    void insert(int key, const string& lastName, const string& firstName, const string& patronymic) {
        int index = hash(key);
        Node* newNode = new Node(key, lastName, firstName, patronymic);
        if (table[index] == nullptr) {
            table[index] = newNode;
        }
        else {
            Node* temp = table[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    string search(int key) {
        int index = hash(key);
        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->key == key)
            {
                return temp->lastName + " " + temp->firstName + " " + temp->patronymic;
            }
            temp = temp->next;
        }
        return "������� �� ������";
    }

    void remove(int key) {
        int index = hash(key);
        Node* temp = table[index];
        Node* prev = nullptr;
        while (temp != nullptr) {
            if (temp->key == key) {
                if (prev == nullptr) {
                    table[index] = temp->next;
                }
                else {
                    prev->next = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }


    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << i << ": ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << "(" << temp->key << ", " << temp->lastName << ", " << temp->firstName << ", " << temp->patronymic << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    int size;
    cout << "������� ������ �������: ";
    cin >> size;

    HashTable ht(size);

    auto start_time = chrono::steady_clock::now();
    auto end_time = chrono::steady_clock::now();

    int choice;
    int key;
    string lastName;
    string firstName;
    string patronymic;

    do {
        cout << "\n1. �������� �������\n";
        cout << "2. ����� �������\n";
        cout << "3. ������� �������\n";
        cout << "4. ������� �������\n";
        cout << "0. �����\n";
        cout << "�������� ��������: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������� ����� ��������, �������, ��� � ��������: ";
            cin >> key >> lastName >> firstName >> patronymic;
            if (key > 0)
            {
                ht.insert(key, lastName, firstName, patronymic);
            }
            else {
                cout << "������� ����������� ��������!\n";
            }
            break;
        case 2:
            cout << "������� ����� �������� ��� ������: ";
            cin >> key;
            start_time = chrono::steady_clock::now();
            cout << "��������� ������: " << ht.search(key) << endl;
            end_time = chrono::steady_clock::now();
            cout << "����� ���������� ������: " << chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count() << " ����������" << endl;
            break;
        case 3:
            cout << "������� ����� �������� ��� ��������: ";
            cin >> key;
            ht.remove(key);
            break;
        case 4:
            cout << "�������:" << endl;
            ht.display();
            break;
        case 0:
            cout << "��������� ���������\n";
            break;
        default:
            cout << "�������� �����\n";
        }
    } while (choice != 0);

    return 0;
}