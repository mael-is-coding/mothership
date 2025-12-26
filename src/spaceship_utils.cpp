
#include <cerrno>
#include <iostream>
#include <optional>
#include <sys/types.h>
#include <dirent.h>
#include <cstring>
#include <fstream>
#include "hook.hpp"
#include "java_utils.hpp"
#include "toml.hpp"
#include "exec_pos.hpp"

#include "spaceship_utils.hpp"
#include "environment.hpp"

using namespace std;

/**
* @author Mael
* @return true if a spaceship.toml file exists in current directory, false if not
*/
bool locate_spaceship() {
    string name = "spaceship.toml";

    DIR* dir_pointer = opendir(".");

    dirent* dp;
    while(dir_pointer) {
        errno = 0;
        if((dp = readdir(dir_pointer)) != NULL) {
            if (name.compare(dp->d_name) == 0) {
                return true;
            }
        } else {
            if(errno == 0) {
                closedir(dir_pointer);
                return false;
            }

            closedir(dir_pointer);
            return false;
        }
    }
    return false;
}

ENVIRONMENT get_env_code(string env) {
    if (env.compare("java") == 0) {
        return JAVA;
    } else if (env.compare("cpp") == 0) {
        return CXX;
    } else if (env.compare("python") == 0) {
        return PYTHON;
    } else {
        return UNKNOWN_ENV;
    }
}

EXEC_POS get_execpos_code(string execpos) {
    if (execpos.compare("after") == 0) {
        return AFTER;
    } else if (execpos.compare("before") == 0) {
        return BEFORE;
    } else {
        return UNKNOWN_POS;
    }
}

vector<Hook> parse_hooks(toml::array* hooks) {
    vector<Hook> stored_bld_hooks = {};

    hooks->for_each([hooks, &stored_bld_hooks](toml::table hk) {
        Hook parsed_hk;

        optional<string> name = hk["name"].value<string>();
        if(name) {
            parsed_hk.name = *name;
        } else {
            parsed_hk.name = "default-hook";
        }

        optional<string> path = hk["path"].value<string>();
        if(path) {
            parsed_hk.path = *path;
        } else {
            parsed_hk.path = "./";
        }

        optional<string> command = hk["command"].value<string>();
        if(command) {
            parsed_hk.command = *command;
        } else {
            parsed_hk.command = "echo 'name'";
        }

        optional<string> when = hk["when"].value<string>();
        if(when) {
            parsed_hk.when = get_execpos_code(*when);
        } else {
            parsed_hk.when = BEFORE;
        }

        stored_bld_hooks.push_back(parsed_hk);
    });

    return stored_bld_hooks;
}

Generic_Spaceship parse_generic_base(toml::parse_result parse_res) {
    Generic_Spaceship generic_spaceship;

    optional<string> env = parse_res["environment"].value<string>();
    if(env) {
        generic_spaceship.environment = get_env_code(*env);
    } else {
        generic_spaceship.environment = UNKNOWN_ENV;
    }

    optional<string> pj_name = parse_res["project_name"].value<string>();
    if(pj_name) {
        generic_spaceship.name = *pj_name;
    } else {
        generic_spaceship.name = "mt-project";
    }

    optional<int> vs = parse_res["version"].value<int>();
    if(vs) {
        generic_spaceship.version = *vs;
    } else {
        generic_spaceship.version = 0;
    }

    return generic_spaceship;
}

Generic_Build_Opts parse_generic_build_opts(toml::node_view<toml::node> build_opts) {

    Generic_Build_Opts generic_build_opts;

    optional<string> build_dir = build_opts["build_dir"].value<string>();
    if(build_dir) {
        generic_build_opts.build_dir = *build_dir;
    } else {
        generic_build_opts.build_dir = "mt-build";
    }

    optional<string> build_path = build_opts["build_path"].value<string>();
    if(build_path) {
        generic_build_opts.build_path = *build_path;
    } else {
        generic_build_opts.build_path = "./";
    }

    return generic_build_opts;
}

void parse_spaceship() {
    try {
        ifstream spaceship("spaceship.toml");

        JavaUtils::Build_Opts build_opts;
        JavaUtils::Run_Opts run_opts;

        if (spaceship.is_open()) {
            toml::parse_result parsed_spaceship = toml::parse(spaceship);

            Generic_Spaceship generic_spaceship = parse_generic_base(parsed_spaceship);

            toml::node_view<toml::node> bld_opts = parsed_spaceship["build_opts"];
            if(bld_opts) {

                Generic_Build_Opts generic_build_opts = parse_generic_build_opts(bld_opts);

                toml::array* hook_array = bld_opts["hooks"].as_array();
                vector<Hook> hooks = parse_hooks(hook_array);

                cout << hooks.at(2).name;
            }

            optional<toml::node_view<toml::node>> run_opts = parsed_spaceship["run_opts"];
        } else {
            cout << "Error while opening spaceship.toml. Does the file exist in the current directory ?" << endl;
        }

    } catch (const toml::parse_error& err) {
        cerr << "Parsing failed" << endl;
        cerr << err.what() << endl;
    } catch (const std::bad_optional_access& err) {
        cerr << "Access error" << endl;
        cerr << err.what() << endl;
    }
}
