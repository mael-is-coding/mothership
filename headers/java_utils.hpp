
#ifndef JAVA_UTILS_HPP
#define JAVA_UTILS_HPP

#include "hook.hpp"
#include "spaceship_utils.hpp"
#include "toml.hpp"
#include <vector>

using namespace std;

namespace JavaUtils {

    class Build_Opts: Generic_Build_Opts {
        public:
            vector<Hook> hooks;
            string path;
    };

    class Run_Opts {
        public:
            vector<Hook> hooks;
            string build_dir;
            string path;
    };

    JavaUtils::Build_Opts parseBuildOpts(toml::node_view<toml::node>);
    JavaUtils::Run_Opts parseRunOpts(toml::node_view<toml::node>);
}

#endif