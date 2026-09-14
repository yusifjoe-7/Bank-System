#include "cli_loops.hpp"
#include <iostream>
#include <sstream>
#include <vector>


int CLI_loops::fr_print(){
    char input[2];
    while (1) {
        std::cout<<"\nplease login"<<std::endl;
        std::cout<<"[1] for login"<<std::endl;
        std::cout<<"[2] for signup"<<std::endl;
        std::cout<<"=> ";
        
        std::cin.width(2);
        std::cin>>input;
        try{
            int num_input = input[0] - '0';
            if(num_input == 1 || num_input == 2){
                return num_input;
            }
            std::cout<<"wrong input"<<std::endl;
        }catch(const char* msg){
            std::cout<<"somting is wrong: "<<msg<<std::endl;
        }
    }
}

std::vector<std::string> CLI_loops::loop_print(std::string role, std::string name){
    std::vector<std::string> input_vec;
    std::string input;
    std::cout<<"{ "<< role << " } "<< name <<" => "<<std::endl;

    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        input_vec.push_back(token);
    }
    return input_vec;
    
}

void CLI_loops::Done(std::string x){
    std::cout<<"The "<< x << " have done sucssefly"<<std::endl;
}

void CLI_loops::fr_p(std::vector<std::string>& vec){
    std::string token;
    std::cout<<"you name => ";
    std::cin>>token;
    vec.push_back(token);
    std::cout<<"you password => ";
    std::cin>>token;
    vec.push_back(token);
    
}

std::string CLI_loops::main_work_print(const std::string username, const std::string role){
    std::string input;
    std::cout<<" { "<< role << " } " << username << " => ";
    std::cin>> input;
    return input;
}

