#pragma once

#include "dependencies.h"
#include "schedule.h"

class Calculator
{
public:
    void run();

private:
    void worker(int thread);
    static void f(char set, int index);

    Schedule schedule_;
    Dependencies dependencies_;
};
