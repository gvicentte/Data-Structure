#ifndef NEW_H
#define NEW_H

template <class thing>

class Node{
    public:
    Thing D;
    Node *next;
}

class Queue{
    private:
        Node *Head;
        Node *Tail;
        int n;
    public:
        Queue();
        bool Empty();
        int size();
        Thing Front();
        Thing Back();
        void Push(Thing T);
        void Pop();
        void Clear();
};

Queue::Queue(){
    Head=Tail=n=0;;
}

bool Queue::Empty(){
    return !Head;
}

int Queue::size(){
    return n;
}

Thing Queue::Front(){
    return Head->D;
}

Thing Queue::Back(){
    return Tail->D;
}

void Queue::Push(Thing T){
    Node *P=new Node;
    P->D=T;
    P->next=0;
    if(!Head){
        Head=P;
    }
    else{
        Tail->next=P;
    }
    Tail=P;
    n++;
}

void Queue::Pop(){
    Node *P=Head;
    Head=Head->next;
    delete P;
    if(!Head){
        Tail=Head;
    }
    n--;
}

void Queue::Clear(){
    Node *P;
    while(Head){
        P=Head->next;
        Head=Head->next;
        delete P;
    }
    Tail=n=0;
}

#endif