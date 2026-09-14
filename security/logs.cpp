#include "./security.hpp"
#include "../db/sql.hpp"
#include <string>

User logs::login(const std::string username, const std::string password){
    User log_user;
    SQL_get::check_log(username, password, log_user);
    
    
}