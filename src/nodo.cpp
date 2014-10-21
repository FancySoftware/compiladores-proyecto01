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

class StmtNode: public Node{
public:
    StmtNode();
};

StmtNode::StmtNode() {
}
File_inputNode::File_inputNode() {
    input = 0;
    stmt = 0;
}
File_inputNode::File_inputNode(Node* input) {
    this->input = input;
}
File_inputNode::File_inputNode(Node* input, Node* stmt) {
    this->input = input;
    this->stmt = stmt;
}