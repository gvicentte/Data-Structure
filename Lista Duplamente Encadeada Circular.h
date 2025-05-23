#ifndef NEW_H
#define NEW_H

template <typename T>
class Node{
    Node<T> *next;
    Node<T> *prev;
    T D;
};

template <typename T>
class ListCDE{
    private:
    Node<T> *Head;
    Node<T> *It;
    int n;
    public:
    ListCDE();
    bool Empty();
    int Size();
    void Itbegin();
    void Itend();
    void ItMM();
    void Itmm();
    T GetFront();
    T GetBack();
    T GetIt();
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
ListCDE<T>::ListCDE(){
    Head=It=NULL;
    n=0;
}

template <typename T>
bool ListCDE<T>::Empty(){
    return !Head;
}

template <typename T>
int ListCDE<T>::Size(){
    return n;
}

template <typename T>
void ListCDE<T>::Itbegin(){
    It=Head;
}

template <typename T>
void ListCDE<T>::Itend(){
    It=Head->prev;
}

template <typename T>
void ListCDE<T>::Itmm(){
    It=It->prev;
}

template <typename T>
void ListCDE<T>::ItMM(){
    It=It->next;
}

template <typename T>
T ListCDE<T>::GetIt(){
    return It->D;
}

template <typename T>
T ListCDE<T>::GetBack(){
    return (Head->prev)->D;
}

template <typename T>
T ListCDE<T>::GetFront(){
    return Head->D;
}

template <typename T>
void ListCDE<T>::PushFront(T V){
    Node<T> *P=new Node<T>;
    P->D=V;
    P->next=Head;
    P->prev=Head->prev;
    Head->prev=P;
    Head=P;
    n++;
}

template <typename T>
void ListCDE<T>::PushBack(T V){
    Node<T> *P=new Node<T>;
    P->D=V;
    P->next=Tail->next;
    P->prev=Tail;
    Tail->next=P;
    Tail=P;
    n++;
}

template <typename T>
void ListCDE<T>::PushbIt(T V){
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
void ListCDE<T>::PushaIt(T V){
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
void ListCDE<T>::PopIt(){
    Node<T> *P=It;
    It=It->next;
    delete P;
    if(!Head){
        Head=P;
    }
    n--;
}

template <typename T>
void ListCDE<T>::PopBack(){
    Node<T> *P=Head->prev;
    (Head->prev)->next=Head;
    delete P;
    if(!It){
        It=Head;
    }
    n--;
}

template <typename T>
void ListCDE<T>::PopFront(){
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
void ListCDE<T>::Clear(){
    Node<T> *P;
    while(n){
        P=Head;
        Head=Head->next;
        delete P;
        n--;
    }
    It=Head;
}

#endif
