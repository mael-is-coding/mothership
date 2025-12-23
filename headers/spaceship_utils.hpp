#ifndef SPACESHIP_UTILS_HPP
#define SPACESHIP_UTILS_HPP

#include "environment.hpp"
#include "hook.hpp"
#include <string>
#include <vector>

using namespace std;

bool locate_spaceship();

void parse_spaceship();

vector<Hook> getAllHooks();

ENVIRONMENT get_env_code(string env);

#endif