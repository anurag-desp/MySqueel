#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Database{
    public:
        std::string databaseName;
        std::vector<Table> tables;
        Database(): databaseName("unknown"){};
        
        Database(std::string dbName): databaseName(dbName){};
        
        void getName(){
            std::cout << databaseName;
        }
};

class Table: public Database{
    public:
        std::string tableName;
        
        Table(std::string name): tableName(name) {};
        Table(): tableName("Unknown") {};
};
