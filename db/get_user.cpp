#include "./sql.hpp"
#include <iostream>
#include <sqlite3.h>
#include "../security/security.hpp"


void SQL_get::check_log(const std::string username, const std::string password,User& user){
    sqlite3* db;
    
    sqlite3_open("bank.db", &db);
    
    sqlite3_stmt* stmt;
    
    sqlite3_prepare_v2(
        db,
        "SELECT * FROM users WHERE username = ?;",
        -1,
        &stmt,
        nullptr
    );
    
    sqlite3_bind_text(stmt, 1, username.c_str(), -1 ,SQLITE_TRANSIENT);
    
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
    
        const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        const char* hashed_password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        int role = sqlite3_column_int(stmt, 2);

        int n = Security::decode(password,hashed_password);

        if(n == 0){
            user.name = username;
            user.type_num = role;
            return;
            
        }else{
            std::cerr<<"wrong user or password"<<std::endl;
        }
    }

    
    
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}