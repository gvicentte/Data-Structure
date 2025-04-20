#ifndef NEW_H
#define NEW_H

template <class thing>

class Node{
    public:
    Thing D;
    Node *next;
}

class Stack{
    private:
        Node *top;
        int n;
    public:
        Stack();
        bool Empty();
        int size();
        Thing TOP();
        void Push(Thing T);
        void Pop();
        void Clear();
};

Stack::Stack(){
    top=n=0;
}

bool Stack::Empty(){
    return !top;
}

int Stack::size(){
    return n;
}

Thing Stack::TOP(){
    return top->D;
}

void Stack::Push(Thing T){
    Node *P=new Node;
    P->D=T;
    P->next=top;
    top=P;
    n++;
}

void Stack::Pop(){
    Node *P=top;
    top=top->next;
    delete P;
    n--;
}

void Stack::Clear(){
    Node *P;
    while(top){
        P=top->next;
        top=top->next;
        delete P;
    }
    n=0;
}

#endif