#include "../cli_prosesses.hpp"
#include "../cli_loops.hpp"

std::vector<std::string> CLI_prosess::login(){
    std::vector<std::string> input;
    CLI_loops::fr_p(input);
    return input;
}