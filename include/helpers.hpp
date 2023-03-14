#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cctype>


#define print std::cout << 
#define nl << std::endl;

void toUpper(std::string& str){
    for(int i = 0; i < str.length(); i++){
        if(isalpha(str[i])){
            str[i] = toupper(str[i]);
        }
    }
}
std::vector<std::string> splitString(std::string str, char delimiter){
    str.insert(str.length()-1, " "); // inserting a space between the last word and ;

    std::string last_word = "";
    std::vector<std::string> result;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == delimiter){
            toUpper(last_word);
            result.push_back(last_word);
            last_word = "";
        }
        else
            last_word += str[i];
    }
    if(last_word != "")
        toUpper(last_word);
        result.push_back(last_word);
    
    // for(auto i = 0; i < result.size(); i++){
    //     print result[i] nl;
    // }
    
    return result;
}