#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class MyStack {
private:
    queue<int> q;
    // 记录栈顶元素
    int top_elem;

public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        // 记录下最后入队的元素为top_elem
        // 以便top()时可以直接返回。
        top_elem = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n = q.size();
        // 注意是剩最后2个的时候
        // 此时队列头的这个元素是下一个要出栈的元素
        while (n > 2) {
            q.push(q.front());
            q.pop();
            n--;
        }
        // 更新top elem
        top_elem = q.front();
        q.push(q.front());
        q.pop();

        int pop_elem = q.front();
        q.pop();
        return pop_elem;
    }

    /** Get the top element. */
    int top() {
        return top_elem;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
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