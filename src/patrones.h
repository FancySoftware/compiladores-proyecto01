#ifndef PATRONES_H
#define PATRONES_H
#include <list>
#include <vector>
#include <string>
#include "nodo.h"
#include <iostream>
#include <typeinfo>
#include "simbolos.hpp"
using namespace std;

static Simbolo* tabla_simbolos = new Simbolo();

class FuncDefNode;
class VarargslistNode;
class AugassignNode;
class PrintNode;
class DelNode;
class PassNode;
class BreakNode;
class ContinueNode;
class ReturnNode;
class GlobalNode;
class ExecNode;
class IfNode;
class WhileNode;
class ForNode;
class SuiteNode;
class TestNode;
class AndNode;
class NotNode;
class ComparisonNode;
class ExprNode;
class XorNode;
class ShiftNode;
class ArithNode;
class TermNode;
class FactorNode;
class IntNode;

class Visitor{
public:
    virtual void visit(FuncDefNode*);
    virtual void visit(VarargslistNode*);
    virtual void visit(AugassignNode*);
    virtual void visit(PrintNode*);
    virtual void visit(DelNode*);
    virtual void visit(PassNode*);
    virtual void visit(BreakNode*);
    virtual void visit(ContinueNode*);
    virtual void visit(ReturnNode*);
    virtual void visit(GlobalNode*);
    virtual void visit(ExecNode*);
    virtual void visit(IfNode*);
    virtual void visit(WhileNode*);
    virtual void visit(ForNode*);
    virtual void visit(SuiteNode*);
    virtual void visit(TestNode*);
    virtual void visit(AndNode*);
    virtual void visit(NotNode*);
    virtual void visit(ComparisonNode*);
    virtual void visit(ExprNode*);
    virtual void visit(XorNode*);
    virtual void visit(ShiftNode*);
    virtual void visit(ArithNode*);
    virtual void visit(TermNode*);
    virtual void visit(FactorNode*);
    virtual void visit(IntNode*);
protected:
    Visitor(){}
};


