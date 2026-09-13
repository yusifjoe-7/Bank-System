#pragma once
#include <cstdint>
#include <vector>
#include "../rules.hpp"
#include "data.hpp"

class User{
    private: 
        UUID id;
        std::string name;
        std::uint32_t hashed_passowrd;
        std::uint16_t token;

    public:
        uint16_t get_token();

};

class Customer:User{
    private:
        //int hash_save_p();
        int make_a_transfer_p();
        int ask_for_a_loan_p();
        int make_a_deposit_p();
        int fixed_deposits_p();
        void load_fixed();
        void load_trnsfares();
        std::vector<fixed_deposits> fixed_deposits_vec;
        std::vector<trnsfares> trnsfares;
        void load_balance();
        double balance;
        
        
    public:
        const Rules rule = CUSTOMER;
        //void hash_save_passord();
        void make_a_transfer();
        void ask_for_a_loan();
        void make_a_deposit();
        void fixed_deposits();
        void check_balance();
        void check_fixed();
        void check_trnsfares();
        
};
 

