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
    virtual void setLeftChild(Node node);
    virtual void setRightChild(Node node);
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
    LeafNode(float val){
        h.number = val;
    }
    LeafNode(string* val){
        h.contenido = val;
    }
};






class File_inputNode: public Node{
private:
    Node* input;
    Node* stmt;
public:
    File_inputNode();
    File_inputNode(Node*);
    File_inputNode(Node*,Node*);
};

class FuncdefNode: public Node{
private:
    Node* parameters;
    Node* suite;
public:
    FuncdefNode(Node*,Node*);
};

class ParametersNode: public Node{
private:
    Node* varargslist;
public:
    ParametersNode(Node*);
};

class VarargslistNode: public Node {
private:
    Node* fpdef;
    Node* test;
public:
    VarargslistNode(Node*);
    VarargslistNode(Node*,Node*);
};

class FpdefNode: public Node{
private:
    Node* fplist;
public:
    FpdefNode();
    FpdefNode(Node*);
};

class FplistNode: public Node{
private:
    Node* fpdef;
public:
    FplistNode(Node*);
};

class StmtNode: public Node {
private:
    Node* stmt;
public:
    StmtNode(Node*);
};

class Simple_stmtNode: public Node {
private:
    Node* small_stmt;
public:
    Simple_stmtNode(Node*);
};

class Small_stmtNode: public Node {
private:
    Node* stmt;
public:
    Small_stmtNode(Node*);
};

class Expr_stmtNode: public Node{
private:
    Node* testlist;
public:
    Expr_stmtNode(Node*);
};

class Print_stmtNode: public Node{
private:
    Node* test;
public:
    Print_stmtNode(Node*);
};

class Del_stmtNode: public Node{
private:
    Node* exprlist;
public:
    Del_stmtNode(Node*);
};

class Flow_stmtNode: public Node{
private:
    Node* stmt;
public:
    Flow_stmtNode(Node*);
};

class ReturnNode: public Node {
private:
    Node* testlist;
public:
    ReturnNode();
    ReturnNode(Node*);
};

class Raise_stmtNode: public Node {
private:
    Node* test1;
    Node* test2;
    Node* test3;
public:
    Raise_stmtNode();
    Raise_stmtNode(Node*);
    Raise_stmtNode(Node*, Node*);
    Raise_stmtNode(Node*, Node*, Node*);
};

class Exec_stmtNode: public Node {
private:
    Node* expr;
    Node* test1;
    Node* test2;
public:
    Exec_stmtNode(Node*);
    Exec_stmtNode(Node*,Node*);
    Exec_stmtNode(Node*,Node*,Node*);
};

class Compound_stmtNode: public Node {
private:
    Node* stmt;
public:
    Compound_stmtNode(Node*);
};

class If_stmtNode: public Node {
private:
    Node* test;
    Node* suite1;
    Node* suite2;
public:
    If_stmtNode(Node*,Node*);
    If_stmtNode(Node*,Node*, Node*);
};

class While_stmtNode: public Node {
private:
    Node* test;
    Node* suite1;
    Node* suite2;
public:
    While_stmtNode(Node*,Node*);
    While_stmtNode(Node*,Node*, Node*);
};

class For_stmtNode: public Node {
private:
    Node* exprlist;
    Node* testlist;
    Node* suite1;
    Node* suite2;
public:
    For_stmtNode(Node*,Node*,Node*);
    For_stmtNode(Node*,Node*,Node*,Node*);
};

class SuiteNode: public Node {
private:
    Node* stmt;
public:
    SuiteNode(Node*);
};

class TestNode: public Node {
private:
    Node* test;
public:
    TestNode();
    TestNode(Node*);
};
class And_testNode: public Node {
private:
    Node* test;
public:
    And_testNode();
    And_testNode(Node*);
};

class Not_testNode: public Node {
private:
    Node* test;
public:
    Not_testNode(Node*);
};

class ComparisonNode: public Node {
private:
    Node* expr;
public:
    ComparisonNode(Node*);
};

class ExprNode: public Node {
private:
    Node* xor_expr;
public:
    ExprNode(Node*);
};

