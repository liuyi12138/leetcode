typedef struct Node{
    int val;
    struct Node* next;
    struct Node* last;
} Node;

typedef struct {
    Node* min;
    Node* end;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* s = (MinStack*)malloc(sizeof(MinStack));
    Node* min = (Node*)malloc(sizeof(Node));
    min->last = NULL;
    min->next = NULL;
    min->val = INT_MAX;
    s->end = NULL;
    s->min = min;
    return s;
}

void minStackPush(MinStack* obj, int x) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->val = x;
    p->next = NULL;
    if(!obj->end){
        obj->end = p;
        p->last = NULL;
    }
    else{
        obj->end->next = p;
        p->last = obj->end;
        obj->end = p;
    }
    if(x <= obj->min->val){
        Node* min = (Node*)malloc(sizeof(Node));
        min->val = x;
        min->next = NULL;
        min->last = obj->min;
        obj->min->next = min;
        obj->min = min;
    }

}

void minStackPop(MinStack* obj) {
    if(obj->end){
        Node* temp;
        if(obj->end->val == obj->min->val){
            temp = obj->min;
            obj->min = obj->min->last;
            free(temp);
        }
        temp = obj->end;
        obj->end = obj->end->last;
        free(temp);
        if(obj->end)
            obj->end->next = NULL;

    }
}

int minStackTop(MinStack* obj) {
  return obj->end->val;
}

int minStackGetMin(MinStack* obj) {
    // if(obj->min->val == INT_MAX) return 0;
    return obj->min->val;
}

void minStackFree(MinStack* obj) {
    Node* temp;
    while(obj->end){
        temp = obj->end;
        obj->end = obj->end->last;
        free(temp);
    }
    while(obj->min){
        temp = obj->min;
        obj->min = obj->min->last;
        free(temp);
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/