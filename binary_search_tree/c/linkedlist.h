typedef struct linked {
    struct node *next;    
    void (*insert)(struct linked *link, int value);
    void (*insert_many)(struct linked *link, int value[], int size);
    void (*show)(struct linked *link);
} linked;

typedef struct node {
  ;
    int value;
    struct node *left;
    struct node *right;
} node;

node* Node(int value) {
    node *n = (node*)malloc(sizeof(node));
    n->value = value;
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insert_node(node *n, int value) {
    if(n->value >= value) {
        if(n->left == NULL) {
            n->left = Node(value);
        } else {
            insert_node(n->left, value);
        }
    } else {
        if(n->right == NULL) {
            n->right = Node(value);
        } else {
            insert_node(n->right, value);
        }
    }
}

void insert(linked *link, int value) {
    if(link->next == NULL) {
       link->next = Node(value);
    } else {
        insert_node(link->next, value);
    }
}
void insert_many(linked *link, int value[], int size) {
    int start_at = 0;
    if(link->next == NULL) {
        link->next = Node(value[0]);
        start_at++;
    }
    for(;start_at < size; start_at++) {
        insert_node(link->next, value[start_at]);
    }
}

result get_node(node *n,int index,  int now_index) {
    result v;
    if(n->left != NULL) {
        v = get_node(n->left, index, now_index);
        if(!v.is_error) return v;
        now_index = v.value;
   }
   if(now_index == index) return Result(false, n->value);
   now_index++;
   if(n->right != NULL) {
        v = get_node(n->right, index, now_index);
        if(!v.is_error) return v;
        now_index = v.value;
   }
   return Result(true, now_index);
}

result get(linked *n, int index) {
    if(n->next == NULL) return Result(true, -1);
    return get_node(n->next, index, 0);
}

int show_node(node *n, int index) {
    if (n->left != NULL) {
        index = show_node(n->left, index);
    }
   printf("arr[%d] = %d\n", index, n->value);
    index++;
   if(n->right != NULL) {
       index = show_node(n->right, index);
   }
   return index;
}

void show(linked *link) {
    show_node(link->next, 0);
    printf("\n");
}

linked Linked() {
    linked li;
    li.next = NULL;
    li.insert = &insert;
    li.insert_many = &insert_many;
    li.show = &show;
    return li;
}

