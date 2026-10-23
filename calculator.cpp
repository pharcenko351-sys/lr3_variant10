#include "calculator.h"

#include <chrono>
#include <iostream>
#include <syncstream>
#include <thread>
#include <vector>

using namespace std;

void Calculator::f(char set, int index)
{
    this_thread::sleep_for(chrono::seconds(1));
    osyncstream(cout) << "З набору " << set << " виконано дію " << index << ".\n";
}

void Calculator::worker(int thread)
{
    for (int step = 0; step < Schedule::STEPS; ++step)
    {
        const Action &action = schedule_.at(step, thread);
        dependencies_.wait_for(action.set);
        f(action.set, action.index);
        dependencies_.done(action.set);
    }
}

void Calculator::run()
{
    vector<jthread> threads;
    threads.reserve(Schedule::THREADS);
    for (int p = 0; p < Schedule::THREADS; ++p)
        threads.emplace_back(&Calculator::worker, this, p);
    for (auto &t : threads)
        t.join();
}
