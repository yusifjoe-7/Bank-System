
#include "security.hpp"
#include "../db/sql.hpp"
#include "../cli/cli_loops.hpp"

void acount_repository::create_user(const std::vector<std::string> vec, const char* sql){
    UUID id = Security::create_a_uuid();
    std::string hash_password = Security::hashing_password(vec[1]);
    int role = vec[2][0] - '0';

    if(SQL_create::add_user(id, vec[0], hash_password, role, sql) == 0){
        CLI_loops::Done("user criation");
    }
}


