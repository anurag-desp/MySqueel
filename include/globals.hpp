#include <string>
#include <vector>
#include </home/anurag/Documents/C++/MySqueel/MySqueel/include/databases.hpp>

std::vector<std::string> keywords = {
    "TABLE", "TABLES", "DATABASE", "DATABASES",
    "INSERT", "SHOW", "DESCRIBE", "CREATE", "DROP",
    "SELECT", "ALTER", "RENAME", "DELETE",
    "SET", "UPDATE", "WHERE", "INT", "STRING",
    "CHAR" 
};

std::vector<Database> databases; // read the file