#include <list>
#include <vector>
#include <string>
#include "nodo.cpp"
using namespace std;

class FuncDefNode: public BlockNode {
public:
    FuncDefNode() : BlockNode() {
    }
};

class VarargslistNode: public LNodeList {
public:
    VarargslistNode() : LNodeList(){
    }
};

class AugassignNode: public BinNode {
private:
    int operacion;
public:
    AugassignNode(int op) : BinNode() {
        operacion = op;
    }
};

class PrintNode: public NodeList {
public:
    PrintNode() : NodeList(){
    }
};

class DelNode: public NodeList {
public:
    DelNode() : NodeList(){
    }
};

class PassNode: public LeafNode {
public:
    PassNode() : LeafNode(){
    }
};

class BreakNode: public LeafNode {
public:
    BreakNode() : LeafNode(){
    }
};

class ContinueNode: public LeafNode {
public:
    ContinueNode() : LeafNode(){
    }
};

class ReturnNode: public NodeList {
public:
    ReturnNode() : NodeList(){
    }
};

class GlobalNode: public NodeList {
public:
    GlobalNode() : NodeList(){
    }
};

class ExecNode: public BlockNode {
public:
    ExecNode() : BlockNode(){
    }
};

class IfNode: public BlockNode {
public:
    IfNode() : BlockNode(){
    }
};

class WhileNode: public BlockNode {
public:
    WhileNode() : BlockNode(){
    }
};

class ForNode: public BlockNode {
public:
    ForNode() : BlockNode(){
    }
};

class SuiteNode: public BlockNode {
public:
    SuiteNode() : BlockNode(){
    }
};

class TestNode: public LNodeList {
public:
    TestNode() : LNodeList(){
    }
};

class AndNode: public LNodeList {
public:
    AndNode() : LNodeList(){
    }
};

class NotNode: public LNodeList {
public:
    NotNode() : LNodeList(){
    }
};

class ComparisonNode: public BinNode {
private:
    int comparacion;
public:
    ComparisonNode(int comp) : BinNode(){
        comparacion = comp;
    }
};

class ExprNode: public BinNode{
public:
    ExprNode(): BinNode(){
    }
};

class XorNode: public BinNode{
public:
    XorNode(): BinNode(){
    }
};

class ShiftNode: public BinNode{
public:
    ShiftNode(): BinNode(){
    }
};

class ArithNode: public BinNode {
private:
    int operacion;
public:
    ArithNode(int op) : BinNode(){
        operacion = op;
    }
};

class TermNode: public BinNode {
private:
    int operacion;
public:
    TermNode(int op) : BinNode(){
        operacion = op;
    }
};

class FactorNode: public LeafNode {
public:
    FactorNode() : LeafNode(){
    }
    FactorNode(float num) : LeafNode(num){
    }
};

class ASTBuilder
{
public:
    ASTBuilder() {};
    Node* bFuncDefNode(){
        return new FuncDefNode();
    }
    NodeList* bVarargslistNode(){
        return new VarargslistNode();
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
};