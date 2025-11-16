#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "node.hpp"
#include "string_manipulation.hpp"



class Graph{
    private:
    std::unordered_map<std::string, std::vector<Node>> base;
    int internalCount = 0;

    public:
    void printAll();
    bool addNode(Node& inQuestion);
    bool deleteNode(Node& inQuestion);
};