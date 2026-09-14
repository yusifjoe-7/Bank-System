#pragma once

#include "../../models/user_models.hpp"
#include "../cli_loops.hpp"
#include <string>

class Working{
    public:
        static void cutomer(User& user);
        static void employer(User& user);
        static void manager(User& user);
};

class print_ability{
    public:
        static std::string customer();
};