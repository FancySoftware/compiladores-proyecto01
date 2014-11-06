#include "patrones.cpp"

class NodeVisistor{
public:
	virtual void visit(FuncDefNode){}
	virtual void visit(VarargslistNode){}
	virtual void visit(AugassignNode){}
	virtual void visit(PrintNode){}
	virtual void visit(DelNode){}
	virtual void visit(PassNode){}
	virtual void visit(BreakNode){}
	virtual void visit(ContinueNode){}
	virtual void visit(ReturnNode){}
	virtual void visit(GlobalNode){}
	virtual void visit(ExecNode){}
	virtual void visit(IfNode){}
	virtual void visit(WhileNode){}
	virtual void visit(ForNode){}
	virtual void visit(SuiteNode){}
	virtual void visit(TestNode){}
	virtual void visit(AndNode){}
	virtual void visit(NotNode){}
	virtual void visit(ComparisonNode){}
	virtual void visit(ExprNode){}
	virtual void visit(XorNode){}
	virtual void visit(ShiftNode){}
	virtual void visit(ArithNode){}
	virtual void visit(TermNode){}
	virtual void visit(FactorNode){}	
protected:
	NodeVisistor(){}
};

