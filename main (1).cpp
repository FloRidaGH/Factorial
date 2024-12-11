#include <iostream>
#include <limits> 

using namespace std;


unsigned long long factorial(int n) {
    if (n < 0) {
        throw invalid_argument("Число должно быть положительным.");
    }

    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }

    return result;
}

int main() {
    int number;
    cout << "Введите положительное целое число: ";

    
    while (true) {
        cin >> number;

        
        if (cin.fail()) {
            cout << "Ошибка: введено нечисловое значение. Пожалуйста, введите целое число: ";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (number < 0) {
            cout << "Ошибка: число должно быть положительным. Пожалуйста, введите число заново: ";
        } else {
            break; 
        }
    }

    try {
        unsigned long long result = factorial(number);
        cout << "Факториал числа " << number << " равен " << result << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Ошибка " << e.what() << endl;
    }

    return 0;
}