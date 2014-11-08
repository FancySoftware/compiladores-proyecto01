#ifndef PATRONES_HPP
#define PATRONES_HPP
#include "nodo.hpp"
using namespace std;

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
protected:
    Visitor(){}
public:
    void visit(FuncDefNode*);
    void visit(VarargslistNode*);
    void visit(AugassignNode*);
    void visit(PrintNode*);
    void visit(DelNode*);
    void visit(PassNode*);
    void visit(BreakNode*);
    void visit(ContinueNode*);
    void visit(ReturnNode*);
    void visit(GlobalNode*);
    void visit(ExecNode*);
    void visit(IfNode*);
    void visit(WhileNode*);
    void visit(ForNode*);
    void visit(SuiteNode*);
    void visit(TestNode*);
    void visit(AndNode*);
    void visit(NotNode*);
    void visit(ComparisonNode*);
    void visit(ExprNode*);
    void visit(XorNode*);
    void visit(ShiftNode*);
    void visit(ArithNode*);
    void visit(TermNode*);
    void visit(FactorNode*);
    void visit(IntNode*);
};



class FuncDefNode: public BlockNode {
public:
    FuncDefNode() : BlockNode() {}
    void accept(Visitor& v){
        v.visit(this);
    }
    FuncDefNode(Node args, Node suite) : BlockNode() {
        setFChild(args);
        setLChild(suite);
    }
};


class VarargslistNode: public LNodeList {
public:
    VarargslistNode() : LNodeList(){
    }
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
    IfNode(Node test, Node suite) : BlockNode() {
        setLChild(test);
        setLChild(suite);
    }
    IfNode(Node test, Node suite, Node suite_else) : BlockNode() {
        setLChild(test);
        setLChild(suite);
        setLChild(suite_else);
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class WhileNode: public BlockNode {
public:
    WhileNode() : BlockNode(){
    }
    WhileNode(Node test, Node suite) : BlockNode() {
        setLChild(test);
        setLChild(suite);
    }
    WhileNode(Node test, Node suite, Node suite_else) : BlockNode() {
        setLChild(test);
        setLChild(suite);
        setLChild(suite_else);
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class ForNode: public BlockNode {
public:
    ForNode() : BlockNode(){
    }
    ForNode(Node exprlist, Node testlist, Node suite) : BlockNode() {
        setLChild(exprlist);
        setLChild(testlist);
        setLChild(suite);
    }
    ForNode(Node exprlist, Node testlist, Node suite, Node suite_else) : BlockNode() {
        setLChild(exprlist);
        setLChild(testlist);
        setLChild(suite);
        setLChild(suite_else);
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
public:
    int operacion;
    ArithNode(int op) : BinNode(){
        operacion = op;
    }
    virtual void accept(Visitor& v){
        v.visit(this);
    }
};

class TermNode: public BinNode {
public:
    int operacion;
    TermNode(int op) : BinNode(){
        operacion = op;
    }
    virtual void accept(Visitor& v){
        v.visit(this);
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
};


class ASTBuilder{
public:
    ASTBuilder() {};
    Node* bToNode(NodeList* lista);
    Node* bFuncDefNode();
    Node* bFuncDefNode(Node args, Node suite);
    NodeList* bVarargslistNode();
    NodeList* bVarargslistNode(NodeList *pdef, NodeList *aux4);
    NodeList* bVarargslistNode(NodeList *fpdef, NodeList *test, NodeList *aux4);
    Node* bAugassignNode(int op);
    NodeList* bPrintNode();
    NodeList* bDelNode();
    Node* bPassNode();
    Node* bBreakNode();
    Node* bContinueNode();
    NodeList* bReturnNode();
    NodeList* bGlobalNode();
    Node* bExecNode();
    Node* bIfNode();
    Node* bIfNode(Node test, Node suite);
    Node* bIfNode(Node test, Node suite, Node suite_else);
    Node* bWhileNode();
    Node* bWhileNode(Node test, Node suite);
    Node* bWhileNode(Node test, Node suite, Node suite_else);
    Node* bForNode();
    Node* bForNode(Node exprlist, Node testlist, Node suite);
    Node* bForNode(Node exprlist, Node testlist, Node suite, Node suite_else);
    Node* bSuiteNode();
    NodeList* bTestNode();
    NodeList* bAndNode();
    NodeList* bNotNode();
    Node* bComparisonNode(int comp);
    Node* bExprNode();
    Node* bXorNode();
    Node* bShiftNode();
    Node* bArithNode(int op);
    Node* bTermNode(int op);
    Node* bFactorNode();
    Node* bFactorNode(float val);
    Node* bIntNode(int val);

};

class PrintVisitor:public Visitor{
    void visit(FuncDefNode* );
    void visit( VarargslistNode* );
    void visit( AugassignNode* );
    void visit( PrintNode* );
    void visit( DelNode* );
    void visit( PassNode*);
    void visit( BreakNode* );
    void visit( ContinueNode* );
    void visit( ReturnNode* );
    void visit( GlobalNode* );
    void visit( ExecNode* );
    void visit( IfNode* );
    void visit( WhileNode* );
    void visit( ForNode* );
    void visit( SuiteNode* );
    void visit( TestNode* );
    void visit( AndNode* );
    void visit( NotNode* );
    void visit( ComparisonNode* );
    void visit( ExprNode* );
    void visit( XorNode* );
    void visit( ShiftNode* );
    void visit( ArithNode* );
    void visit( TermNode* );
    void visit( FactorNode* );
    void visit( IntNode* );
};



#endif