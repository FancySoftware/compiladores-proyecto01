class ASTBuilder{
public:

    virtual Node* bFile_inputNode()=0;
    virtual Node* bFuncdefNode()=0;
    virtual Node* bParametersNode()=0;
    virtual Node* bVarargslistNode()=0;
    virtual Node* bFpdefNode()=0;
    virtual Node* bFplistNode()=0;
    virtual Node* bStmtNode()=0;
    virtual Node* bSimple_stmtNode()=0;
    virtual Node* bSmall_stmtNode()=0;
    virtual Node* bExpr_stmtNode()=0;
    virtual Node* bAugassignNode()=0;
    virtual Node* bPrint_stmtNode()=0;
    virtual Node* bDel_stmtNode()=0;
    virtual Node* bPass_stmtNode()=0;
    virtual Node* bFlow_stmtNode()=0;
    virtual Node* bBreak_stmtNode()=0;
    virtual Node* bContinue_stmtNode()=0;
    virtual Node* bReturn()=0;
    virtual Node* bRaise_stmtNode()=0;
    virtual Node* bGlobal_stmtNode()=0;
    virtual Node* bTemp2Node()=0;
    virtual Node* bExec_stmtNode()=0;
    virtual Node* bCompound_stmtNode()=0;
    virtual Node* bIf_stmtNode()=0;
    virtual Node* bWhile_stmtNode()=0;
    virtual Node* bFor_stmtNode()=0;
    virtual Node* bSuiteNode()=0;
    virtual Node* bTestNode()=0;
    virtual Node* bAnd_testNode()=0;
    virtual Node* bNot_testNode()=0;
    virtual Node* bComparisonNode()=0;
    virtual Node* bComp_opNode()=0;
    virtual Node* bExprNode()=0;
    virtual Node* bXor_exprNode()=0;
    virtual Node* bAnd_exprNode()=0;
    virtual Node* bShift_exprNode()=0;
    virtual Node* bArith_exprNode()=0;
    virtual Node* bTermNode()=0;
    virtual Node* bFactorNode()=0;
    virtual Node* bPowerNode()=0;
    virtual Node* bAtomNode()=0;
    virtual Node* bListmakerNode()=0;
    virtual Node* bTestlist_compNode()=0;
    virtual Node* bTrailerNode()=0;
    virtual Node* bSubscriptlistNode()=0;
    virtual Node* bSubscriptNode()=0;
    virtual Node* bSliceopNode()=0;
    virtual Node* bExprlistNode()=0;
    virtual Node* bTestlistNode()=0;
    virtual Node* bTestlist_safeNode()=0;
    virtual Node* bDictorsetmakerNode()=0;
    virtual Node* bArglistNode()=0;
    virtual Node* bArgumentNode()=0;
    virtual Node* bList_iterNode()=0;
    virtual Node* bList_forNode()=0;
    virtual Node* bList_ifNode()=0;
    virtual Node* bComp_iterNode()=0;
    virtual Node* bComp_forNode()=0;
    virtual Node* bComp_ifNode()=0;
    virtual Node* bTestlist1Node()=0;

    Node* bFile_inputNode() {
        return new File_inputNode();
    }
    Node* bFuncdefNode() {
        return new FuncdefNode();
    }
    Node* bParametersNode() {
        return new ParametersNode();
    }
    Node* bVarargslistNode() {
        return new VarargslistNode();
    }
    Node* bFpdefNode() {
        return new FpdefNode();
    }
    Node* bFplistNode() {
        return new FplistNode();
    }
    Node* bStmtNode() {
        return new StmtNode();
    }
    Node* bSimple_stmtNode() {
        return new Simple_stmtNode();
    }
    Node* bSmall_stmtNode() {
        return new Small_stmtNode();
    }
    Node* bExpr_stmtNode() {
        return new Expr_stmtNode();
    }
    Node* bAugassignNode() {
        return new AugassignNode();
    }
    Node* bPrint_stmtNode() {
        return new Print_stmtNode();
    }
    Node* bDel_stmtNode() {
        return new Del_stmtNode();
    }
    Node* bPass_stmtNode() {
        return new Pass_stmtNode();
    }
    Node* bFlow_stmtNode() {
        return new Flow_stmtNode();
    }
    Node* bBreak_stmtNode() {
        return new Break_stmtNode();
    }
    Node* bContinue_stmtNode() {
        return new Continue_stmtNode();
    }
    Node* bReturn new_stmtNode() {
        return new Return new_stmtNode();
    }
    Node* bRaise_stmtNode() {
        return new Raise_stmtNode();
    }
    Node* bGlobal_stmtNode() {
        return new Global_stmtNode();
    }
    Node* bTemp2Node() {
        return new Temp2Node();
    }
    Node* bExec_stmtNode() {
        return new Exec_stmtNode();
    }
    Node* bCompound_stmtNode() {
        return new Compound_stmtNode();
    }
    Node* bIf_stmtNode() {
        return new If_stmtNode();
    }
    Node* bWhile_stmtNode() {
        return new While_stmtNode();
    }
    Node* bFor_stmtNode() {
        return new For_stmtNode();
    }
    Node* bSuiteNode() {
        return new SuiteNode();
    }
    Node* bTestNode() {
        return new TestNode();
    }
    Node* bAnd_testNode() {
        return new And_testNode();
    }
    Node* bNot_testNode() {
        return new Not_testNode();
    }
    Node* bComparisonNode() {
        return new ComparisonNode();
    }
    Node* bComp_opNode() {
        return new Comp_opNode();
    }
    Node* bExprNode() {
        return new ExprNode();
    }
    Node* bXor_exprNode() {
        return new Xor_exprNode();
    }
    Node* bAnd_exprNode() {
        return new And_exprNode();
    }
    Node* bShift_exprNode() {
        return new Shift_exprNode();
    }
    Node* bArith_exprNode() {
        return new Arith_exprNode();
    }
    Node* bTermNode() {
        return new TermNode();
    }
    Node* bFactorNode() {
        return new FactorNode();
    }
    Node* bPowerNode() {
        return new PowerNode();
    }
    Node* bAtomNode() {
        return new AtomNode();
    }
    Node* bListmakerNode() {
        return new ListmakerNode();
    }
    Node* bTestlist_compNode() {
        return new Testlist_compNode();
    }
    Node* bTrailerNode() {
        return new TrailerNode();
    }
    Node* bSubscriptlistNode() {
        return new SubscriptlistNode();
    }
    Node* bSubscriptNode() {
        return new SubscriptNode();
    }
    Node* bSliceopNode() {
        return new SliceopNode();
    }
    Node* bExprlistNode() {
        return new ExprlistNode();
    }
    Node* bTestlistNode() {
        return new TestlistNode();
    }
    Node* bTestlist_safeNode() {
        return new Testlist_safeNode();
    }
    Node* bDictorsetmakerNode() {
        return new DictorsetmakerNode();
    }
    Node* bArglistNode() {
        return new ArglistNode();
    }
    Node* bArgumentNode() {
        return new ArgumentNode();
    }
    Node* bList_iterNode() {
        return new List_iterNode();
    }
    Node* bList_forNode() {
        return new List_forNode();
    }
    Node* bList_ifNode() {
        return new List_ifNode();
    }
    Node* bComp_iterNode() {
        return new Comp_iterNode();
    }
    Node* bComp_forNode() {
        return new Comp_forNode();
    }
    Node* bComp_ifNode() {
        return new Comp_ifNode();
    }
    Node* bTestlist1Node() {
        return new Testlist1Node();
    }
}