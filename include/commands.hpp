#pragma once

#include <iostream>
#include <vector>
#include <string>
#include </home/anurag/Documents/C++/MySqueel/MySqueel/include/globals.hpp>
#include </home/anurag/Documents/C++/MySqueel/MySqueel/include/databases.hpp>

#define print std::cout << 
#define nl << std::endl;

// every command has a unique number that identifies which function to call

typedef struct command{
    std::string name;
    std::vector<std::string> properties;
} Command;


// commands
std::vector<std::string> first_words = {
    "DROP", "CREATE", "RENAME", 
    "ALTER", "UPDATE", "SELECT", "INSERT",
    "SHOW", "DESCRIBE"};


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
                name_expected = true;

                command_set = command.properties;
                break;
            // show
            case 8:
                command.name = "SHOW";
                command.properties = {
                    "TABLES",
                    "DATABASES"
                };

                command_set = command.properties;
                break;
            
            // Describe
            case 9:
                command.name = "DESCRIBE";
                command.properties = {};
                name_expected = true;

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

int reverseNumber(int num){
    int result = 0;
    while(num){
        result = result*10 + (num%10);
        num /= 10;
    }

    return result;
}

bool checkKeyword(std::string name){
    for(int i = 0; i < keywords.size(); i++){
        if(name == keywords[i]){
            return false;
        }
    }
    return true;
}

int runCommand(int command_number, std::vector<std::string> command, Database current_database){
    command_number = reverseNumber(command_number);
    int initial_command;
    while(command_number){
        initial_command = command_number % 10;

        switch(initial_command){
            case 1:
                // drop
                command_number /= 10;
                initial_command = command_number % 10;
                
                if(!checkKeyword(command[2])){
                    print "INVALID Name!" nl;
                    return -1;
                }

                // Table
                if(initial_command == 1){
                    std::string table_to_delete = command[2];
                    std::vector<Table>::iterator itr;
                    bool flag = false;

                    for(itr = current_database.tables.begin(); itr != current_database.tables.end(); itr++){
                        if(itr -> tableName == table_to_delete){
                            flag = true;
                            break;
                        }
                    }

                    if(!flag){
                        std::cout << "INVALID NAME!" << std::endl;
                        return -1;
                    }
                }

                // Database
                if(initial_command == 2){
                    std::string database_to_delete = command[2];
                    std::vector<Database>::iterator itr;
                    bool flag = false;

                    for(itr = databases.begin(); itr != databases.end(); itr++){
                        if(itr -> databaseName == database_to_delete){
                            // destruct(*itr);
                            flag = true;
                            break;
                        }
                    }
                    if(!flag){
                        std::cout << "INVALID NAME!" << std::endl;
                        return -1;
                    }
                }
                break;
            
            case 2:
                // create
                command_number /= 10;
                initial_command = command_number % 10;
                
                if(!checkKeyword(command[2])){
                    print "INVALID Name!" nl;
                    return -1;
                }

                // Table
                if(initial_command == 1){
                    std::string new_table_name = command[2];
                    Table* new_table = new Table(new_table_name);
                    current_database.tables.push_back(*new_table);

                    print "A table named " << new_table_name << " created" nl;
                    return 0;
                }

                // Database
                if(initial_command == 2){
                    std::string new_database_name = command[2];
                    Database new_database(new_database_name);
                    databases.push_back(new_database);

                    print "A database named " << new_database_name << " created" nl;
                    return 0;
                }
                break;
            
            // case 3:
            //     // RENAME
            //     command.name = "RENAME";
            //     command.properties = {
            //         "TABLE",
            //         "DATABASE"
            //     };

            //     command_set = command.properties;
            //     break;

            
            // case 4:
            // // alter
            //     command.name = "ALTER";
            //     command.properties = {
            //         "TABLE"
            //     };

            //     command_set = command.properties;
            //     break;

            // case 5:
            //     // update
            //     command.name = "UPDATE";
            //     command.properties = {
            //         "TABLE"
            //     };

            //     command_set = command.properties;
            //     break;
            
            // case 6:
            //     // select
            //     // syntax: select table table_name
            //     command.name = "SELECT";
            //     command.properties = {
            //         "TABLE"
            //     };

            //     command_set = command.properties;
            //     break;
            
            // case 7:
            //     // insert
            //     // syntax : insert table_name;
            //     command.name = "INSERT";
            //     command.properties = {};
            //     name_expected = true;

            //     command_set = command.properties;
            //     break;
            // // show
            // case 8:
            //     command.name = "SHOW";
            //     command.properties = {
            //         "TABLES",
            //         "DATABASES"
            //     };

            //     command_set = command.properties;
            //     break;
            
            // // Describe
            // case 9:
            //     command.name = "DESCRIBE";
            //     command.properties = {};
            //     name_expected = true;

            //     command_set = command.properties;
            //     break;

            default:
                std::cout << "Command NOT found!" << std::endl;
                break;
        }
    }
    return -1;
}