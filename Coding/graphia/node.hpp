#pragma once
#include <string>
#include <random>

// change this to have a randomly generated id that way we can just hash the iD and then we finessee

class Node{
    private:
    std::string name;
    int id;
    public:
    std::string getName() const {return name;};

    int getID() const {return id;};

    //Constructors / Big 4??
    Node() = delete;

    // Initalization with name
    Node(std::string name);
    
    // Instantiation
    Node(const Node& other);

    // assignment operator
    Node& operator=(const Node& other);

    //move constructor
    Node(Node&& Other) noexcept;

    // move assignment
    Node& operator=(Node&& other) noexcept; 

    ~Node();
};