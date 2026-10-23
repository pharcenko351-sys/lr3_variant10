#pragma once

#include "dependencies.h"
#include "scheme.h"

class Calculator
{
public:
    void run();

private:
    void worker(int thread);
    static void f(char set, int index);

    Scheme scheme_;
    Dependencies dependencies_;
};
