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
    if(!Head){
        P->next=P->prev=P;
        Head=P;
    }
    else{
        P->next=Head;
        P->prev=Head->prev;
        (Head->prev)->next=P;
        Head->prev=P;
        Head=P;
    }
    n++;
}


template <typename T>
void ListCDE<T>::PushBack(T V){
    Node<T> *P=new Node<T>;
    P->D=V;
    P->next=Head;
    P->prev=Head->prev;
    (Head->prev)->next=P;
    Head->prev=P;
    n++;
}

template <typename T>
void ListCDE<T>::PushbIt(T V){
    Node<T> *P=new Node<T>;
    P->D=V;
    P->next=It;
    P->prev=It->prev;
    if(It==Head){
        Head=P;
    }
    (It->prev)->next=P;
    It->prev=P;
    n++;
}

template <typename T>
void ListCDE<T>::PushaIt(T V){
    Node<T> *P=new Node<T>;
    P->D=V;
    P->prev=It;
    P->next=It->next;
    (It->next)->prev=P;
    It->next=P;
    n++;
}

template <typename T>
void ListCDE<T>::PopIt(){
    if(!It){
        return;
    }
    Node<T> *P = It;
    if(n==1){
        Head=It=nullptr;
    }
    else{
        It=It->next;
        P->prev->next=P->next;
        P->next->prev=P->prev;
        if(Head==P){
            Head=P->next;
        }
    }
    delete P;
    n--;
}


template <typename T>
void ListCDE<T>::PopBack(){
    if(!Head){
        return;
    }
    Node<T> *P=Head->prev;
    if(n==1){
        Head=It=nullptr;
    }
    else{
        P->prev->next=Head;
        Head->prev=P->prev;
        if(It==P){
            It=Head;
        }
    }
    delete P;
    n--;
}


template <typename T>
void ListCDE<T>::PopFront(){
    if(!Head){
        return;
    }
    Node<T> *P=Head;
    if(n==1){
        Head=It=nullptr;
    }
    else{
        Head=Head->next;
        P->prev->next=Head;
        Head->prev=P->prev;
        if(It==P){
            It=Head;
        }
    }

    delete P;
    n--;
}


template <typename T>
void ListCDE<T>::Clear(){
    Node<T> *P;
    while(n>0){
        P=Head;
        Head=Head->next;
        delete P;
        n--;
    }
    It=Head;
}

#endif
