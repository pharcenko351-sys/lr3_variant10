// Програмний проект 3, варіант 10
// Харченко Поліна К-28
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <latch>
#include <syncstream>
#if defined(_WIN32)
#include <windows.h>
#endif

using namespace std;

const int NT = 4;
const int SLOTS = 16;

latch latA(7), latB(9), latC(4), latD(8), latH(9), latI(8);

struct Action
{
    char x;
    int i;
};

const Action plan[SLOTS][NT] = {
    {{'a', 1}, {'a', 2}, {'a', 3}, {'a', 4}},
    {{'a', 5}, {'a', 6}, {'a', 7}, {'b', 1}},
    {{'b', 2}, {'b', 3}, {'b', 4}, {'b', 5}},
    {{'b', 6}, {'b', 7}, {'b', 8}, {'b', 9}},
    {{'h', 1}, {'h', 2}, {'h', 3}, {'h', 4}},
    {{'h', 5}, {'h', 6}, {'h', 7}, {'h', 8}},
    {{'h', 9}, {'d', 1}, {'d', 2}, {'d', 3}},
    {{'d', 4}, {'d', 5}, {'d', 6}, {'d', 7}},
    {{'d', 8}, {'c', 1}, {'c', 2}, {'c', 3}},
    {{'c', 4}, {'i', 1}, {'i', 2}, {'i', 3}},
    {{'i', 4}, {'i', 5}, {'i', 6}, {'i', 7}},
    {{'i', 8}, {'j', 1}, {'j', 2}, {'j', 3}},
    {{'j', 4}, {'j', 5}, {'k', 1}, {'k', 2}},
    {{'n', 1}, {'n', 2}, {'n', 3}, {'k', 3}},
    {{'k', 4}, {'g', 1}, {'g', 2}, {'g', 3}},
    {{'g', 4}, {'g', 5}, {'g', 6}, {'g', 7}}
};

void f(char x, int i)
{
    this_thread::sleep_for(chrono::seconds(1));
    osyncstream(cout) << "З набору " << x << " виконано дію " << i << ".\n";
}

void wait_for(char x)
{
    switch (x)
    {
    case 'c':
    case 'h':
    case 'g':
        latA.wait();
        break;
    case 'd':
    case 'i':
    case 'k':
        latB.wait();
        break;
    case 'j':
        latH.wait();
        latD.wait();
        break;
    case 'n':
        latC.wait();
        latI.wait();
        break;
    default:
        break;
    }
}

void done(char x)
{
    switch (x)
    {
    case 'a':
        latA.count_down();
        break;
    case 'b':
        latB.count_down();
        break;
    case 'c':
        latC.count_down();
        break;
    case 'd':
        latD.count_down();
        break;
    case 'h':
        latH.count_down();
        break;
    case 'i':
        latI.count_down();
        break;
    default:
        break;
    }
}

void worker(int p)
{
    for (int t = 0; t < SLOTS; ++t)
    {
        const Action &act = plan[t][p];
        wait_for(act.x);
        f(act.x, act.i);
        done(act.x);
    }
}

int main()
{
#if defined(_WIN32)
    SetConsoleOutputCP(CP_UTF8);
#endif

    osyncstream(cout) << "Обчислення розпочато.\n";
    auto start = chrono::steady_clock::now();

    {
        jthread t0(worker, 0);
        jthread t1(worker, 1);
        jthread t2(worker, 2);
        jthread t3(worker, 3);
    }

    chrono::duration<double> total = chrono::steady_clock::now() - start;
    osyncstream(cout) << "Обчислення завершено. Тривалість обчислення "
                      << fixed << setprecision(2) << total.count() << " секунд.\n";
    return 0;
}
