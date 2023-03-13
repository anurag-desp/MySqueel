#pragma once

#include <iostream>
#include <vector>
#include <string>

#define print std::cout << 
#define nl << std::endl;

// every command has a unique number that identifies which function to call

typedef struct command{
    std::string name;
    std::vector<std::string> properties;
} Command;


// commands
std::vector<std::string> first_words = {
    "SHOW", "DESCRIBE", "DROP", "CREATE", "RENAME", 
    "ALTER", "UPDATE", "SELECT", "INSERT"};


int findCommand(std::vector<std::string> user_command){
    int command_size = user_command.size();
    int answer = 0;
    int last_command;
    
    bool found = false;
    bool name_expected = false; // whether a user given name is expected
    bool flag = true;

    if(user_command[command_size-1] != ";")
        return -1;

    std::vector<std::string> command_set = first_words;  
    Command command;
    command.name = "NILL";

    for(int i = 0; i < command_size-1; i++){
        for(int j = 0; j < command_set.size(); j++){
            if(user_command[i] == command_set[j]){
                last_command = j+1;
                answer = answer*10 + (last_command);
                found = true;

                break;
            }
        }
        if(!name_expected){
            if(!found)
                return -1;
        }
        else{
            name_expected = false;
            flag = true;
        }
        
        if(command.name != "NILL"){
            if (!flag)
                name_expected = true;

            command_set.clear();
            continue;
        }

        switch(last_command){
            case 1:
                // drop
                command.name = "DROP";
                command.properties = {
                    "TABLE",
                    "DATABASE"
                };

                command_set = command.properties;
                break;
            
            case 2:
                // create
                command.name = "CREATE";
                command.properties = {
                    "TABLE",
                    "DATABASE"
                };

                command_set = command.properties;
                break;
            
            case 3:
                // RENAME
                command.name = "RENAME";
                command.properties = {
                    "TABLE",
                    "DATABASE"
                };

                command_set = command.properties;
                break;

            
            case 4:
            // alter
                command.name = "ALTER";
                command.properties = {
                    "TABLE"
                };

                command_set = command.properties;
                break;

            case 5:
                // update
                command.name = "UPDATE";
                command.properties = {
                    "TABLE"
                };

                command_set = command.properties;
                break;
            
            case 6:
                // select
                // syntax: select table table_name
                command.name = "SELECT";
                command.properties = {
                    "TABLE"
                };

                command_set = command.properties;
                break;
            
            case 7:
                // insert
                // syntax : insert table_name;
                command.name = "INSERT";
                command.properties = {};

                command_set = command.properties;
                break;

            default:
                std::cout << "Command NOT found!" << std::endl;
                break;
        }

        found = false;
    } 
    if(name_expected){
        return -1;
    }

    return answer;
}

