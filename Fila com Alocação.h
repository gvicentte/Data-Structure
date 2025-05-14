#ifndef NEW_H
#define NEW_H

template <typename T>
class Node {
public:
    T D;
    Node* next;
};

template <typename T>
class Queue {
private:
    Node<T>* Head;
    Node<T>* Tail;
    int n;

public:
    Queue();
    bool Emptyq();
    int Sizeq();
    void Pushq(T S);
    void Popq();
    void Clearq();
    T front();
};

template <typename T>
Queue<T>::Queue() {
    Head=Tail=nullptr;
    n=0;
}

template <typename T>
bool Queue<T>::Emptyq(){
    return !Head;
}

template <typename T>
int Queue<T>::Sizeq(){
    return n;
}

template <typename T>
void Queue<T>::Pushq(T S){
    Node<T>* P=new Node<T>;
    P->D=S;
    P->next=nullptr;
    if(!Head){
        Head=P;
    } 
    else{
        Tail->next=P;
    }
    Tail=P;
    n++;
}

template <typename T>
void Queue<T>::Popq(){
    Node<T>* P=Head;
    Head=Head->next;
    delete P;
    if(!Head){
        Tail=nullptr;
    }
    n--;
}

template <typename T>
void Queue<T>::Clearq(){
    Node<T>* P;
    while(Head){
        P=Head;
        Head=Head->next;
        delete P;
    }
    Tail=nullptr;
    n=0;
}

template <typename T>
T Queue<T>::front(){
    return Head->D;
}

#endif
