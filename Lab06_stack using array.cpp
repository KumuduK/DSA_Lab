#include <bits/stdc++.h>
using namespace std;
#define max_val 1000
  
class Stack {
    int top_val;
 
public:
    int arr[max_val];
  
    Stack() { top_val = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};
  
bool Stack::push(int x){
    if (top_val >= (max_val - 1)) {
        return false;
    }
    else {
        arr[++top_val] = x;
        return true;
    }
}
  
int Stack::pop(){
    if (top_val < 0) {
        return 0;
    }
    else {
        int x = arr[top_val--];
        return x;
    }
}

int Stack::peek()
{
    if (top_val < 0) {
        return 0;
    }
    else {
        int x = arr[top_val];
        return x;
    }
}
  
bool Stack::isEmpty()
{
    return (top_val < 0);
}

void display(class Stack s){
    while(!s.isEmpty()){
        cout << s.peek() <<" ";
        s.pop();
    }
}

int main(){
    clock_t time_req;
    class Stack s;
    time_req = clock();
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    display(s);
    cout << "\n";
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    display(s);
    cout << "\n";
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    display(s);
    cout << "\n";
    time_req = clock() - time_req; 
    cout << "Time taken is: " << (float)time_req/CLOCKS_PER_SEC << " seconds\n" << endl;
    
    return 0;
}
