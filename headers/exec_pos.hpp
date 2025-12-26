#ifndef EXEC_POS_HPP
#define EXEC_POS_HPP

#include <string>
using namespace std;

enum EXEC_POS {
    UNKNOWN_POS,
    BEFORE,
    AFTER
};

EXEC_POS get_execpos_code(string execpos);

#endif