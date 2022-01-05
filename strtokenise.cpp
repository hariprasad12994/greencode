#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>


std::vector<std::string> str_tokenise(std::string input_str){
    std::stringstream stream(input_str);
    std::vector<std::string> output_vector;
    std::string line;
    const char* delimiter_array = " ,'-;";

    while(std::getline(stream, line)){
        std::size_t prev = 0, pos = 0;
        pos = line.find_first_of(delimiter_array, prev);
        while(pos != std::string::npos){
            if(pos > prev){
                //std::cout << line.substr(prev, pos - prev);
                output_vector.push_back(line.substr(prev, pos - prev));
            }
            prev = pos + 1;
            pos = line.find_first_of(delimiter_array, prev);
        }
        if(prev < line.length())
            output_vector.push_back(line.substr(prev, std::string::npos));
    }
    return output_vector;
}


int main(void){
    std::vector<std::string> tokenised_str = str_tokenise(std::string("Hello world, this is a sample string"));
    for(auto const& str: tokenised_str)
        std::cout << str << '\n';
    return 0;
}
