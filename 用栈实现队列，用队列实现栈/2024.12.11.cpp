//用栈实现队列
//https://leetcode.cn/problems/implement-queue-using-stacks/submissions/586442179/
class MyQueue {
public:
    stack<int> IN;
    stack<int> OUT;
    MyQueue() {

    }

    void push(int x) {
        IN.push(x);
    }

    int pop() {
        if (!OUT.empty())
        {
            int rv = OUT.top();
            OUT.pop();
            return rv;
        }
        while (!IN.empty())
        {
            int msg = IN.top();
            IN.pop();
            OUT.push(msg);
        }
        int rv = OUT.top();
        OUT.pop();
        return rv;


    }

    int peek() {
        if (!OUT.empty())
        {
            return OUT.top();
        }
        while (!IN.empty())
        {
            int msg = IN.top();
            IN.pop();
            OUT.push(msg);
        }
        return OUT.top();


    }

    bool empty() {
        return IN.empty() && OUT.empty();

    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */




//用队列实现栈
//https://leetcode.cn/problems/implement-stack-using-queues/submissions/586444568/
class MyStack {
public:
    queue<int> q2;//备份用
    queue<int> q1;
    MyStack() {

    }

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        while (q1.size() != 1)
        {
            int val = q1.front();
            q2.push(val);
            q1.pop();
        }
        int rv = q1.front();
        q1.pop();
        q1 = q2;
        q2 = queue<int>();
        return rv;
    }

    int top() {
        return q1.back();
    }

    bool empty() {
        return q1.empty();

    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */















