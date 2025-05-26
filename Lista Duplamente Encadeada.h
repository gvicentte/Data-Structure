#ifndef NEW_H
#define NEW_H

template <typename T>
class Node{
    public:
    Node<T> *next;
    Node<T> *prev;
    T D;
};

template <typename T>
class ListDE{
    private:
    Node<T> *Head;
    Node<T> *Tail;
    Node<T> *It;
    int n;
    public:
    ListDE();
    bool Empty();
    int Size();
    void Itbegin();
    void Itend();
    void ItMM();
    void Itmm();
    T GetFront();
    T GetBack();
    T GetIt();
    bool Itnull();
    void PushFront(T V);
    void PushBack(T V);
    void PushbIt(T V);
    void PushaIt(T V);
    void PopFront();
    void PopBack();
    void PopIt();
    void Clear();
};

template <typename T>
ListDE<T>::ListDE(){
    Head=Tail=It=NULL;
    n=0;
}

template <typename T>
bool ListDE<T>::Empty(){
    return !Head;
}

template <typename T>
int ListDE<T>::Size(){
    return n;
}

template <typename T>
void ListDE<T>::Itbegin(){
    It=Head;
}

template <typename T>
void ListDE<T>::Itend(){
    It=Tail;
}

template <typename T>
void ListDE<T>::Itmm(){
    It=It->prev;
}

template <typename T>
void ListDE<T>::ItMM(){
    It=It->next;
}

template <typename T>
bool ListDE<T>::Itnull(){
    return !It;
}

template <typename T>
T ListDE<T>::GetIt(){
    return It->D;
}

template <typename T>
T ListDE<T>::GetBack(){
    return Tail->D;
}

template <typename T>
T ListDE<T>::GetFront(){
    return Head->D;
}

template <typename T>
void ListDE<T>::PushFront(T V){
    Node<T> *P=new Node<T>;
    P->D=V;
    P->next=Head;
    P->prev=Head->prev;
    Head->prev=P;
    Head=P;
    n++;
}

template <typename T>
void ListDE<T>::PushBack(T V){
    Node<T> *P=new Node<T>;
    P->D=V;
    P->next=Tail->next;
    P->prev=Tail;
    Tail->next=P;
    Tail=P;
    n++;
}

template <typename T>
void ListDE<T>::PushbIt(T V){
    Node<T> *P=new Node<T>;
    P->D=V;
    P->next=It;
    P->prev=It->prev;
    if(It->prev){
        (It->prev)->next=P;
    }
    else{
        Head=P;
    }
    It->prev=P;
    n++;
}

template <typename T>
void ListDE<T>::PushaIt(T V){
    Node<T> *P=new Node<T>;
    P->D=V;
    P->prev=It;
    P->next=It->next;
    if(It->next){
        (It->next)->prev=P;
    }
    else{
        Tail=P;
    }
    It->next=P;
    n++;
}

template <typename T>
void ListDE<T>::PopIt(){
    Node<T> *P=It;
    It=It->next;
    delete P;
    if(!Head){
        Head=It;
    }
    if(!Tail){
        Tail=It;
    }
    n--;
}

template <typename T>
void ListDE<T>::PopBack(){
    Node<T> *P=Tail;
    Tail=Tail->prev;
    delete P;
    if(!Head){
        Head=Tail;
    }
    if(!It){
        It=Tail;
    }
    n--;
}

template <typename T>
void ListDE<T>::PopFront(){
    Node<T> *P=Head;
    Head=Head->next;
    delete P;
    if(!Tail){
        Tail=Head;
    }
    if(!It){
        It=Head;
    }
    n--;
}

template <typename T>
void ListDE<T>::Clear(){
    Node<T> *P;
    while(Head){
        P=Head;
        Head=Head->next;
        delete P;
    }
    Tail=It=Head;
    n=0;
}

#endif
