#ifndef HOOK_HPP
#define HOOK_HPP

#include <string>
#include "exec_pos.hpp"
using namespace std;

class Hook {
    public:
        string name;
        string command;
        string path;
        EXEC_POS when;
};

#endif