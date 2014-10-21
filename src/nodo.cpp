class Node{
protected:
  Node();
};
Node::Node(){};

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