#include "patrones.hpp"
using namespace std;

Node* ASTBuilder::bToNode(NodeList* lista) {
        return new INode(lista);
}
Node* ASTBuilder::bFuncDefNode(){
	return new FuncDefNode();
}
Node* ASTBuilder::bFuncDefNode(Node args, Node suite){
	return new FuncDefNode(args,suite);
}
NodeList* ASTBuilder::bVarargslistNode(){
	return new VarargslistNode();
}
NodeList* ASTBuilder::bVarargslistNode(NodeList* fpdef, NodeList *aux4){
     return new VarargslistNode(*bToNode(fpdef),*bToNode(aux4));
}
NodeList* ASTBuilder::bVarargslistNode(NodeList *fpdef, NodeList *test, NodeList *aux4){
    return new VarargslistNode(*bToNode(fpdef),*bToNode(test),*bToNode(aux4));
}
Node* ASTBuilder::bAugassignNode(int op){
	return new AugassignNode(op);
}
NodeList* ASTBuilder::bPrintNode(){
	return new PrintNode();
}
NodeList* ASTBuilder::bDelNode(){
return new DelNode();
}
Node* ASTBuilder::bPassNode(){
return new PassNode();
}
Node* ASTBuilder::bBreakNode(){
return new BreakNode();
}
Node* ASTBuilder::bContinueNode(){
return new ContinueNode();
}
NodeList* ASTBuilder::bReturnNode(){
return new ReturnNode();
}
NodeList* ASTBuilder::bGlobalNode(){
return new GlobalNode();
}
Node* ASTBuilder::bExecNode(){
return new ExecNode();
}
Node* ASTBuilder::bIfNode(){
return new IfNode();
}
Node* ASTBuilder::bWhileNode(){
return new WhileNode();
}
Node* ASTBuilder::bForNode(){
return new ForNode();
}
Node* ASTBuilder::bSuiteNode(){
return new SuiteNode();
}
NodeList* ASTBuilder::bTestNode(){
return new TestNode();
}
NodeList* ASTBuilder::bAndNode(){
return new AndNode();
}
NodeList* ASTBuilder::bNotNode(){
return new NotNode();
}
Node* ASTBuilder::bComparisonNode(int comp){
return new ComparisonNode(comp);
}
Node* ASTBuilder::bExprNode(){
return new ExprNode();
}
Node* ASTBuilder::bXorNode(){
return new XorNode();
}
Node* ASTBuilder::bShiftNode(){
return new ShiftNode();
}
Node* ASTBuilder::bArithNode(int op){
return new ArithNode(op);
}
Node* ASTBuilder::bTermNode(int op){
return new TermNode(op);
}
Node* ASTBuilder::bFactorNode(){
return new FactorNode();
}
Node* ASTBuilder::bFactorNode(float val){
return new FactorNode(val);
}
Node* ASTBuilder::bIntNode(int val){
return new IntNode(val);
}

void Visitor::visit(VarargslistNode*){}
void Visitor::visit(AugassignNode*){}
void Visitor::visit(PrintNode*){}
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