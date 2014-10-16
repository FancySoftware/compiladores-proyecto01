class ASTBuilder{
public:
	virtual void makeSiblings(Node* n, Node* ns)=0;
	virtual Node* bPlusNode() = 0;
	virtual Node* blFNode() =0;


	Node* bPlusNode(){
		return new PlusNode;
	}

	Node* blFNode(){
		return new IFNode();
	}
}