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
        int type_num;
        friend class SQL_get;
        friend class Working;

    public:
        uint16_t get_token();

};

class Customer : User{
    private:
        //int hash_save_p();
        int make_a_transfer_p();
        int ask_for_a_loan_p();
        int make_a_deposit_p();
        int fixed_deposits_p();
        void load_fixed();
        void load_trnsfares();
        std::vector<fixed_deposits> fixed_deposits_vec;
        std::vector<trnsfares> trnsfares_vec;
        void load_balance();
        double balance;
        friend class Working;
        
        
    public:
        const Rules rule = CUSTOMER;
        //void hash_save_passord();
        void make_a_transfer();
        void ask_for_a_loan();
        void make_a_deposit();
        void fixed_deposit();
        void check_balance();
        void check_fixed();
        void check_trnsfares();
        
};

class Employer : User{
    private:
        void louad_loan_application_p();
        std::vector<loan_app> loans;
        friend class Working;

    public:
        void louad_load_application();
};
 

