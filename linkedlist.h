struct linked
{
    struct node *next;
    void (*insert)(struct linked *n, int value);
    void (*insert_many)(struct linked *n, int value[], int len);
    struct result (*get_index)(struct linked *n, int index);
    struct result (*pop)(struct linked *n);
    struct result (*pop_index)(struct linked *n, int index);
    struct result (*set)(struct linked *n, int index, int value);
    int (*len)(struct linked *n);
    void (*show)(struct linked *n);
};

struct node
{
    int value;
    struct node *next;
};

void insert(struct linked *n, int value)
{
    // check if linked empty
    if(n->next == NULL) {
        n->next = (struct node*)malloc(sizeof(struct node));
        n->next->next = NULL;
        n->next->value = value;
        return;
    }
    struct node *tmp = n->next;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = (struct node *)malloc(sizeof(struct node));
    tmp->next->next = NULL;
    tmp->next->value = value;
}

void insert_many(struct linked *n, int value[], int len)
{
   int s = 0;
   // check if linked empty
   if(n->next == NULL) {
        n->next = (struct node *)malloc(sizeof(struct node));
        n->next->next = NULL;
        n->next->value = value[0];
        s++;
   }
    struct node *tmp = n->next;
    for (int i = s; i < len; i++) {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = (struct node *)malloc(sizeof(struct node));
        tmp->next->next = NULL;
        tmp->next->value = value[i];
    }
}

struct result get_index(struct linked *n, int index)
{
    if(n->next == NULL) return Result(true, 0);
    struct node *tmp = n->next;
    for (int i = 1; i <= index; i++) {
        if (tmp->next == NULL)
            return Result(true, 0);
        tmp = tmp->next;
    }
    return Result(false, tmp->value);
}

struct result pop(struct linked *n) {
    int v = 0;
    // check empty 
    if(n->next == NULL) return Result(true, -1);
    // check is one element in array
    if(n->next->next == NULL) {
        v = n->next->value;
        n->next = NULL;
        return Result(false, v);
    }
    struct node *tmp = n->next;
    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    }
    v = tmp->next->value;
    tmp->next = NULL;
    return Result(false, v);
}

struct result pop_index(struct linked *n, int index)
{
    // check empty
    if(n->next == NULL) return Result(true, -1);
    int v;
    // check is head change head to index 1
    if(index == 0) {
        v = n->next->value;
        if (n->next->next != NULL)
            n->next = n->next->next;
        else
            n->next = NULL;
        return Result(false, v);
    }
    struct node *tmp = n->next;
    for (int i = 1; i < index; i++) {
        if (tmp->next == NULL)
            return Result(true, -1);
        tmp = tmp->next;
    }
    v = tmp->next->value;
    // is last index 
    if(tmp->next->next != NULL) {
        tmp->next = tmp->next->next;
    } else {
        tmp->next = NULL;
    }
    return Result(false, v);
}

struct result set(struct linked *n, int index, int value) {
    struct node *tmp = n->next;
    for(int i = 0; i < index; i++) {
        if(tmp->next  == NULL) return Result(true, -1);
        tmp = tmp->next;
    }
    tmp->value = value; 
    return Result(false, value);
}

int len(struct linked *n) {
    if(n->next == NULL) return 0;
    struct node *tmp = n->next;
    int count = 1;
    for(count = 1; tmp->next != NULL; count++) {
        tmp = tmp->next;
        count++;
    }
    return count;
}

void show(struct linked *n)
{
    if(n->next == NULL) {
        printf("empty array\n");
        return;
    }
    int count = 0;
    struct result v = get_index(n, 0);
    while (!v.is_error)
    {
        printf("arr[%d] = %d\n", count, v.value);
        count++;
        v = get_index(n, count);
    }
}

struct linked Linked()
{
    struct linked n;
    n.next = NULL;
    n.insert = &insert;
    n.insert_many = &insert_many;
    n.get_index = &get_index;
    n.pop = &pop;
    n.pop_index = &pop_index;
    n.set = &set;
    n.len = &len;
    n.show = &show;
    return n;
}