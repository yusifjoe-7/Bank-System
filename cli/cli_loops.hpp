#pragma once

#include <string>
#include <vector>

class CLI_loops{
    public:
        static int fr_print();
        static std::vector<std::string> loop_print(std::string rule, std::string name);
        static void Done(std::string x);
        static void fr_p( std::vector<std::string>& vec);
        static std::string main_work_print(const std::string username, const std::string role);
};