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

    Node* bErrorNode() {
        return ErrorNode();
    }
    Node* bFile_inputNode() {
        return File_inputNode();
    }
    Node* bFuncdefNode() {
        return FuncdefNode();
    }
    Node* bParametersNode() {
        return ParametersNode();
    }
    Node* bVarargslistNode() {
        return VarargslistNode();
    }
    Node* bFpdefNode() {
        return FpdefNode();
    }
    Node* bFplistNode() {
        return FplistNode();
    }
    Node* bStmtNode() {
        return StmtNode();
    }
    Node* bSimple_stmtNode() {
        return Simple_stmtNode();
    }
    Node* bSmall_stmtNode() {
        return Small_stmtNode();
    }
    Node* bExpr_stmtNode() {
        return Expr_stmtNode();
    }
    Node* bAugassignNode() {
        return AugassignNode();
    }
    Node* bPrint_stmtNode() {
        return Print_stmtNode();
    }
    Node* bDel_stmtNode() {
        return Del_stmtNode();
    }
    Node* bPass_stmtNode() {
        return Pass_stmtNode();
    }
    Node* bFlow_stmtNode() {
        return Flow_stmtNode();
    }
    Node* bBreak_stmtNode() {
        return Break_stmtNode();
    }
    Node* bContinue_stmtNode() {
        return Continue_stmtNode();
    }
    Node* bReturn_stmtNode() {
        return Return_stmtNode();
    }
    Node* bRaise_stmtNode() {
        return Raise_stmtNode();
    }
    Node* bGlobal_stmtNode() {
        return Global_stmtNode();
    }
    Node* bTemp2Node() {
        return Temp2Node();
    }
    Node* bExec_stmtNode() {
        return Exec_stmtNode();
    }
    Node* bCompound_stmtNode() {
        return Compound_stmtNode();
    }
    Node* bIf_stmtNode() {
        return If_stmtNode();
    }
    Node* bWhile_stmtNode() {
        return While_stmtNode();
    }
    Node* bFor_stmtNode() {
        return For_stmtNode();
    }
    Node* bSuiteNode() {
        return SuiteNode();
    }
    Node* bTestNode() {
        return TestNode();
    }
    Node* bAnd_testNode() {
        return And_testNode();
    }
    Node* bNot_testNode() {
        return Not_testNode();
    }
    Node* bComparisonNode() {
        return ComparisonNode();
    }
    Node* bComp_opNode() {
        return Comp_opNode();
    }
    Node* bExprNode() {
        return ExprNode();
    }
    Node* bXor_exprNode() {
        return Xor_exprNode();
    }
    Node* bAnd_exprNode() {
        return And_exprNode();
    }
    Node* bShift_exprNode() {
        return Shift_exprNode();
    }
    Node* bArith_exprNode() {
        return Arith_exprNode();
    }
    Node* bTermNode() {
        return TermNode();
    }
    Node* bFactorNode() {
        return FactorNode();
    }
    Node* bPowerNode() {
        return PowerNode();
    }
    Node* bAtomNode() {
        return AtomNode();
    }
    Node* bListmakerNode() {
        return ListmakerNode();
    }
    Node* bTestlist_compNode() {
        return Testlist_compNode();
    }
    Node* bTrailerNode() {
        return TrailerNode();
    }
    Node* bSubscriptlistNode() {
        return SubscriptlistNode();
    }
    Node* bSubscriptNode() {
        return SubscriptNode();
    }
    Node* bSliceopNode() {
        return SliceopNode();
    }
    Node* bExprlistNode() {
        return ExprlistNode();
    }
    Node* bTestlistNode() {
        return TestlistNode();
    }
    Node* bTestlist_safeNode() {
        return Testlist_safeNode();
    }
    Node* bDictorsetmakerNode() {
        return DictorsetmakerNode();
    }
    Node* bArglistNode() {
        return ArglistNode();
    }
    Node* bArgumentNode() {
        return ArgumentNode();
    }
    Node* bList_iterNode() {
        return List_iterNode();
    }
    Node* bList_forNode() {
        return List_forNode();
    }
    Node* bList_ifNode() {
        return List_ifNode();
    }
    Node* bComp_iterNode() {
        return Comp_iterNode();
    }
    Node* bComp_forNode() {
        return Comp_forNode();
    }
    Node* bComp_ifNode() {
        return Comp_ifNode();
    }
    Node* bTestlist1Node() {
        return Testlist1Node();
    }
}