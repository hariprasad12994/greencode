#include <string>
#include <iostream>
#include <fstream>
#include <stack>
#include <map>


class JSONBase{
};

class JSON : public JSONBase{
    // depth wise iteration on the stream in two aspects
    // first is for the current node pushing and popping based on the top of the
    // stack. other is the depth wise iteration of the tree itself
    // cases to be handled with the stack anything-}, "-,. "-", "-:, {-, {-{,
    // ,-", [-", [-{, }-], "-] etc
    // code can be done in multiple iterations. 
    // single json node. single json node with arrays?, recursive tree
    // decide whether [] operator has to be overloaded. 
    // decide the data structure and abstract data structure to be used for the
    // recursion. Create a new element when top of stack == current cursor == {
    // to also overload the stream operators
    private:
    std::stack<char> parsing_stack;
    std::map<std::string, JSON> json;

    public:

};

int main(int argc, char* argv[]){
    std::ifstream json_file("sample.json");
    std::string json_file_content(std::istreambuf_iterator<char>(json_file), {});
    std::cout << json_file_content << '\n';

    std::map<std::string, std::string> json_dict;
    std::stack<char> parsing_stack;
    unsigned int line = 1, col = 0;
    bool is_parsing_done = false;

    for(auto it = json_file_content.begin(); it != json_file_content.end(); ++it){
        col++;
        switch(*it){
            case '\n':
                col = 0;
                line++;
                break;
            case '{':
                parsing_stack.push(*it);
                break;
            case '}':
                if(parsing_stack.empty())
                    std::cout << "Error, mismatched parathesis @line" << line << ", @col" << col << '\n';
                if(parsing_stack.top() == '{'){
                    parsing_stack.pop();
                }
                break;
            case ':':
                break;
            case ',':
                break;
            case '"':
                parsing_stack.push(*it);
                break;
            case ' ':
                break;
            default:
                break;
        }
    }
    //if(!parsing_stack.empty()) std::cout << "Invalid json" << '\n';
    std::cout << "line count = " << line << '\n';
    return 0;
}
