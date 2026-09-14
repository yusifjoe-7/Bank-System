#include "./security.hpp"
#include <sodium.h>
#include <string>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>


std::string Security::hashing_password( const std::string& password){
    char hashed_password[crypto_pwhash_STRBYTES];
    
        if (crypto_pwhash_str(
                hashed_password,
                password.c_str(),
                password.length(),
                crypto_pwhash_OPSLIMIT_INTERACTIVE, 
                crypto_pwhash_MEMLIMIT_INTERACTIVE  
            ) != 0) {
            throw std::runtime_error("Out of memory during hashing");
        }
    
        return std::string(hashed_password);
}

UUID Security::create_a_uuid(){
    boost::uuids::random_generator generato;
    return generato();
}

bool Security::decode(const std::string& password, const std::string& hashedPassword){
    return crypto_pwhash_str_verify(
            hashedPassword.c_str(),
            password.c_str(),
            password.length()
        ) == 0;
}