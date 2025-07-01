#include <stdio.h>
#define MAX_SIZE 1000

// Structure for stack (no pointers)
typedef struct {
    int top;
    int array[MAX_SIZE];
} Stack;

// Stack operations
void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (stack->top < MAX_SIZE - 1)
        stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return -1;
}

int peek(Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top];
    return -1;
}

// Function to calculate trapped water
int trapWater(int height[], int n) {
    Stack stack;
    initStack(&stack);
    int water = 0;
    
    // Process each bar
    for (int current = 0; current < n; current++) {
        // While stack is not empty and current bar has height greater than the bar at top of stack
        while (!isEmpty(&stack) && height[current] > height[peek(&stack)]) {
            int top = pop(&stack);
            
            if (isEmpty(&stack))
                break;
                
            // Calculate width between current bar and the bar at top of stack
            int distance = current - peek(&stack) - 1;
            
            // Calculate height of water that can be trapped
            int bounded_height = (height[current] < height[peek(&stack)] ? 
                                height[current] : height[peek(&stack)]) - height[top];
            
            // Add trapped water
            water += distance * bounded_height;
        }
        
        // Push current bar's index to stack
        push(&stack, current);
    }
    
    return water;
}

int main() {
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(height) / sizeof(height[0]);
    
    int result = trapWater(height, n);
    printf("Amount of water that can be trapped: %d\n", result);
    
    return 0;
}
