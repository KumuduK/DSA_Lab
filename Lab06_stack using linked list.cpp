#include <bits/stdc++.h>
using namespace std;

class StackNode {
public:
    int data;
    StackNode* next;
};
  
StackNode* newNode(int data){
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
  
int isEmpty(StackNode* root){
    return !root;
}
  
void push(StackNode** root, int data){
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}
  
int pop(StackNode** root){
    if (isEmpty(*root))
        return INT_MIN;
    StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
  
    return popped;
}
  
int peek(StackNode* root){
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

void display(StackNode* root){
    while(!isEmpty(root)){
        cout << peek(root) <<" ";
        pop(&root);
    }
}
  

int main(){
    clock_t time_req;
    StackNode* root = NULL;
  
    time_req = clock();
    push(&root, 8);
    push(&root, 10);
    push(&root, 5);
    push(&root, 11);
    push(&root, 15);
    push(&root, 23);
    push(&root, 6);
    push(&root, 18);
    push(&root, 20);
    push(&root, 17);
    display(root);
    cout << "\n";
    pop(&root);
    pop(&root);
    pop(&root);
    pop(&root);
    pop(&root);
    display(root);
    cout << "\n";
    push(&root, 4);
    push(&root, 30);
    push(&root, 3);
    push(&root, 1);
    display(root);
    cout << "\n";
    time_req = clock() - time_req; 
    cout << "Time taken is: " << (float)time_req/CLOCKS_PER_SEC << " seconds\n" << endl;
    
    return 0;
}
