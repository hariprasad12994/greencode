#include <iostream>
#include <vector>
#include <queue>


struct FreeServer{
    int id;
    int weight;
    FreeServer(int id, int weight): weight(weight), id(id) {}
    friend bool operator<(const FreeServer& lhs, const FreeServer& rhs) { return lhs.weight < rhs.weight && (lhs.weight == rhs.weight && lhs.id < rhs.id); }
    friend bool operator>(const FreeServer& lhs, const FreeServer& rhs) { return !(lhs < rhs); }
};

struct OccupiedServer{
    int id;
    int time_posted;
    int task_execution_time;
    OccupiedServer(int id, int time_posted, int task_execution_time): id(id), time_posted(time_posted), task_execution_time(task_execution_time) {}
    friend bool operator<(const OccupiedServer& lhs, const OccupiedServer& rhs) { return lhs.task_execution_time < rhs.task_execution_time; }
    friend bool operator>(const OccupiedServer& lhs, const OccupiedServer& rhs) { return !(lhs < rhs); }
};


void scheduler(const std::vector<int>& servers, const std::vector<int>& tasks, std::vector<int>& schedule) {
    std::priority_queue<FreeServer, std::vector<FreeServer>, std::greater<FreeServer>> free_servers;
    std::priority_queue<OccupiedServer, std::vector<OccupiedServer>, std::greater<OccupiedServer>> occupied_servers; 

    for(std::size_t iter = 0; iter < servers.size(); iter++) {
        free_servers.push(FreeServer(iter, servers[iter]));
    }

    int time = 0;
    std::size_t task_id = 0;
    // poll for each second;
    while(task_id < tasks.size()) {
        if(!occupied_servers.empty()) {
            auto next_server_available = occupied_servers.top();
            auto time_elapsed = next_server_available.time_posted + time;
            if(time_elapsed < next_server_available.task_execution_time)
              break;
            if(time_elapsed >=  next_server_available.task_execution_time) {
              occupied_servers.pop();
              std::cout << "freed: " << next_server_available.id << '\n';
              free_servers.push(FreeServer(next_server_available.id, servers[next_server_available.id]));
            }
        }

        if(!free_servers.empty()) {
                auto current_available_server = free_servers.top();
                std::cout << "available: " << current_available_server.id << '\n';
                schedule.push_back(current_available_server.id);
                occupied_servers.push(OccupiedServer(current_available_server.id, time, tasks[task_id]));
                free_servers.pop();
                task_id++;
        }
        time++;
    }
}


int main(void) {
    std::vector<int> out;
    scheduler(std::vector<int>{3,3,2}, std::vector<int>{1, 2, 3, 2, 1, 2}, out);
    for(auto elem: out) std::cout << elem << " ";
    std::cout << '\n';
    return 0;
}
