#pragma once
#include <cstdint>
#include <sqlite3.h>
#include <iostream>

#include "../types.hpp"


class SQL_FNs{
    private:
        friend class User;
        static void add_customer(UUID id, std::string name, std::uint32_t hashed_passowrd);
};