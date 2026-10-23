#include "dependencies.h"

Dependencies::Dependencies() : a_(7), b_(9), c_(4), d_(8), h_(9), i_(8)
{
}

void Dependencies::wait_for(char set)
{
    switch (set)
    {
    case 'c':
    case 'h':
    case 'g':
        a_.wait();
        break;
    case 'd':
    case 'i':
    case 'k':
        b_.wait();
        break;
    case 'j':
        h_.wait();
        d_.wait();
        break;
    case 'n':
        c_.wait();
        i_.wait();
        break;
    default:
        break;
    }
}

void Dependencies::done(char set)
{
    switch (set)
    {
    case 'a':
        a_.count_down();
        break;
    case 'b':
        b_.count_down();
        break;
    case 'c':
        c_.count_down();
        break;
    case 'd':
        d_.count_down();
        break;
    case 'h':
        h_.count_down();
        break;
    case 'i':
        i_.count_down();
        break;
    default:
        break;
    }
}
