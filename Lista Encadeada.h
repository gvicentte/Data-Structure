#ifndef NEW_H
#define NEW_H

template <typename T>
class Node{
    public:
    Node *next;
    T T;
}

template <typename T>
class List{
    private:
    Node *Head;
    Node** It;
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
}

#endif
