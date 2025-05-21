#ifndef NEW_H
#define NEW_H

template <typename T>
class Node{
    Node *next;
    Node *prev;
    T D;
}

template <typename T>
class ListDE{
    private:
    Node *Head;
    Node *Tail;
    Node *It;
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
}

#endif
