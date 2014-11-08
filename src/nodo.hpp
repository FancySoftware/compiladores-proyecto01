#ifndef NODO_HPP
#define NODO_HPP
#include <list>
#include <vector>
#include <string>
using namespace std;


/* Clase Nodo*/
class Node{
public:
  Node(){}
  void setFChild(Node arg);
  void setLChild(Node arg);
};

/* Clase NodeList que nos permite tener una lista de hijos o bien un vector de hijos*/

class NodeList{
private:
    union Nodelist{
        list<Node>* lista;
        vector<Node>* vectores;
    };
public:
    Nodelist hijos;
    void setLeftChild(Node node);
    void setRightChild(Node node);
    Node getFChild();
    Node getLChild();
};



/* Clase para cuando tenemos una lista de hijos */

class LNodeList: public NodeList{
private:
    list<Node> hijos;
public:
    LNodeList(){}
    void addLChild(Node arg);
    void addFChild(Node arg);
    void setRightChild(Node node);
    void setLeftChild(Node node);
};

/* Clase para cuando tenemos solo dos hijos y los guardamos en un vector*/

class VNodeList:public NodeList{
private:
    vector<Node> hijos;
public:
    VNodeList(int n){
        hijos.resize(n);
    }
    void addFChild(Node arg);
    void addLChild(Node arg);
    void setRightChild(Node arg);
    void setLeftChild(Node arg);
    Node getRightChild();
    Node getLeftChild();
};


class INode:public Node{
 public:
    NodeList* hijos;
    INode(){
        hijos = new LNodeList();
    }
    INode(int n){
        hijos = new VNodeList(n);
    }

 };

class BinNode: public INode{
private:
    VNodeList* hijos;
public:
    BinNode(){
        hijos = new VNodeList(2);
    }

    void setLChild(Node arg);
    void setFChild(Node arg);
    Node getLChild();
    Node getFChild();

};
class BlockNode:public INode{
public:
    INode* hijos;
    BlockNode(){
        hijos = new INode();
    }
};
/* Nodo hoja para guardar valores*/
class LeafNode: public Node{
private:
    union hoja{
        string* contenido;
        float number;
    };
public:
    hoja h;
    LeafNode(){}
    LeafNode(float val){
        h.number = val;
    }
    LeafNode(string* val){
        h.contenido = val;
    }
};

#endif