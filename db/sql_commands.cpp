#include "./sql_commands.hpp"

const char* create_user =
        "INSERT INTO users(UUID, username, hashed_password, role)"
        "VALUES(?,?,?,?)";


// CREATE A CREATE REQUEST
const char* create_create_request =
    "INSERT INTO create_requests(UUID, username, hashed_password, role)"
    "VALUES(?,?,?,?)";
