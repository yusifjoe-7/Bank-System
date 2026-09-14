#pragma once
#include "../models/user_models.hpp"

#include <cstdint>
#include <string>
#include <vector>

class Security{
  private:
    friend class User;
    friend class acount_repository;
    friend class SQL_get;
    static std::string hashing_password(const std::string& password);
    static bool decode(const std::string& password, const std::string& hased_password);
    static UUID create_a_uuid();
    //bool chack_access();
    int make_a_transfare();
    std::string get_free_employers();
};

class acount_repository{
    private:
        static void create_emplyer();
        static void create_manager();

    public:
        static void create_user(const std::vector<std::string> vec, const char* sql);
        static void crate_ask_for_acount();
};


class logs{
    public:
        static User login(const std::string username, const std::string password);
};