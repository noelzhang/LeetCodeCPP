class Queue {
private:
    stack<int> workingStack, helperStack;
public:
    // Push element x to the back of queue.
    void push(int x) {
        while(!workingStack.empty()){
            helperStack.push(workingStack.top());
            workingStack.pop();
        }
        helperStack.push(x);
        while(!helperStack.empty()){
            workingStack.push(helperStack.top());
            helperStack.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        workingStack.pop();
    }

    // Get the front element.
    int peek(void) {
        return workingStack.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return workingStack.empty();
    }
};