#include <bits/stdc++.h> 
class TwoStack {
public:
    int *arr;
    int st1=-1;
    int st2;
    int size;
    // Initialize TwoStack.
    TwoStack(int s) {
        // Write your code here.
        arr = new int[s];
        fill(arr, arr + s, -1);
        st2 =s;
        size =s;

    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        if (st1 != st2-1){
            arr[++st1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        if (st1 != st2-1){
            arr[--st2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(st1 < 0 ) return -1;
        int val = arr[st1];
        st1--;
        return val;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(st2 >=size) return -1;
        int val = arr[st2];
        st2++;
        return val;
    }
};
