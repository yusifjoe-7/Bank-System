#include <sqlite3.h>
#include <iostream>

#include "sql.hpp"

void SQL_FNs::main_fn(){
    sqlite3* db = nullptr;

    if (sqlite3_open("bank.db", &db) != SQLITE_OK) {
           std::cerr << sqlite3_errmsg(db) << '\n';
           exit(1);
       }



    //a logic code here


    // at the last
     sqlite3_close(db);
}
