
#include "../types.hpp"
#include "sql.hpp"
#include <sqlite3.h>
#include <string>




//              or requet
int SQL_create::add_user( const UUID& id, const std::string& name, const std::string& hashed_passowrd, const int& role, const char* sql){
    sqlite3* db = nullptr;

    if (sqlite3_open("bank.db", &db) != SQLITE_OK) {
           std::cerr << sqlite3_errmsg(db) << '\n';
           exit(1);
       }


    
    sqlite3_stmt* stmt;

    

    
    // sqlite3_stmt* stmt = nullptr;

    // 3. Prepare
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        exit(1);
    }
 

    // const auto enum_num = [role, db]()-> int{
    //     switch (role) {
    //         case CUSTOMER: return 1;
    //         case EMPLOYER: return 2;
    //         case MANAGER: return 3;
    //         default: std::cerr<< "enum error\n"; sqlite3_close(db); break;
    //     }
    // }();

    std::string Uid;
    for(auto &&i : id){
        Uid += std::to_string(i);
    }
    
    sqlite3_bind_text(stmt, 1, Uid.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, name.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, hashed_passowrd.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 4, role);
    
    int rc = sqlite3_step(stmt);
    
        if (rc != SQLITE_DONE) {
            std::cerr << "SQL error: "
                      << sqlite3_errmsg(db)
                      << '\n';
    
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return 1;
       
        }

    if(role == 1){
        // for print ACOUNT CREATES or REQUEST SAVED
    }


    // at the end
     sqlite3_finalize(stmt);
     sqlite3_close(db);
     return 0;
}