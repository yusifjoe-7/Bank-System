#pragma once
#include <string>
#include "../types.hpp"

enum Profit_system{
    MONTHLY,
    QURTERYEAR,
    HALFYEAR,
    YEAR,
};

class fixed_deposits{
    private:
        std::string user_name;
        UUID user_id;
        std::string start_date;
        std::string end_date;
        float profit;
        Profit_system PS;
};

class trnsfares{
    private:
        UUID from;
        UUID to;
        std::string date;
        std::string time;
        float value;
};


