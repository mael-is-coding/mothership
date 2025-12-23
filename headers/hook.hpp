#ifndef HOOK_HPP
#define HOOK_HPP

#include <optional>
#include <string>
using namespace std;

enum ExecPosition {
    BEFORE,
    AFTER
};

class Hook {
    public:
        optional<string> name;
        optional<string> command;
        optional<string> path;
        optional<ExecPosition> when;
};

#endif