class Xor_exprNode: public Node {
private:
    Node* and_expr;
public:
    Xor_exprNode(Node*);
};

class And_exprNode: public Node {
private:
    Node* shift_expr;
public:
    And_exprNode(Node*);
};

class Shift_exprNode: public Node {
private:
    Node* arith_expr;
public:
    Shift_exprNode(Node*);
};

class Arith_exprNode: public Node {
private:
    Node* term;
public:
    Arith_exprNode(Node*);
};

class TermNode: public Node {
private:
    Node* factor;
public:
    TermNode(Node*);
};
class FactorNode:public Node{
private:
    Node*factor;
public:
    FactorNode(Node*);
};

class PowerNode:public Node{
private:
    Node*atom;
    Node*factor;
public:
    PowerNode(Node*);
    PowerNode(Node*, Node*);
};

class AtomNode:public Node{
private:
    Node*list;
public:
    AtomNode(Node*);
};

class ListmakerNode:public Node{
private:
    Node*test;
    Node*list_for;
public:
    ListmakerNode(Node*);
    ListmakerNode(Node*, Node*);
};

class Testlist_compNode:public Node{
private:
    Node*test;
    Node*comp_for;
public:
    Testlist_compNode(Node*);
    Testlist_compNode(Node*, Node*);
};

class TrailerNode:public Node{
private:
    Node*list;
public:
    TrailerNode(Node*);
};


class SubscriptlistNode :public Node{

private:
    Node* subscript;
public:
    SubscriptlistNode(Node*);
};

class SubscriptNode:public Node{
private:
    Node*test;
    Node*sliceop;
public:
    SubscriptNode(Node*);
    SubscriptNode(Node*, Node*);
};

class SliceopNode :public Node{
private:
    Node* test;
public:
    SliceopNode(Node*);
};


class ExprlistNode :public Node{
private:
    Node* expr;
public:
    ExprlistNode(Node*);
};

class TestlistNode :public Node{
private:
    Node* test;
public:
    TestlistNode(Node*);
};

class Testlist_safeNode :public Node{

private:
    Node* test;
public:
    Testlist_safeNode(Node*);
};
class DictorsetmarkerNode:public Node{

private:
    Node* test;
public:
    DictorsetmarkerNode(Node*);
};

class ArgList:public Node{

private:
    Node* test;
public:
    ArgList(Node*);
};
class ArgumentNode:public Node{
private:
    Node* test;
    Node* comp_for;
public:
    ArgumentNode(Node*);
    ArgumentNode(Node*, Node*);
};
class List_iterNode:public Node{
private:
    Node * list;
public:
    List_iterNode(Node*);
};

class List_forNode:public Node{
private:
    Node* exprlist;
    Node*testlist_state;
    Node*list_iter;

public:
    List_forNode(Node*, Node*);
    List_forNode(Node*, Node*, Node*);
};

class List_ifNode:public Node{
private:
    Node*test;
    Node*list_iter;

public:
    List_ifNode(Node*);
    List_ifNode(Node*, Node*);
};
class Comp_iterNode:public Node{
private:
    Node*comp;
public:
    Comp_iterNode(Node*);
};

class Comp_forNode:public Node{
private:
    Node *exprlist;
    Node *test;
    Node *comp_iter;
public:
    Comp_forNode(Node*,Node*);
    Comp_forNode(Node*,Node*,Node*);
};


class Comp_ifNode:public Node{
private:
    Node *test;
    Node *comp_iter;
public:
    Comp_ifNode(Node*);
    Comp_ifNode(Node*,Node*);
};

class Testlist1Node: public Node{
private:
    Node* test;
public:
    Testlist1Node(Node*);
};

class testNode: public Node{
public:
    testNode();

};

