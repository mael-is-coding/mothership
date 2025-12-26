#ifndef SPACESHIP_UTILS_HPP
#define SPACESHIP_UTILS_HPP

#include "environment.hpp"
#include "generic_spaceship.hpp"
#include "hook.hpp"

#include "toml.hpp"
#include <string>
#include <vector>

using namespace std;

bool locate_spaceship();

void parse_spaceship();

Generic_Build_Opts parse_generic_build_opts(toml::node_view<toml::node> build_opts);

Generic_Spaceship parse_generic_base(toml::parse_result parse_res);

vector<Hook> parse_hooks(toml::array *hook_node);

ENVIRONMENT get_env_code(string env);

#endif