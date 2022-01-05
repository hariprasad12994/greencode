#include <iostream>
#include <algorithm>
#include <string>

unsigned int longest_common_subsequence(std::string seq_1, std::string seq_2, std::size_t seq_1_idx, std::size_t seq_2_idx){
    // std::cout << "Comparing " << seq_1 << " and " << seq_2 << '\n';

    if(seq_1_idx == 0 || seq_2_idx == 0)
        return 0;

    if(seq_1.at(seq_1_idx - 1) == seq_2.at(seq_2_idx - 1))
        return 1 + longest_common_subsequence(seq_1.substr(0, seq_1_idx - 1), seq_2.substr(0, seq_2_idx - 1), seq_1_idx - 1, seq_2_idx - 1);

    return std::max(longest_common_subsequence(seq_1.substr(0, seq_1_idx - 1), seq_2.substr(0, seq_2_idx), seq_1_idx - 1, seq_2_idx),
            longest_common_subsequence(seq_1.substr(0, seq_1_idx), seq_2.substr(0, seq_2_idx - 1), seq_1_idx, seq_2_idx - 1));
}

int main(void){
    std::cout << longest_common_subsequence(std::string("ABDACDA"), std::string("ABADCE"), 7, 6) << '\n';
    std::cout << longest_common_subsequence(std::string("aggtab"), std::string("gxtxayb"), 6, 7) << '\n';
    std::cout << longest_common_subsequence(std::string("ABAA"), std::string("ABADCE"), 4, 6) << '\n';

    return 0;
}

