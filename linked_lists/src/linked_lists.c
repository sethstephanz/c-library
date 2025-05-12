#include "linked_lists.h"
#include <stdio.h>
#include <stdlib.h>

Node *node() {
    struct Node *p;
    p = (struct Node *)malloc(sizeof(Node));
    return p;
}

