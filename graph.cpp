#include "graph.hpp"

void Graph::printAll(){
    for (const std::pair<const std::string, const std::vector<Node>>& n : base){
        std::cout << "Node \"" << n.first << "\"" << " is adjacent to: " << '\n' << '[';;
        for (auto nuds : n.second){
            std::cout << nuds.getName() << ", ";
        }
        std::cout << ']' << std::endl;
    }
}

// returns if the node was added successfully
bool Graph::addNode(Node & inQuestion){
    std::string temp = inQuestion.getName();
    convertToLowercase(temp);
    if (base.find(temp) != base.end()){
        std::cout << "Warning: Node already exists within the graph";
        return false;
    }
    base[inQuestion.getName()] = {};
    return true;
}


bool Graph::deleteNode(Node & other){
    std::string temp = other.getName();
    convertToLowercase(temp);
    if (base.find(temp) != base.end()){

    }
    std::cout << "Node does not exist within graph";
    return false;
}



// how to find something with only one lookup
// if (auto iter = base.find(x); iter != base.end()) {
//     std::cout << “Found: ” << iter->second << std::endl;
// }
