#include <iostream>
#include <string>
#include <queue>


std::vector<std::string> digit_generator(std::size_t count){
    std::queue<std::string> num_queue;
    std::vector<std::string> output_vector;
    num_queue.push(std::string(""));

    for(auto iter = 0; iter < count; iter++){
        std::string current = num_queue.front();
        num_queue.pop();
        num_queue.push(current + std::string("0"));
        num_queue.push(current + std::string("1"));
        output_vector.push_back(current);
    }
    return output_vector;
}


int main(void){
    std::vector<std::string> numbers = digit_generator(16);
    for(auto const& num: numbers)
        std::cout << num << '\n';
    return 0;
}
