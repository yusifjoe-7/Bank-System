#include "../cli_prosesses.hpp"
#include "../cli_loops.hpp"
#include <iostream>
#include <ostream>


std::vector<std::string>CLI_prosess::signup(){
    std::vector<std::string> input;
    std::string token;
    CLI_loops::fr_p(input);
    while (1) {
        std::cout<<"[1] customer, [2] employer, [3] manager " << std::endl;
        std::cout<<"choose a number => ";
        std::cin>> token;
        if(token == "1" ||token == "2" ||token == "3" ){
            input.push_back(token);
            return input;
        }
    }
    
}