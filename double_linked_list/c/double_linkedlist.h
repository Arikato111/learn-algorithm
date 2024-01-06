typedef struct doub_linkd {
  int length;
  struct node *head;
  struct node *last;
  void (*insert)(struct doub_linkd *n, int value);
  void (*insert_many)(struct doub_linkd *n, int value[], int len);
  struct result (*pop)(struct doub_linkd *n);
  struct result (*pop_index)(struct doub_linkd *n, int index);
  struct result (*set)(struct doub_linkd *n, int index, int value);
  struct result (*get_index)(struct doub_linkd *n, int index);
  void (*show)(struct doub_linkd *n);
} doub_linkd;

typedef struct node {
  int value;
  struct node *next;
  struct node *prev;
} node;

struct node *Node(int value, struct node *prev) {
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->value = value;
  n->next = NULL;
  n->prev = prev;
  return n;
}

void insert(struct doub_linkd *n, int value) {
  // check if linked empty
  if (n->head == NULL) {
    n->head = Node(value, NULL);
    n->last = n->head;
    n->length++;
    return;
  }
  struct node *tmp = n->head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  tmp->next = Node(value, tmp);
  n->last = tmp->next;
  n->length++;
}

void insert_many(struct doub_linkd *n, int value[], int len) {
  int s = 0;
  // check if linked empty
  if (n->head == NULL) {
    n->head = Node(value[0], NULL);
    n->last = n->head;
    n->length++;
    s++;
  }
  struct node *tmp = n->head;
  for (int i = s; i < len; i++) {
    while (tmp->next != NULL) {
      tmp = tmp->next;
    }
    tmp->next = Node(value[i], tmp);
    n->last = tmp->next;
    n->length++;
  }
}

struct result pop(struct doub_linkd *n) {
  int v = 0;
  // check empty
  if (n->head == NULL) return Result(true, -1);
  // check is one element in array
  if (n->head->next == NULL) {
    v = n->head->value;
    free(n->head);
    n->head = NULL;
    n->last = NULL;
    n->length--;
    return Result(false, v);
  }
  struct node *tmp = n->last->prev;
  v = tmp->next->value;
  free(tmp->next);
  tmp->next = NULL;
  n->last = tmp;
  n->length--;
  return Result(false, v);
}

struct result pop_index(struct doub_linkd *n, int index) {
  // check empty
  if (n->head == NULL) return Result(true, -1);
  int v;
  struct node *pointer_tmp;
  // check is head change head to index 1
  if (index == 0) {
    v = n->head->value;
    if (n->head->next != NULL) {
      // use pointer_tmp to keep address from pointer to free memory in next
      // step
      pointer_tmp = n->head;
      n->head = n->head->next;
      n->length--;
      free(pointer_tmp);
    } else {
      free(n->head);
      n->head = NULL;
    }
    n->length--;
    return Result(false, v);
  }
  struct node *tmp = n->head;
  for (int i = 1; i < index; i++) {
    if (tmp->next == NULL) return Result(true, -1);
    tmp = tmp->next;
  }
  v = tmp->next->value;
  // is last index
  if (tmp->next->next != NULL) {
    pointer_tmp = tmp->next;
    tmp->next = tmp->next->next;
    free(pointer_tmp);
  } else {
    free(tmp->next);
    tmp->next = NULL;
    n->last = tmp;
  }
  n->length--;
  return Result(false, v);
}

struct result set(struct doub_linkd *n, int index, int value) {
  struct node *tmp = n->head;
  for (int i = 0; i < index; i++) {
    if (tmp->next == NULL) return Result(true, -1);
    tmp = tmp->next;
  }
  tmp->value = value;
  return Result(false, value);
}

struct result get_index(struct doub_linkd *n, int index) {
  if (n->head == NULL) return Result(true, 0);
  struct node *tmp = n->head;
  for (int i = 1; i <= index; i++) {
    if (tmp->next == NULL) return Result(true, 0);
    tmp = tmp->next;
  }
  return Result(false, tmp->value);
}

void show(struct doub_linkd *n) {
  if (n->head == NULL) {
    printf("empty array\n");
    return;
  }
  int count = 0;
  struct result v = get_index(n, 0);
  while (!v.is_error) {
    printf("arr[%d] = %d\n", count, v.value);
    count++;
    v = get_index(n, count);
  }
}

struct doub_linkd DoubLinkd() {
  struct doub_linkd l;
  l.head = NULL;
  l.last = NULL;
  l.length = 0;
  l.insert = &insert;
  l.insert_many = &insert_many;
  l.pop = &pop;
  l.pop_index = &pop_index;
  l.set = &set;
  l.get_index = &get_index;
  l.show = &show;
  return l;
}