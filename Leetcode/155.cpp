class MinStack {
public:
    stack<int>element, minVal;
    MinStack() {
    }

    void push(int x) {
        element.push(x);
        if (minVal.empty() || x <= minVal.top()) {
            minVal.push(x);
        }
    }

    void pop() {
        if (element.empty()) return;
        if (element.top() == minVal.top()) {
            minVal.pop();
        }
        element.pop();
    }

    int top() {
        return element.top();
    }

    int getMin() {
        return minVal.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */