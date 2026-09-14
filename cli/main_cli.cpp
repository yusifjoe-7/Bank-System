

#include "cli_loops.hpp"
#include "cli_prosesses.hpp"
#include "../security/security.hpp"
#include "../db/sql_commands.hpp"
#include <cstdlib>
#include <string>
#include <vector>
void main_loop(){
    int input = CLI_loops::fr_print();
    
    switch (input) {
    case 1:
        exit(1);
        break;
    case 2:
        std::vector<std::string> data = CLI_prosess::signup(); 
        switch (data[2][0]) {
            case '1':
                acount_repository::create_user(data, create_user);
                break;
            case '2':
            case '3':
               acount_repository::create_user(data, create_create_request);
                break;              //or request
        }
        break;
    }
}