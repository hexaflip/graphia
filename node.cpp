#pragma once
#include "node.hpp"
static std::default_random_engine generator;
static std::uniform_int_distribution<int> distribution(1,1e6);

Node::Node(std::string title) : name(title){
    this->id = distribution(generator);
};

Node::Node(const Node& other) : name(other.name), id(other.id){};

Node& Node::operator=(const Node& other){
    if (this != &other){
        name = other.getName();
    }
    id = other.id;
    return *this;
}

Node& Node::operator=(Node&& other) noexcept{
    if (this != &other){
        name = std::move(other.getName());
    }
    id = other.getID();
    return *this;
}

Node::Node(Node&& other) noexcept : name(std::move(other.name)), id(std::move(other.id)){}

Node::~Node() = default;