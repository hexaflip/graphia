#pragma once
#include <iostream>
#include <list>
#include <cstring>
#include <random>
#include "node.hpp"

class hashmap{
    private:
    std::vector<int> primes = {11, 23, 37, 71, 149, 307, 601, 1297, 2347, 4649, 7919};
    static const int hashGroups = 10;
    std::list<std::pair<Node, std::vector<Node>>> table[hashGroups];
    public:
        bool isEmpty();
        int hashFunction(Node& thing);
        void insertItem(Node& thing, Node& insta);
        void removeItem(Node& thing);
        void pushBack(Node& key, Node & val);
        std::vector<Node> searchTable(Node);
        void printTable();
};





