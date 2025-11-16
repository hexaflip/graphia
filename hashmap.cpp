#include "hashmap.hpp"

// Implement some form of MST
// 

bool hashmap::isEmpty(){
    int size = 0;
    for (int i = 0; i < hashGroups; i++){
        // get the size of the linked list
        // this should run in O(n) where n is the number of hashgroups
        size += table[i].size();
    }
    if (size > 0){
        return false;
    }
    return true;
}

int hashmap::hashFunction(Node & thing){
    return thing.getID() % hashGroups;
}

void hashmap::insertItem(Node & key, Node& value){
    int hash = hashFunction(key);
    auto& cell = table[hash];
    auto bIter = begin(cell);
    bool keyExists {false};
    for (; bIter != end(cell); bIter++){
        // see if the id already exists within the hashmap
        if (bIter->first.getID() == key.getID()){
            keyExists = true;
            bIter->second = {value};
            std::cout << "added nodes that already existed ";
            return;
        }
    }
    //THIS NEEDS TO BE FIXED, YOU ARE ADDING THE KEY WITHOUT PUTTNG THE VALUE
    //THIS NEEDS TO BE FIXED, YOU ARE ADDING THE KEY WITHOUT PUTTNG THE VALUE
    //insert the node into the linked list that holds the hashed values of it
    cell.emplace_back(key);
}

void hashmap::pushBack(Node & key, Node & val){
    int hash = hashFunction(key);
    auto& cell = table[hash];
    auto bIter = begin(cell);
    bool keyExists {false};
    for ( ; bIter != end(cell); bIter++){
        keyExists = true;
        bIter->second.push_back(val);
        return;
    }
    std::cout << "WARNING: Attempted to pushback a node that does not exist";
}

void hashmap::removeItem(Node & thing){
    int hash = hashFunction(thing);
    auto& cell = table[hash];
    auto bIter = begin(cell);
    bool keyExists {false};
    for (; bIter != end(cell); bIter++){
        if (bIter->first.getID() == thing.getID()){
            keyExists = true;
            cell.erase(bIter);
            return;
        }
    }
    std::cout << "WARNING: Attempted to delete node that did not exist";
}

void hashmap::printTable(){
    for (int i = 0; i < hashGroups; i++){
        auto&cell = table[i];
        auto bIter = begin(cell);
        for (; bIter != end(cell); bIter++){
            std::cout << "Node : [" << bIter->first.getName() <<']' << '\n';
            std::cout << "Adjacent Nodes :[";
            for (int j = 0; j < (int) bIter->second.size(); j++){
                std::cout << bIter->second[j].getName() << ", ";
            }
            std::cout << ']' << '\n';
        }
    }
    // end line + flush stream
    std::cout << std::endl;
}





