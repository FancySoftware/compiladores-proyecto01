#include "constructor.hpp"

NumberNode::NumberNode(float arg, int tipo) : LeafNode(arg) {
    this->tipo = tipo;
}

int NumberNode::getTipo() {
    return tipo;
}

StringNode::StringNode(string* arg) : LeafNode(arg) {}

PrintNode::PrintNode() : BlockNode() {}

BreakNode::BreakNode() : LeafNode() {}

ContinueNode::ContinueNode() : LeafNode() {}

ReturnNode::ReturnNode() : LeafNode() {}

AugassignNode::AugassignNode(int op) : OpNode(op) {}

ArithNode::ArithNode(int op) : OpNode(op) {}

TermNode::TermNode(int op) : OpNode(op) {}

FactorNode::FactorNode(int op) : OpNode(op) {}

ComparisonNode::ComparisonNode(int op) : OpNode(op) {}

IdNode::IdNode(string* name): LeafNode(name) {}

string* IdNode::getName() {
    return h.str;
}

IfNode::IfNode() : BlockNode() {
    ifChilds = new BlockNode();
    elseChilds = new BlockNode();
}

void IfNode::addIfChild(Node node) {
    ifChilds->addChild(node);
}

void IfNode::addElseChild(Node node) {
    elseChilds->addChild(node);
}

BlockNode* IfNode::getIfChilds() {
    return ifChilds;
}

BlockNode* IfNode::getElseChilds() {
    return elseChilds;
}

WhileNode::WhileNode() : BlockNode() {
    bodyChilds = new BlockNode();
}

void WhileNode::addBodyChild(Node node) {
    bodyChilds->addChild(node);
}

BlockNode* WhileNode::getBodyChilds() {
    return bodyChilds;
}

ForNode::ForNode(string* var, string* cjto) : BlockNode() {
    this->var = var;
    this->cjto = cjto;
}

string* ForNode::getVar() {
    return var;
}

string* ForNode::getCjto() {
    return cjto;
}

TestNode::TestNode() : BlockNode() {}

AndNode::AndNode() : BlockNode() {}

NotNode::NotNode() : BlockNode() {}

XorNode::XorNode() : BlockNode() {}