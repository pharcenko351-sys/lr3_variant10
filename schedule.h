#pragma once

#include "action.h"

class Schedule
{
public:
    static constexpr int THREADS = 4;
    static constexpr int STEPS = 16;

    const Action &at(int step, int thread) const;

private:
    static const Action plan_[STEPS][THREADS];
};