class FuncDefNode: public BlockNode {
public:
    FuncDefNode(Node args, Node suite) : BlockNode() {
        setFChild(args);
        setLChild(suite);
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class VarargslistNode: public LNodeList {
public:
    VarargslistNode(Node fpdef, Node aux4) : LNodeList(){
        addLChild(fpdef);
        addLChild(aux4);
    }
    VarargslistNode(Node fpdef, Node test, Node aux4) : LNodeList(){
        addLChild(fpdef);
        addLChild(test);
        addLChild(aux4);
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class AugassignNode: public BinNode {
private:
    int operacion;
public:
    AugassignNode(int op) : BinNode() {
        operacion = op;
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class PrintNode: public NodeList {
public:
    PrintNode() : NodeList(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class DelNode: public NodeList {
public:
    DelNode() : NodeList(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class PassNode: public LeafNode {
public:
    PassNode() : LeafNode(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class BreakNode: public LeafNode {
public:
    BreakNode() : LeafNode(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class ContinueNode: public LeafNode {
public:
    ContinueNode() : LeafNode(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class ReturnNode: public NodeList {
public:
    ReturnNode() : NodeList(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class GlobalNode: public NodeList {
public:
    GlobalNode() : NodeList(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class ExecNode: public BlockNode {
public:
    ExecNode() : BlockNode(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class IfNode: public BlockNode {
public:
    IfNode() : BlockNode(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class WhileNode: public BlockNode {
public:
    WhileNode() : BlockNode(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class ForNode: public BlockNode {
public:
    ForNode() : BlockNode(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class SuiteNode: public BlockNode {
public:
    SuiteNode() : BlockNode(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class TestNode: public LNodeList {
public:
    TestNode() : LNodeList(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class AndNode: public LNodeList {
public:
    AndNode() : LNodeList(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class NotNode: public LNodeList {
public:
    NotNode() : LNodeList(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class ComparisonNode: public BinNode {
private:
    int comparacion;
public:
    ComparisonNode(int comp) : BinNode(){
        comparacion = comp;
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class ExprNode: public BinNode{
public:
    ExprNode(): BinNode(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class XorNode: public BinNode{
public:
    XorNode(): BinNode(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class ShiftNode: public BinNode{
public:
    ShiftNode(): BinNode(){
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class ArithNode: public BinNode {
private:
    int operacion;
public:
    ArithNode(int op) : BinNode(){
        operacion = op;
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
    float getOperacion(){
        return operacion;
    }
};

class TermNode: public BinNode {
private:
    int operacion;
public:
    TermNode(int op) : BinNode(){
        operacion = op;
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
    int getOperacion(){
        return operacion;
    }
};

class FactorNode: public LeafNode {
public:
    float valor;
    FactorNode() : LeafNode(){
    }
    FactorNode(float num) : LeafNode(num){
        valor = num;
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }

};

class IntNode:public LeafNode{

public:
    int valor;
    IntNode(int val): LeafNode(val){
        valor = val;
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
    int getValor(){
        return valor;
    }
};

class ASTBuilder{
public:
    ASTBuilder() {};
    Node* bToNode(NodeList* lista) {
        return new INode(lista);
    }
    Node* bFuncDefNode(Node args, Node suite){
        return new FuncDefNode(args,suite);
    }
    NodeList* bVarargslistNode(NodeList *fpdef, NodeList *aux4){
        return new VarargslistNode(*bToNode(fpdef),*bToNode(aux4));
    }
    NodeList* bVarargslistNode(NodeList *fpdef, NodeList *test, NodeList *aux4){
        return new VarargslistNode(*bToNode(fpdef),*bToNode(test),*bToNode(aux4));
    }
    Node* bAugassignNode(int op){
        return new AugassignNode(op);
    }
    NodeList* bPrintNode(){
        return new PrintNode();
    }
    NodeList* bDelNode(){
        return new DelNode();
    }
    Node* bPassNode(){
        return new PassNode();
    }
    Node* bBreakNode(){
        return new BreakNode();
    }
    Node* bContinueNode(){
        return new ContinueNode();
    }
    NodeList* bReturnNode(){
        return new ReturnNode();
    }
    NodeList* bGlobalNode(){
        return new GlobalNode();
    }
    Node* bExecNode(){
        return new ExecNode();
    }
    Node* bIfNode(){
        return new IfNode();
    }
    Node* bWhileNode(){
        return new WhileNode();
    }
    Node* bForNode(){
        return new ForNode();
    }
    Node* bSuiteNode(){
        return new SuiteNode();
    }
    NodeList* bTestNode(){
        return new TestNode();
    }
    NodeList* bAndNode(){
        return new AndNode();
    }
    NodeList* bNotNode(){
        return new NotNode();
    }
    Node* bComparisonNode(int comp){
        return new ComparisonNode(comp);
    }
    Node* bExprNode(){
        return new ExprNode();
    }
    Node* bXorNode(){
        return new XorNode();
    }
    Node* bShiftNode(){
        return new ShiftNode();
    }
    Node* bArithNode(int op){
        return new ArithNode(op);
    }
    Node* bTermNode(int op){
        return new TermNode(op);
    }
    Node* bFactorNode(){
        return new FactorNode();
    }
    Node* bFactorNode(float val){
        return new FactorNode(val);
    }
    Node* bIntNode(int val){
        return new IntNode(val);
    }
};

     void Visitor::visit(VarargslistNode*){}
     void Visitor::visit(DelNode*){}
     void Visitor::visit(PassNode*){}
     void Visitor::visit(BreakNode*){}
     void Visitor::visit(ContinueNode*){}
     void Visitor::visit(ReturnNode*){}
     void Visitor::visit(GlobalNode*){}
     void Visitor::visit(ExecNode*){}
     void Visitor::visit(IfNode*){}
     void Visitor::visit(WhileNode*){}
     void Visitor::visit(ForNode*){}
     void Visitor::visit(SuiteNode*){}
     void Visitor::visit(TestNode*){}
     void Visitor::visit(AndNode*){}
     void Visitor::visit(NotNode*){}
     void Visitor::visit(ComparisonNode*){}
     void Visitor::visit(ExprNode*){}
     void Visitor::visit(XorNode*){}
     void Visitor::visit(ShiftNode*){}
     void Visitor::visit(ArithNode*){}
     void Visitor::visit(TermNode*){}
     void Visitor::visit(FactorNode*){}
     void Visitor::visit(IntNode*){}

void Visitor::visit(FuncDefNode* n){
    tabla_simbolos->openScope();
}
void Visitor::visit( AugassignNode* n){
    //obtener el nombre del identificador
    string name = "prueba";
    if(tabla_simbolos->declaredLocally(name)){
        cout<< "declarado";
        Elemento *ref = tabla_simbolos->lookup(name);
      /*
        if(ref->tipo != n->SegundoElemento)
            throw "no son del mismo tipo";
        */
        //falta asociar al nodo la referencia al elemento
    }else{
        cout <<"agregamos a la tabla";
        Elemento nuevo;
        nuevo.alcance = tabla_simbolos->alcance_actual;
        nuevo.nombre = name;
        nuevo.tipo = "identificador";
        tabla_simbolos->insert(name,nuevo);
        //falta guarda en el nodo la referencia al elemento
    }
}
void Visitor::visit( PrintNode* n){
    /*
    string identificador = n->identificador;
    if(tabla_simbolos->declaredLocally(identificador)){
        Elemento *ref = tabla_simbolos->lookup(identificador);
        //asociar la referencia al nodo
    }else{
        throw "La variable no ha sido declarada"
    }
    */
}

class PrintVisitor:public Visitor{
public:
    virtual void visit(FuncDefNode* n);
    virtual void visit( VarargslistNode* n);
    virtual void visit( AugassignNode* n);
    virtual void visit( PrintNode* n);
    virtual void visit( DelNode* n);
    virtual void visit( PassNode* n);
    virtual void visit( BreakNode* n);
    virtual void visit( ContinueNode* n);
    virtual void visit( ReturnNode* n);
    virtual void visit( GlobalNode* n);
    virtual void visit( ExecNode* n);
    virtual void visit( IfNode* n);
    virtual void visit( WhileNode* n);
    virtual void visit( ForNode* n);
    virtual void visit( SuiteNode* n);
    virtual void visit( TestNode* n);
    virtual void visit( AndNode* n);
    virtual void visit( NotNode* n);
    virtual void visit( ComparisonNode* n);
    virtual void visit( ExprNode* n);
    virtual void visit( XorNode* n);
    virtual void visit( ShiftNode* n);
    virtual void visit( ArithNode* n);
    virtual void visit( TermNode* n);
    virtual void visit( FactorNode* n);
    virtual void visit( IntNode* n);
};

/*
void PrintVisitor::visit(ReturnNode*n){
    cout<<"(";
    list<Node> *lista= (n->hijos.lista);
    list<Node>::iterator it;
    for(it=lista->begin();it != lista->end();++it){

    }

}
*/
void PrintVisitor::visit(IntNode* n){
    cout << "(" << n->valor <<")";
}
void PrintVisitor::visit(FactorNode*n){
    cout <<"(" << n->valor<<")";
}
void PrintVisitor::visit(TermNode* n){
    cout << "(" ;
    if(n->getOperacion() == 1){
        cout << "*";
    }
    if(n->getOperacion() == 2){
        cout<<"/";
    }
//    PrintVisitor::visit(n->getLChild());
//    PrintVisitor::visit(n->getFChild());
    cout << ")";
}

void PrintVisitor::visit(ArithNode* n){
    cout << "(" ;
    if(n->getOperacion() == 1){
        cout << "+";
    }
    if(n->getOperacion()==2){
        cout<<"-";
    }
//  PrintVisitor::visit(n->getLChild());
//  PrintVisitor::visit(n->getFChild());
    cout << ")";
}


#endif