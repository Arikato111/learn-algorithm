typedef struct doub_linkd {
  int length;
  struct node *head;
  struct node *last;
} doub_linkd;

typedef struct node {
  int value;
  struct node *next;
  struct node *prev;
} node;

struct node* Node(int value, struct node* prev) {
  struct node* n = (struct node*)malloc(sizeof(struct node));
  n->value = value;
  n->next = NULL;
  n->prev = prev;
  return n;
}

void insert(struct doub_linkd *n, int value) {
  // check if linked empty
  if (n->head == NULL) {
    n->head = Node(value, NULL);
    n->length++;
    return;
  }
  struct node *tmp = n->head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  tmp->next = Node(value, tmp);
  n->length++;
}

void insert_many(struct doub_linkd *n, int value[], int len)
{
   int s = 0;
   // check if linked empty
   if(n->head == NULL) {
        n->head = Node(value[0], NULL);
        n->length++;
        s++;
   }
    struct node *tmp = n->head;
    for (int i = s; i < len; i++) {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = Node(value[i], tmp);
        n->length++;
    }
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
  return l;
}