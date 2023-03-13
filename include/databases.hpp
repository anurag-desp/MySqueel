#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Database{
    std::string databaseName;
    public:
        Database(): databaseName("unknown"){};
        
        Database(std::string dbName): databaseName(dbName){};
        void getName(){
            std::cout << databaseName;
        }
};
