// Програмний проект 3, варіант 10
// Харченко Поліна К-28
#include <chrono>
#include <iomanip>
#include <iostream>
#include <syncstream>
#if defined(_WIN32)
#include <windows.h>
#endif
#include "calculator.h"

using namespace std;

int main()
{
#if defined(_WIN32)
    SetConsoleOutputCP(CP_UTF8);
#endif

    Calculator calculator;

    osyncstream(cout) << "Обчислення розпочато.\n";
    auto start = chrono::steady_clock::now();

    calculator.run();

    chrono::duration<double> total = chrono::steady_clock::now() - start;
    osyncstream(cout) << "Обчислення завершено. Тривалість обчислення "
                      << fixed << setprecision(2) << total.count() << " секунд.\n";
    return 0;
}
