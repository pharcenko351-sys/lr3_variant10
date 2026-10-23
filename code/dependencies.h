#pragma once

#include <latch>

class Dependencies
{
public:
    Dependencies();

    void wait_for(char set);
    void done(char set);

private:
    std::latch a_;
    std::latch b_;
    std::latch c_;
    std::latch d_;
    std::latch h_;
    std::latch i_;
};
