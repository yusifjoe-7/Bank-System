
#include "../types.hpp"
#include "sql.hpp"


void SQL_FNs::add_customer( UUID id, std::string name, std::uint32_t hashed_passowrd){
    sqlite3* db = nullptr;

    if (sqlite3_open("bank.db", &db) != SQLITE_OK) {
           std::cerr << sqlite3_errmsg(db) << '\n';
           exit(1);
       }
    
    const char* sql =
        "INSERT INTO customers(UUID, username, hashed_password)"
        "VALUE(?,?,?)";

    
    sqlite3_stmt* stmt = nullptr;

    // 3. Prepare
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << sqlite3_errmsg(db) << '\n';
        sqlite3_close(db);
        exit(1);
    }

    


    // at the end
     sqlite3_close(db);
}