File_inputNode::File_inputNode() {
    input = 0;
    stmt = 0;
}
File_inputNode::File_inputNode(Node* input) {
    this->input = input;
    stmt = 0;
}
File_inputNode::File_inputNode(Node* input, Node* stmt) {
    this->input = input;
    this->stmt = stmt;
}
FuncdefNode::FuncdefNode(Node* parameters,Node* suite) {
    this->parameters = parameters;
    this->suite = suite;
}
ParametersNode::ParametersNode(Node* varargslist) {
    this->varargslist = varargslist;
}
VarargslistNode::VarargslistNode(Node* fpdef){
    this->fpdef = fpdef;
    test = 0;
}
VarargslistNode::VarargslistNode(Node* fpdef,Node* test){
    this->fpdef = fpdef;
    this->test = test;
}
FpdefNode::FpdefNode(){
    fplist = 0;
}
FpdefNode::FpdefNode(Node* fplist){
    this->fplist = fplist;
}
FplistNode::FplistNode(Node* fpdef){
    this->fpdef = fpdef;
}
StmtNode::StmtNode(Node* stmt){
    this->stmt = stmt;
}
Simple_stmtNode::Simple_stmtNode(Node* small_stmt) {
    this->small_stmt = small_stmt;
}
Small_stmtNode::Small_stmtNode(Node* stmt) {
    this->stmt = stmt;
}
Expr_stmtNode::Expr_stmtNode(Node* testlist) {
    this->testlist = testlist;
}
Print_stmtNode::Print_stmtNode(Node* test) {
    this->test = test;
}
Del_stmtNode::Del_stmtNode(Node* exprlist) {
    this->exprlist = exprlist;
}
Flow_stmtNode::Flow_stmtNode(Node* stmt) {
    this->stmt = stmt;
}
ReturnNode::ReturnNode(){
    testlist = 0;
}
ReturnNode::ReturnNode(Node* testlist){
    this->testlist = testlist;
}
Raise_stmtNode::Raise_stmtNode(){
    test1 = 0;
    test2 = 0;
    test3 = 0;
}
Raise_stmtNode::Raise_stmtNode(Node* test1){
    this->test1 = test1;
    test2 = 0;
    test3 = 0;
}
Raise_stmtNode::Raise_stmtNode(Node* test1, Node* test2){
    this->test1 = test1;
    this->test2 = test2;
    test3 = 0;
}
Raise_stmtNode::Raise_stmtNode(Node* test1, Node* test2, Node* test3){
    this->test1 = test1;
    this->test2 = test2;
    this->test3 = test3;
}
Exec_stmtNode::Exec_stmtNode(Node* expr){
    this->expr = expr;
    test1 = 0;
    test2 = 0;
}
Exec_stmtNode::Exec_stmtNode(Node* expr, Node* test1){
    this->expr = expr;
    this->test1 = test1;
    test2 = 0;
}
Exec_stmtNode::Exec_stmtNode(Node* expr, Node* test1, Node* test2){
    this->expr = expr;
    this->test1 = test1;
    this->test2 = test2;
}
Compound_stmtNode::Compound_stmtNode(Node* stmt) {
    this->stmt = stmt;
}
If_stmtNode::If_stmtNode(Node* test, Node* suite1){
    this->test = test;
    this->suite1 = suite1;
    suite2 = 0;
}
If_stmtNode::If_stmtNode(Node* test, Node* suite1, Node* suite2){
    this->test = test;
    this->suite1 = suite1;
    this->suite2 = suite2;
}
While_stmtNode::While_stmtNode(Node* test, Node* suite1){
    this->test = test;
    this->suite1 = suite1;
    suite2 = 0;
}
While_stmtNode::While_stmtNode(Node* test, Node* suite1, Node* suite2){
    this->test = test;
    this->suite1 = suite1;
    this->suite2 = suite2;
}
For_stmtNode::For_stmtNode(Node* exprlist, Node* testlist, Node* suite1){
    this->exprlist = exprlist;
    this->testlist = testlist;
    this->suite1 = suite1;
    suite2 = 0;
}
For_stmtNode::For_stmtNode(Node* exprlist, Node* testlist, Node* suite1, Node* suite2){
    this->exprlist = exprlist;
    this->testlist = testlist;
    this->suite1 = suite1;
    this->suite2 = suite2;
}
SuiteNode::SuiteNode(Node* stmt){
    this->stmt = stmt;
}
TestNode::TestNode(){
    test = 0;
}
TestNode::TestNode(Node* test){
    this->test = test;
}
And_testNode::And_testNode(){
    test = 0;
}
And_testNode::And_testNode(Node* test){
    this->test = test;
}
Not_testNode::Not_testNode(Node* test){
    this->test = test;
}
ComparisonNode::ComparisonNode(Node* expr){
    this->expr = expr;
}
ExprNode::ExprNode(Node* xor_expr){
    this->xor_expr = xor_expr;
}
Xor_exprNode::Xor_exprNode(Node* and_expr){
    this->and_expr = and_expr;
}
And_exprNode::And_exprNode(Node* shift_expr){
    this->shift_expr = shift_expr;
}
Shift_exprNode::Shift_exprNode(Node* arith_expr){
    this->arith_expr = arith_expr;
}
Arith_exprNode::Arith_exprNode(Node* term){
    this->term = term;
}
TermNode::TermNode(Node* factor){
    this->factor = factor;
}
FactorNode::FactorNode(Node*factor){
    this->factor=factor;
}

