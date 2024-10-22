#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

// Рекурсивна функція для заповнення масиву
void fillArrayRecursive(int* arr, int size, int index = 0) {
    if (index == size) return;
    arr[index] = rand() % 201 - 100; // Генеруємо числа від -100 до 100
    fillArrayRecursive(arr, size, index + 1);
}

// Рекурсивна функція для створення та заповнення динамічного масиву
int* createArray(int size) {
    int* arr = new int[size];
    fillArrayRecursive(arr, size);
    return arr;
}

// Рекурсивна функція для виведення масиву
void printArrayRecursive(const int* arr, int size, int index = 0) {
    if (index == size) {
        cout << endl;
        return;
    }
    cout << setw(5) << arr[index];
    printArrayRecursive(arr, size, index + 1);
}

// Допоміжна рекурсивна функція для пошуку мінімального за модулем елемента
int findMinAbsElementRecursive(const int* arr, int size, int index, int currentMin, int minElement) {
    if (index == size) return minElement;

    if (abs(arr[index]) < currentMin) {
        return findMinAbsElementRecursive(arr, size, index + 1, abs(arr[index]), arr[index]);
    }
    return findMinAbsElementRecursive(arr, size, index + 1, currentMin, minElement);
}

// Основна функція пошуку мінімального за модулем елемента
int findMinAbsElement(const int* arr, int size) {
    return findMinAbsElementRecursive(arr, size, 1, abs(arr[0]), arr[0]);
}

// Допоміжна рекурсивна функція для обчислення суми модулів після першого нуля
int sumAbsAfterFirstZeroRecursive(const int* arr, int size, int index, bool foundZero, int sum) {
    if (index == size) return sum;

    if (foundZero) {
        return sumAbsAfterFirstZeroRecursive(arr, size, index + 1, true, sum + abs(arr[index]));
    }
    if (arr[index] == 0) {
        return sumAbsAfterFirstZeroRecursive(arr, size, index + 1, true, sum);
    }
    return sumAbsAfterFirstZeroRecursive(arr, size, index + 1, false, sum);
}

// Основна функція обчислення суми модулів після першого нуля
int sumAbsAfterFirstZero(const int* arr, int size) {
    return sumAbsAfterFirstZeroRecursive(arr, size, 0, false, 0);
}

// Допоміжна рекурсивна функція для копіювання елементів у тимчасовий масив
void copyToTempArrayRecursive(int* source, int* temp, int size, int index,
    int& evenIndex, int& oddIndex) {
    if (index == size) return;

    if (index % 2 == 0) {
        temp[evenIndex++] = source[index];
    }
    else {
        temp[oddIndex++] = source[index];
    }

    copyToTempArrayRecursive(source, temp, size, index + 1, evenIndex, oddIndex);
}

// Допоміжна рекурсивна функція для копіювання назад в оригінальний масив
void copyBackRecursive(int* dest, const int* source, int size, int index) {
    if (index == size) return;
    dest[index] = source[index];
    copyBackRecursive(dest, source, size, index + 1);
}

// Основна функція перестановки елементів
void rearrangeArray(int* arr, int size) {
    int* temp = new int[size];
    int evenIndex = 0;
    int oddIndex = size / 2;

    copyToTempArrayRecursive(arr, temp, size, 0, evenIndex, oddIndex);
    copyBackRecursive(arr, temp, size, 0);

    delete[] temp;
}

int main() {
    SetConsoleOutputCP(1251); 

    srand(time(0));
    int n;

    cout << "Введіть розмір масиву: ";
    cin >> n;

    // Створення та заповнення масиву
    int* arr = createArray(n);

    // Виведення початкового масиву
    cout << "Початковий масив:\n";
    printArrayRecursive(arr, n);

    // Знаходження мінімального за модулем елемента
    int minAbs = findMinAbsElement(arr, n);
    cout << "Мінімальний за модулем елемент: " << minAbs << endl;

    // Обчислення суми модулів після першого нуля
    int sumAbs = sumAbsAfterFirstZero(arr, n);
    cout << "Сума модулів елементів після першого нуля: " << sumAbs << endl;

    // Перестановка елементів
    rearrangeArray(arr, n);
    cout << "Масив після перестановки:\n";
    printArrayRecursive(arr, n);

    // Звільнення пам'яті
    delete[] arr;

    return 0;
}
