#include <algorithm>
#include <string>

// why is this not a thing in c++ already
void convertToLowercase(std::string & temp){
    std::transform(temp.begin(), temp.end(), temp.begin(), [](unsigned char c){return std::tolower(c);});
}
// convert all characters to uppercase
void convertToUppercase(std::string & temp){
    std::transform(temp.begin(), temp.end(), temp.begin(), [](unsigned char c){return std::toupper(c);});
}
