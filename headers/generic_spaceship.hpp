#include <string>
#include "environment.hpp"

#ifndef GENERIC_SPACESHIP_HPP
#define GENERIC_SPACESHIP_HPP

using namespace std;

class Generic_Spaceship {
    public:
        string name;
        ENVIRONMENT environment;
        int version;
};

class Generic_Build_Opts {
    public:
        string build_dir;
        string build_path;
};

#endif