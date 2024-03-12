class Node {
 public:
  int value = 0;
  Node* left = NULL;
  Node* right = NULL;
  Node(int value) { this->value = value; }
  static Node* ptr(int value) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = value;
    p->left = NULL;
    p->right = NULL;
    return p;
  }
  void print(Node* n) {
    if (n->left != NULL) {
      this->print(n->left);
    }
    printf("%d ", n->value);
    if (n->right != NULL) {
      this->print(n->right);
    }
  }
};

class BinarySTree {
 public:
  Node* Head = NULL;
  void insert(int value) {
    if (this->Head == NULL) {
      this->Head = Node::ptr(value);
      return;
    }
    Node* tmp = this->Head;
    while (true) {
      if (value < tmp->value) {
        if (tmp->left == NULL) {
          tmp->left = Node::ptr(value);
          break;
        } else {
          tmp = tmp->left;
          continue;
        }
      } else {
        if (tmp->right == NULL) {
          tmp->right = Node::ptr(value);
          break;
        } else {
          tmp = tmp->right;
          continue;
        }
      }
    }
  }
  void print() {
    if(this->Head != NULL) {
        this->Head->print(this->Head);
        printf("\n");
    } else {
        printf("empty\n");
    }
  }
};
