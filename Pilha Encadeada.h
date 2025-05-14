#ifndef NEW_H
#define NEW_H

template <typename T>
class Node {
public:
    T D;
    Node* next;
};

template <typename T>
class Stack {
private:
    int n;
    Node<T>* top;

public:
    Stack();
    bool Emptys();
    int Sizes();
    void Pushs(T S);
    void Pops();
    void Clears();
    T TOP();
};

template <typename T>
Stack<T>::Stack(){
    top=nullptr;
    n=0;
}

template <typename T>
bool Stack<T>::Emptys(){
    return !top;
}

template <typename T>
int Stack<T>::Sizes(){
    return n;
}

template <typename T>
T Stack<T>::TOP(){
    return top->D;
}

template <typename T>
void Stack<T>::Pushs(T S){
    Node<T>* P=new Node<T>;
    P->D=S;
    P->next=top;
    top=P;
    n++;
}

template <typename T>
void Stack<T>::Pops(){
    Node<T>* P=top;
    top=top->next;
    delete P;
    n--;
}

template <typename T>
void Stack<T>::Clears(){
    Node<T>* P;
    while(top){
        P=top;
        top=top->next;
        delete P;
    }
    n=0;
}

#endif
