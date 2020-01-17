typedef struct {
    int* stack;
    int size;
    int min;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* minstack = (MinStack*)malloc(sizeof(MinStack));
    
    minstack->stack = malloc(10000 * sizeof(int));
    minstack->size = 0;
    minstack->min = INT_MAX;
    
    return minstack;
}

void minStackPush(MinStack* obj, int x) {
    obj->stack[obj->size] = x;
    obj->size ++;
    if(x < obj->min) obj->min = x;
}

void minStackPop(MinStack* obj) {
    -- obj->size;
    if(obj->size == 0) obj->min = INT_MAX; 
    else {
        obj->min = obj->stack[0];
        for(int i = 0; i < obj->size; i++) {
            if(obj->stack[i] < obj->min) obj->min = obj->stack[i];
        }
    }
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->size-1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    
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
