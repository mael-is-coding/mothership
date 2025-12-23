#ifndef JAVA_SPACESHIP_HPP
#define JAVA_SPACESHIP_HPP

#include "generic_spaceship.hpp"
#include "java_utils.hpp"
#include <memory>

using namespace std;

class Java_Spaceship: Generic_Spaceship {
    unique_ptr<JavaUtils::Build_Opts> build_opts;
    unique_ptr<JavaUtils::Run_Opts> run_opts;
};

#endif