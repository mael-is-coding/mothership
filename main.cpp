
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "spaceship_utils.hpp"
#include "general_actions.hpp"

using namespace std;

int main(int argc, char** argv) {

    bool isSpaceshipPresent = locate_spaceship();

    switch(argc) {
        case 1:
            mothership_help();
            break;

        case 2:
            if(strcmp(argv[1], "init") == 0) {
                cout << "the environment argument is missing" << endl;
                cout << "please specify one of 'java', 'python' or 'cpp'" << endl;
            }

            if(strcmp(argv[1], "build") == 0) {
                if(isSpaceshipPresent) {
                    cout << "[mothership] Building project..." << endl;
                    cout << "[mothership] parsing spaceship.toml" << endl;
                    parse_spaceship();
                } else {
                    cout << "No spaceship configuration file found in current directory" << endl;
                    cout << "Please call mothership init, or cd to a directory with spaceship.toml" << endl;
                }
            }

            if(strcmp(argv[1], "run") == 0) {
                if(isSpaceshipPresent) {
                    cout << "[mothership] Running project..." << endl;
                    cout << "[mothership] parsing spaceship.toml" << endl;
                    parse_spaceship();
                } else {
                    cout << "No spaceship configuration file found in current directory" << endl;
                    cout << "Please call mothership init, or cd to a directory with spaceship.toml" << endl;
                }
            }
            break;

        case 3:
            if(strcmp(argv[1], "init") == 0) {
                cout << "the project name argument is missing, please specify one" << endl;
            }
            break;

        case 4:
            if(strcmp(argv[1], "init") == 0) {
                if(isSpaceshipPresent) {
                    string answer;

                    cout << "spaceship.toml is present in this directory. Overwrite it ? [Y/n]" << endl;
                    cout << "mt $ ";
                    getline(cin, answer);

                    while(
                        (answer.compare("y") != 0) && 
                        (answer.compare("Y") != 0) &&
                        (answer.compare("N") != 0) && 
                        (answer.compare("n") != 0) &&
                        !(answer.empty())
                    ) {
                        cout << "please choose a valid answer" << endl;
                        cout << "mt $ ";
                        getline(cin, answer);
                    }

                    if(
                        (answer.compare("y") == 0) || 
                        (answer.compare("Y") == 0) ||
                        (answer.empty())
                    ) {
                        mothership_init(argv[2], argv[3]);
                    } else if (
                        (answer.compare("N") == 0) || 
                        (answer.compare("n") == 0) ||
                        (answer.compare("exit"))
                    ) {
                        cout << "Nothing was overwritten !" << endl;
                    } else {
                        cout << "wtf are you doing here" << endl;
                    }
                } else {
                    mothership_init(argv[2], argv[3]);
                }
            }
            break;

        default:
            cout << "???";
            break;
    }

    return 0;
}