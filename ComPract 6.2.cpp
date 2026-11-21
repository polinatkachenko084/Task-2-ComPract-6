#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
// Функція для введення елементів масиву
void inputArray(int* a, int n) {
    SetConsoleCP(1251);          
    SetConsoleOutputCP(1251);  

    for (int i = 0; i < n; i++) {
        cout << "A[" << i + 1 << "] = ";
        cin >> a[i];
    }
}


void printArray(const int* a, int n) {
    // Перевірка на порожній масив
    if (n == 0) {
        cout << "(масив порожній)" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Функція, яка створює новий масив без елемента з номером k (нумерація з 1)
int* removeElement(const int* a, int n, int k) {
    // Виділяю пам'ять під новий масив на 1 елемент менше
    int* result = new int[n - 1];

    int pos = 0;  // Індекс для запису в новий масив

    // Копіюю всі елементи, крім того, що потрібно видалити
    for (int i = 0; i < n; i++) {
        if (i != k - 1) {          // k-1, бо нумерація в масиві з 0
            result[pos] = a[i];
            pos++;
        }
    }
    return result;
}

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть розмір масиву N: ";
    cin >> n;

    // Перевірка коректності розміру масиву
    while (n <= 0) {
        cout << "N має бути додатним. Спробуйте ще раз: ";
        cin >> n;
    }

    // Виділення динамічної пам'яті під масив
    int* a = new int[n];

    // Введення елементів масиву
    inputArray(a, n);

    int k;
    cout << "Введіть номер елемента для видалення (1.." << n << "): ";
    cin >> k;

    // Перевірка коректності номера елемента
    while (k < 1 || k > n) {
        cout << "Такого номера немає. Введіть число від 1 до " << n << ": ";
        cin >> k;
    }

    // Створення нового масиву без вибраного елемента
    int* b = removeElement(a, n, k);
    cout << "Вхідний масив: ";
    printArray(a, n);

    cout << "Масив після видалення " << k << "-го елемента: ";
    printArray(b, n - 1);
}