#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <cmath>


class Graph{
    private:
        std::vector<bool> visited_;
        std::map<int, std::list<int>> adj_matrix_;
        int node_cnt_;

    public:
        Graph(int num_of_nodes, const std::vector<int>& from, const std::vector<int>& to){
            node_cnt_ = num_of_nodes;

            visited_.reserve(num_of_nodes);
            
            for(auto node_cnt = 1; node_cnt <= num_of_nodes; ++node_cnt){
                adj_matrix_[node_cnt] = std::list<int>();
            }

            for(auto node_iter = 0; node_iter < from.size(); ++node_iter){
                std::cout << "Adding node " << from[node_iter] << "->" << to[node_iter] << '\n';
                adj_matrix_[from[node_iter]].push_back(to[node_iter]);
            }
        }

        void add_edge(int from, int to){
            adj_matrix_[from].push_back(to);
        }

        void DFS(int vertex){
            visited_[vertex] = true;
            for(auto iter = adj_matrix_[vertex].begin(); iter != adj_matrix_[vertex].end(); ++iter){
                if(!visited_[*iter]){
                    std::cout << *iter << ' ';
                    visited_[*iter] = true;
                    DFS(*iter);
                }
            }
        }

        void component_count(int vertex, int& count){
            visited_[vertex] = true;
            for(auto iter = adj_matrix_[vertex].begin(); iter != adj_matrix_[vertex].end(); ++iter){
                if(!visited_[*iter]){
                    visited_[*iter] = true;
                    count++;
                    component_count(*iter, count);
                }
            }
        }

        int connected_sum(){
            int sum = 0;
            for(auto iter = 1; iter <= node_cnt_; ++iter){
                if(!visited_[iter]){
                    int count = 0;
                    component_count(iter, count);
                    std::cout << "count = " << count << '\n';
                    sum += std::ceil(std::sqrt(count + 1));
                }
            }
            return sum;
        }
};

int main(){
    std::vector<int> from_1{1, 1};
    std::vector<int> to_1{2, 4};
    Graph h(4, from_1, to_1);
    std::cout << h.connected_sum() << '\n';
    std::cout << '\n';

    std::vector<int> from{1, 1, 2, 3, 7};
    std::vector<int> to{2, 3, 4, 5, 8};
    Graph g(10, from, to);
    std::cout << g.connected_sum() << '\n';
    //g.DFS(1);
    //std::cout << '\n';
    //g.DFS(6);
    //std::cout << '\n';

    return 0;
}