PowerNode::PowerNode(Node*atom){
    this->atom =atom;
}
PowerNode::PowerNode(Node*atom, Node*factor){
    this->atom = atom;
    this->factor=factor;
}
AtomNode::AtomNode(Node*list){
    this->list = list;
}
ListmakerNode::ListmakerNode(Node*test){
    this->test = test;
}
ListmakerNode::ListmakerNode(Node*test, Node*list_for){
    this->test = test;
    this->list_for= list_for;
}     
Testlist_compNode::Testlist_compNode(Node*test){
    this->test = test;
}
Testlist_compNode::Testlist_compNode(Node*test, Node*comp_for){
    this->test = test;
    this->comp_for= comp_for;
}   
SubscriptNode::SubscriptNode(Node*test){
    this->test = test;
}
SubscriptNode::SubscriptNode(Node*test, Node*sliceop){
    this->test = test;
    this->sliceop= sliceop;
}

SubscriptlistNode::SubscriptlistNode(Node*subscript){
    this->subscript= subscript;
}


TrailerNode::TrailerNode(Node*list){
    this->list = list;
}

Testlist_safeNode::Testlist_safeNode(Node*test){
    this->test= test;
}

TestlistNode::TestlistNode(Node*test){
    this->test= test;
}
ExprlistNode::ExprlistNode(Node*test){
    this->expr= expr;
}

SliceopNode::SliceopNode(Node*test){
    this->test= test;
}
List_ifNode::List_ifNode(Node*test){
    this->test=test;
}
List_ifNode::List_ifNode(Node*test, Node*list_iter){
    this->test = test;
    this->list_iter=list_iter; 
}


List_forNode::List_forNode(Node*exprlist, Node*testlist_state){
    this->exprlist=exprlist;
    this->testlist_state =testlist_state;
}
List_forNode::List_forNode(Node*exprlist,Node* testlist_state, Node*list_iter){
    this->exprlist =exprlist;
    this->testlist_state=testlist_state;
    this->list_iter=list_iter; 
}

List_iterNode::List_iterNode(Node*list){
    this->list = list;
}


ArgumentNode::ArgumentNode(Node*test){
    this->test = test;
}
ArgumentNode::ArgumentNode(Node*test, Node *comp_for){
    this->test=test;
    this->comp_for =comp_for;
}

ArgList::ArgList(Node*test){
    this->test= test;
}

DictorsetmarkerNode::DictorsetmarkerNode(Node*test){
    this->test= test;
}

testNode::testNode() {
}
Testlist1Node::Testlist1Node(Node*test) {
    this->test =test;
}


Comp_ifNode::Comp_ifNode(Node*test){
    this->test = test;
}
Comp_ifNode::Comp_ifNode(Node* test, Node* comp_iter){
    this->test=test;
    this->comp_iter = comp_iter;
}


Comp_forNode::Comp_forNode(Node* exprlist, Node*test){
    this->exprlist = exprlist;
    this->test=test;
}
Comp_forNode::Comp_forNode(Node* exprlist, Node*test, Node* comp_iter){
    this->exprlist = exprlist;
    this->test=test;
    this->comp_iter = comp_iter;
}

Comp_iterNode::Comp_iterNode(Node*comp){
    this->comp  = comp;
}


int main(){
    
}