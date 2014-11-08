#include "nodo.hpp"
#include <iostream>
using namespace std;

void Node::setFChild(Node n){
	throw "Esta función no está definida para los nodos";
}

void Node::setLChild(Node n){
	throw "Esta función no está definida para los nodos";
}


void LNodeList::addLChild(Node arg){
    hijos.push_back(arg);
}

void LNodeList::addFChild(Node arg){
    hijos.push_front(arg);
}
  
void LNodeList::setRightChild(Node node){
    throw "operacion no valida";
}

void LNodeList::setLeftChild(Node node){
    throw "operacion no valida";
}

void VNodeList::addFChild(Node arg){
    hijos.insert(hijos.begin(),arg);
}
void VNodeList::addLChild(Node arg){
    hijos.insert(hijos.end(),arg);
}
void VNodeList::setRightChild(Node arg){
    hijos.back() = arg;
}
void VNodeList::setLeftChild(Node arg){
    hijos.front() = arg;
}
Node VNodeList::getRightChild(){
    return hijos.back();
}
Node VNodeList::getLeftChild(){
    return hijos.front();
}
void BinNode::setLChild(Node arg){
    hijos->setRightChild(arg);
}

void BinNode::setFChild(Node arg){
    hijos->setLeftChild(arg);
}
Node BinNode::getLChild(){
    hijos->getRightChild();
}
Node BinNode::getFChild(){
    hijos->getLeftChild();
}