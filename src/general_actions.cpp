
#include <fstream>
#include <iostream>
#include "general_actions.hpp"
#include "environment.hpp"
#include "spaceship_utils.hpp"

using namespace std;

void mothership_help() {
    cout << "Mothership beta version" << endl;
    cout << "> supposed to be a versatile and simplistic project manager for prototyping";
    cout << "or beginners" << endl;
    cout << "\n";
    cout << "OPTIONS : " << endl;
    cout << "   help -- displays this help message" << endl << endl;
    cout << "   init <java | cpp | python> <project_name> -- creates a spaceship.toml file according to spec. environment" << endl << endl;
    cout << "   build -- builds current project if relevant, with specified hooks if any" << endl << endl;
    cout << "   run -- runs specified project, with specified hooks if any" << endl << endl;
}

/**
* @author Cosmos
* @brief Initializes a spaceship.toml files with given options
* @param project_name name of project. Read from stdin
* @param environment environment of project. Read from stdin
*/
void mothership_init(string project_name, string environment) {

    ofstream spaceship("./spaceship.toml");

    ENVIRONMENT envCode = get_env_code(environment);

    if(envCode == UNKNOWN_ENV) {
        cout << "the specified environment is unknown, please specify either" << endl;
        cout << "'java', 'python', 'cpp'" << endl;
    } else {
        if(spaceship.is_open()) {
            spaceship << "project_name = \"" << project_name << "\"" << endl;
            spaceship << "environment = \"" << environment << "\"" << endl;
            spaceship << "version = " << 0 << endl;

            cout << "Successfully created spaceship.toml in current directory ✅" << endl;
        } else {
            cerr << "Error while opening spaceship.toml, please check for reading/writing rights !" << endl;
        }
    }
}