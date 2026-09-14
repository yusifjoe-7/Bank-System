#pragma once
#include <cstdint>
#include <sqlite3.h>
#include <iostream>
#include <string>
#include <vector>
#include "../types.hpp"
#include "../models/user_models.hpp"



class SQL_create{
    private:
        friend class User;
        friend class acount_repository;
        static int add_user(const UUID& id, const std::string& name, const std::string& hashed_passowrd, const int& role, const char* sql);
};

class SQL_get{
    private:
        friend class logs;
        static void check_log(const std::string username, const std::string password, User& user);
};


