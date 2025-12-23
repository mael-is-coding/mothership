
#ifndef JAVA_UTILS_HPP
#define JAVA_UTILS_HPP

#include "hook.hpp"
#include "toml.hpp"
#include <optional>
#include <vector>

using namespace std;

namespace JavaUtils {

    class Build_Opts {
        public:
            optional<vector<Hook>> hooks;
            optional<string> build_dir;
            optional<string> path;
    };

    class Run_Opts {
        public:
            optional<vector<Hook>> hooks;
            optional<string> build_dir;
            optional<string> path;
    };

    JavaUtils::Build_Opts parseBuildOpts(toml::node_view<toml::node>);
    JavaUtils::Run_Opts parseRunOpts(toml::node_view<toml::node>);
}

#endif