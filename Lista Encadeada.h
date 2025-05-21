#ifndef NEW_H
#define NEW_H

template <typename T>
class Node{
    public:
    Node<T> *next;
    T G;
};

template <typename T>
class List{
    private:
    Node<T> *Head;
    Node<T>** It;
    int n;
    public:
    List();
    bool Empty();
    int size();
    T getfront();
    T getIt();
    void pushFront(T D);
    void pushIt(T D);
    void popFront();
    void popIt();
    void Clear();
    void ItMM();
    void ItBegin();
};

template <typename T>
List<T>::List(){
    n=0;
    Head=nullptr;
    It=&Head;
}

template <typename T>
bool List<T>::Empty(){
    return !Head;
}

template <typename T>
int List<T>::size(){
    return n;
}

template <typename T>
T List<T>::getfront(){
    return Head->G;
}

template <typename T>
T List<T>::getIt(){
    return (*It)->G;
}

template <typename T>
void List<T>::pushFront(T D){
    Node<T> *P=new Node<T>;
    P->G=D;
    P->next=Head;
    Head=P;
    n++;
}

template <typename T>
void List<T>::pushIt(T D){
    Node<T> *P=new Node<T>;
    P->G=D;
    P->next=*It;
    *It=P;
    n++;
}

template <typename T>
void List<T>::popFront(){
    Node<T> *P=Head;
    Head=Head->next;
    delete P;
    n--;
}

template <typename T>
void List<T>::popIt(){
    if(*It){
        Node<T> *P=*It;
        *It=P->next;
        n--;   
    }
}

template <typename T>
void List<T>::Clear(){
    Node<T> *P;
    while(Head){
        P=Head;
        Head=Head->next;
        delete P;
    }
    It=&Head;
    n=0;
}

template <typename T>
void List<T>::ItMM(){
    It=&((*It)->next);
}

template <typename T>
void List<T>::ItBegin(){
    It=&Head;
}

#endif
