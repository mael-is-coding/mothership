
#include <cerrno>
#include <iostream>
#include <optional>
#include <sys/types.h>
#include <dirent.h>
#include <cstring>
#include <fstream>
#include "java_utils.hpp"
#include "toml.hpp"

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

void parse_spaceship() {
    try {
        ifstream spaceship("spaceship.toml");

        string project_name;
        string environment;
        int version = -1;
        JavaUtils::Build_Opts build_opts;
        JavaUtils::Run_Opts run_opts;

        if (spaceship.is_open()) {
            toml::parse_result parsed_spaceship = toml::parse(spaceship);

            optional<string> pj_name = parsed_spaceship["project_name"].value<string>();

            if(pj_name) {
                project_name = *pj_name;
            }

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

ENVIRONMENT get_env_code(string env) {
    if (env.compare("java") == 0) {
        return JAVA;
    } else if (env.compare("cpp") == 0) {
        return CXX;
    } else if (env.compare("python") == 0) {
        return PYTHON;
    } else {
        return UNKNOWN;
    }
}

