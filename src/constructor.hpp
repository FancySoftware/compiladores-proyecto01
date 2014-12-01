#ifndef CONSTRUCTOR_HPP
#define CONSTRUCTOR_HPP
#include "nodo.hpp"

class NumberNode: public LeafNode {
private:
    //1 para int, 2 para float
    int tipo;
public:
    NumberNode(float,int);
    int getTipo();
};

class StringNode: public LeafNode {
public:
    StringNode(string*);
};

class PrintNode: public BlockNode {
public:
    PrintNode();
};

class BreakNode: LeafNode {
public:
    BreakNode();
};

class ContinueNode: LeafNode {
public:
    ContinueNode();
};

class ReturnNode: LeafNode {
public:
    ReturnNode();
};

class AugassignNode: OpNode {
public:
    AugassignNode(int);
};

class ArithNode: OpNode{
public:
    ArithNode(int);
};

class TermNode: OpNode{
public:
    TermNode(int);
};

class FactorNode: OpNode{
public:
    FactorNode(int);
};

class ComparisonNode: OpNode{
public:
    ComparisonNode(int);
};

class IdNode: LeafNode {
public:
    IdNode(string*);
    string* getName();
};

class IfNode: BlockNode {
protected:
    BlockNode* ifChilds;
    BlockNode* elseChilds;
public:
    IfNode();
    void addIfChild(Node);
    void addElseChild(Node);
    BlockNode* getIfChilds();
    BlockNode* getElseChilds();
};

class WhileNode: BlockNode {
protected:
    BlockNode* bodyChilds;
public:
    WhileNode();
    void addBodyChild(Node);
    BlockNode* getBodyChilds();
};

class ForNode: BlockNode {
protected:
    string* var;
    string* cjto;
public:
    ForNode(string*, string*);
    string* getVar();
    string* getCjto();
};

class TestNode : BlockNode {
public:
    TestNode();
};

class AndNode : BlockNode {
public:
    AndNode();
};

class NotNode : BlockNode {
public:
    NotNode();
};

class XorNode : BlockNode {
public:
    XorNode();
};


#endif