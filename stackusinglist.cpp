#include<iostream>
#include<vector>
using namespace std;
//linked list implementation of stack 
struct Node
{
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
struct MyStack
{
    Node *head;
    int s3;
    MyStack(){
        head=NULL;
        s3=0;
    }
    void push(int x){
        Node *temp=new Node(x);
        temp->next=head;
        head=temp;
        s3++;
    }
    int pop(){
        if(head == NULL){
            return INT_MAX;
        }
        int res=head->data;
        Node *temp=head;
        head=head->next;
        delete(temp);
        s3--;
        return res;

    }
    int size(){
        return s3;
    }
    bool isEmpty(){
        return (head == NULL);
    }
    int peek(){
        if(head == NULL){
            return INT_MAX;
        }
        return head->data;
    }

};
int main(){
    MyStack s;
    s.push(10);
    s.push(20);s.push(30);
    cout<<s.size();
    cout<<s.pop();
    cout<<s.peek();
}

//array implementation of stack
struct MyStack{
    int *arr;
    int cap;
    int top;
    MyStack(int c){
        cap=c;
        arr=new int[cap];
        top=-1;
    }
    void push(int x){
        top++;
        arr[top]=x;
    }
    int pop(){
        if(top == (cap-1)){
            return 0;
        }
        int res=arr[top];
        top--;
        return res;
    }
    int peek(){
        if(top == -1){
            return 0;
        }
            return arr[top];
    }
    int size(){
        return (top+1);
    }
    bool isEmpty(){
        return (top == -1);
    }
};
//stack using vector
struct MyStack{
vector<int>v;
void push(int x){
    v.push_back(x);
}
int pop(){
    int res=v.back();
    v.pop_back();
    return res;
}
int size(){
    return v.size();
}
bool isEmpty(){
    return v.empty();
}
int peek(){
    return v.back();
}
};

