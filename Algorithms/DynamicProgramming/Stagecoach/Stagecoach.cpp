#include <climits>
#include <iostream>
#include <vector>


std::vector<std::string> labels = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};

std::vector<std::vector<int>> data = {
    {0, 2, 4, 3, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 7, 4, 6, 0, 0, 0},
    {0, 0, 0, 0, 3, 2, 4, 0, 0, 0},
    {0, 0, 0, 0, 4, 1, 5, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 4, 0},
    {0, 0, 0, 0, 0, 0, 0, 6, 3, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 3, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
  };


struct state {
    std::string from,to;
    int cost;
};

int main(){
    int n = data.size();

    std::vector<state> states(n);

    states [n-1] = {"","" , 0};

  
    for (int i = n - 2; i >= 0; i--) {
      // Initialize the current state with a very large cost and no path
        states[i] = { labels[i], "", INT_MAX };
      // Iterate through each neighbor of the current node
        for (int j = i + 1; j < n; j++) {
          // If there is no edge between the current node and the neighbor, continue to the next neighbor
            if (data[i][j] == 0) continue;
          // Calculate the new cost to reach the neighbor and add it to the cost of the neighbor's minimum path
            int newCost = data[i][j] + states[j].cost;
          // If the new cost is smaller than the current minimum cost for the current node, update the current state
            if (newCost < states[i].cost) {
                states[i].to = labels[j];
                states[i].cost = newCost;
            }
        }
    }
    std::vector<std::string> path(1, "A");
    int i = 0, j = 0;
    while (i < states.size()) {
        if (states[i].from == path[j]) {
            path.push_back(states[i].to);
            j++;
        }
        i++;
    }

    std::cout << "Minimum Cost: " << states[0].cost << std::endl;
    std::cout << "Minimum path: ";
    for (std::string node : path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    return 0;
}

