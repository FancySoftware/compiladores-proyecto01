#ifndef NODO_H
#define NODO_H
#include <list>
#include <vector>
#include <string>
using namespace std;


/* Clase Nodo*/
class Node{
public:
  Node(){}
  void setFChild(Node arg){
    throw "La operación no es válida en este nivel de jerarquía";
  }
  void setLChild(Node arg){
    throw "La operación no es válida en este nivel de jerarquía";
  }
};

/* Clase NodeList que nos permite tener una lista de hijos o bien un vector de hijos*/

class NodeList{
private:
    union Nodelist{
        list<Node>* lista;
        vector<Node>* vectores;
    };
public:
    Nodelist children;
    virtual void setLeftChild(Node node){};
    virtual void setRightChild(Node node){};

};



/* Clase para cuando tenemos una lista de hijos */

class LNodeList: public NodeList{
private:
    list<Node> hijos;
public:
    LNodeList(){}
    void addLChild(Node arg){
        hijos.push_back(arg);
    }
    void addFChild(Node arg){
        hijos.push_front(arg);
    }
    void setRightChild(Node node){
        throw "operacion no valida";
    }
    void setLeftChild(Node node){
        throw "operacion no valida";
    }
};

/* Clase para cuando tenemos solo dos hijos y los guardamos en un vector*/

class VNodeList:public NodeList{
private:
    vector<Node> hijos;
public:
    VNodeList(int n){
        hijos.resize(n);
    }
    void addFChild(Node arg){
        hijos.insert(hijos.begin(),arg);
    }
    void addLChild(Node arg){
        hijos.insert(hijos.end(),arg);
    }
    void setRightChild(Node arg){
        hijos.back() = arg;
    }
    void setLeftChild(Node arg){
        hijos.front() = arg;
    }
};


class INode:public Node{
 private:
    NodeList* hijos;
 public:
    INode(){
        hijos = new LNodeList();
    }
    INode(int n){
        hijos = new VNodeList(n);
    }
    INode(NodeList *lista) {
        hijos = lista;
    }

 };

class BinNode: public INode{
private:
    NodeList* hijos;
public:
    BinNode(){
        hijos = new VNodeList(2);
    }

    void setLChild(Node arg){
        hijos->setRightChild(arg);
    }

    void setFChild(Node arg){
        hijos->setLeftChild(arg);
    }

};
class BlockNode:public INode{
private:
    INode* hijos;
public:
    BlockNode(){
        hijos = new INode();
    }
    void setLChild(Node arg){
        hijos->setLChild(arg);
    }

    void setFChild(Node arg){
        hijos->setFChild(arg);
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