#ifndef NODO_HPP
#define NODO_HPP
#include <vector>
#include <string>
using namespace std;


/* Clase Nodo*/
class Node{
public:
  Node(){}
};

class BlockNode: public Node{
protected:
    vector<Node> hijos;
public:
    BlockNode();
    void addChild(Node);
    vector<Node> getChilds();
};

class OpNode: public BlockNode{
protected:
    int op;
public:
    OpNode(int);
    int getOp();
};


/* Nodo hoja para guardar valores*/
class LeafNode: public Node{
protected:
    union hoja {
        string* str;
        float num;
    };
    hoja h;
public:
    LeafNode();
    LeafNode(float);
    LeafNode(string*);
};
#endif