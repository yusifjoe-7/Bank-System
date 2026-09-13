#pragma once
#include "../models/models.hpp"

#include <cstdint>

class Security{
  private:
    friend class User;
    uint32_t hashing_password();
    bool chack_access();
    int make_a_transfare();
    std::string get_free_employers();
};

class acount_repository{
    private:
        void create_emplyer_p();
        void create_manager_p();

    public:
        static void create_customer();
        static void create_emplyer();
        static void create_manager();
};