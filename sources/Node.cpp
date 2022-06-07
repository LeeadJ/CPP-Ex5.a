#include "Node.hpp"
using namespace ariel;
//Getters:
std::string& Node::getData() {return this->_data;}
std::vector<Node*>& Node::getChildrenVec() {return this->_children;}

//Constructor:
Node::Node(const std::string& str) {this->_data=str;}

//Destructor:
// Node::~Node(){}

//Functions:
//Addes a child to the Nodes children vector.
void Node::addChild(const std::string& child){}
