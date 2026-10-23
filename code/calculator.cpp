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
    for (int step = 0; step < Scheme::STEPS; ++step)
    {
        const Action &action = scheme_.at(step, thread);
        dependencies_.wait_for(action.set);
        f(action.set, action.index);
        dependencies_.done(action.set);
    }
}

void Calculator::run()
{
    vector<jthread> threads;
    threads.reserve(Scheme::THREADS);
    for (int p = 0; p < Scheme::THREADS; ++p)
        threads.emplace_back(&Calculator::worker, this, p);
    for (auto &t : threads)
        t.join();
}
