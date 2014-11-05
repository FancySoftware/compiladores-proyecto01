#include <list>
#include <vector>
#include <string>
#include "nodo.cpp"
using namespace std;

class FuncDefNode: public BlockNode {
public:
    FuncdefNode() {
        BlockNode();
    }
};

class VarargslistNode: public LNodeList {
public:
    VarargslistNode() {
        LNodeList();
    }
};

class AugassignNode: public BinNode {
private:
    int operacion;
public:
    AugassignNode(int op) {
        BinNode();
        operacion = op;
    }
};

class PrintNode: public NodeList {
public:
    PrintNode() {
        NodeList();
    }
};

class DelNode: public NodeList {
public:
    DelNode() {
        NodeList();
    }
};

class PassNode: public LeafNode {
public:
    PassNode() {
        LeafNode();
    }
};

class BreakNode: public LeafNode {
public:
    BreakNode() {
        LeafNode();
    }
};

class ContinueNode: public LeafNode {
public:
    ContinueNode() {
        LeafNode();
    }
};

class ReturnNode: public NodeList {
public:
    ReturnNode() {
        NodeList();
    }
};

class GlobalNode: public NodeList {
public:
    GlobalNode() {
        NodeList();
    }
};

class ExecNode: public BlockNode {
public:
    ExecNode() {
        BlockNode();
    }
};

class IfNode: public BlockNode {
public:
    IfNode() {
        BlockNode();
    }
};
class WhileNode: public BlockNode {
public:
    WhileNode() {
        BlockNode();
    }
};
class ForNode: public BlockNode {
public:
    ForNode() {
        BlockNode();
    }
};

class SuiteNode: public BlockNode {
public:
    SuiteNode() {
        BlockNode();
    }
};

class TestNode: public LNodeList {
public:
    TestNode() {
        LNodeList();
    }
};
class AndNode: public LNodeList {
public:
    AndNode() {
        LNodeList();
    }
};
class NotNode: public LNodeList {
public:
    NotNode() {
        LNodeList();
    }
};
class ComparisonNode: public BinNode {
private:
    int comparacion;
public:
    ComparisonNode(int comp) {
        BinNode();
        comparacion = comp;
    }
};
/*
class ASTBuilder{
public:

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
}*/