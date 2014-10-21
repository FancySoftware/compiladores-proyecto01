#include "nodo.cpp"

class ASTBuilder{
public:

    virtual Node* bFile_inputNode()=0;
    virtual Node* bFile_inputNode(Node*)=0;
    virtual Node* bFile_inputNode(Node*,Node*)=0;


};

Node* ASTBuilder::bFile_inputNode() {
    return new File_inputNode();
}
Node* ASTBuilder::bFile_inputNode(Node* input){
    return new File_inputNode(input);
}
Node* ASTBuilder::bFile_inputNode(Node* input, Node* stmt){
    return new File_inputNode(input,stmt);
}

int main() {
    return 0;
}