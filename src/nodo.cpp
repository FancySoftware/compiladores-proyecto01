#include "nodo.hpp"
#include <iostream>
using namespace std;

BlockNode::BlockNode() : Node() {}
void BlockNode::addChild(Node node) {
    hijos.push_back(node);
}
vector<Node> BlockNode::getChilds() {
    return hijos;
}

OpNode::OpNode(int op) : BlockNode() {
    this->op = op;
}
int OpNode::getOp() {
    return op;
}

LeafNode::LeafNode() : Node() {}
LeafNode::LeafNode(float arg) : Node() {
    h.num = arg;
}
LeafNode::LeafNode(string* arg) : Node() {
    h.str = arg;
}