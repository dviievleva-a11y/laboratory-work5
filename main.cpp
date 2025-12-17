#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

/* ---------- КОРЕКТНЕ ВВЕДЕННЯ ---------- */

int inputInt(const string& msg, int minVal, int maxVal)
{
    int v;
    while (true)
    {
        cout << msg;
        cin >> v;
        if (cin.fail()  v < minVal  v > maxVal)
        {
            cout << "Помилка введення!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else return v;
    }
}

double inputDouble(const string& msg, double minVal, double maxVal)
{
    double v;
    while (true)
    {
        cout << msg;
        cin >> v;
        if (cin.fail()  v < minVal  v > maxVal)
        {
            cout << "Помилка введення!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else return v;
    }
}

/* ---------- ЗАВДАННЯ 1 (ФІГУРА, варіант 13) ---------- */
/*
   Варіант 13 — зелена частина:
   - коло радіуса r з центром (-r, -r)
   - + обмеження прямими y >= x та x <= 0
*/

void task1()
{
    cout << "\n--- Завдання 1 (Фігура, варіант 13) ---\n";

    int n = inputInt("Кількість точок: ", 1, 10000);
    double r = inputDouble("Введіть r: ", 0.01, 1000);

    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        double x, y;
        cout << "Точка " << i << " (x y): ";
        cin >> x >> y;

        bool inCircle =
            (x + r) * (x + r) + (y + r) * (y + r) <= r * r;

        bool inTriangle =
            y >= x && x <= 0;

        if (inCircle && inTriangle)
            count++;
    }

    cout << "Кількість точок у фігурі: " << count << endl;
}

/* ---------- ЗАВДАННЯ 2 (РЯД) ---------- */
/*
   S = Σ ( ln(x^(i-1)) * (-1)^i ) / x
   Виводимо кожний 4-й елемент
*/

void task2()
{
    cout << "\n--- Завдання 2 (Ряд) ---\n";

    double x = inputDouble("Введіть x (0.5..2): ", 0.5, 2.0);
    int n = inputInt("Введіть n: ", 1, 50);

    double sum = 0;

    for (int i = 1; i <= n; i++)
    {
        double term = log(pow(x, i - 1)) * pow(-1, i) / x;
        sum += term;

        if (i % 4 == 0)
            cout << "i = " << i << ", елемент = " << term << endl;
    }

    cout << "Сума ряду = " << sum << endl;
}

/* ---------- ЗАВДАННЯ 3 (ДОСЛІДЖЕННЯ РЯДУ) ---------- */
/*
   u_n = (x^n * n!) / n^(n/2)
   Умова зупинки: |u_n| > g
*/

void task3()
{
    cout << "\n--- Завдання 3 (Збіжність) ---\n";

    double x = inputDouble("Введіть x: ", 0.1, 5.0);
    const double g = 1e3;

    double sum = 0;
    double fact = 1;
    int n = 1;

    while (true)
    {
        fact *= n;
        double un = pow(x, n) * fact / pow(n, n / 2.0);
        sum += un;

        if (fabs(un) > g)
            break;

        n++;
    }

    cout << "Ряд розбіжний\n";
    cout << "n = " << n << endl;
    cout << "Часткова сума = " << sum << endl;
}

/* ---------- МЕНЮ ---------- */

int main()
{
    int choice;

    do
    {
        cout << "\n====== МЕНЮ ======\n";
        cout << "1 - Завдання 1 (Фігура)\n";
        cout << "2 - Завдання 2 (Ряд)\n";
        cout << "3 - Завдання 3 (Збіжність)\n";
        cout << "0 - Вихід\n";

        choice = inputInt("Ваш вибір: ", 0, 3);

        switch (choice)
        {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 0: cout << "Завершення програми.\n"; break;
        }

    } 
    while (choice != 0);

    return 0;
}
