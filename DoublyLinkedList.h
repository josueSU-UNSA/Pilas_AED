#include<iostream>
#include "Node.h"
template<typename T>
class DoublyLinkedList{
    private:

        Node<T>*head;
        Node<T>*actual;
        int longitud;

    public:

    //          FIRMAS

        //Constructor por defecto
        DoublyLinkedList();

        //Constructor incializado con un numero
        DoublyLinkedList(T nodo);

        //Metodo que retornara la longitud de la lista
        int getLongitud();

        Node<T>*getActual()const;

        void setActual(Node<T>*);

        void moveNextActual();
        void movePreviusActual();
        void moveEndWithEnd();
        void moveEndWithoutEnd();
        void moveBeginWithBegin();
        void moveBeginWithoutBegin();


        //Agregar al ultimo
        void pushBack(T nodo);

        //Borrar el ultimo
        void popBack();

        //Agregar al principio
        void pushFront(T nodo);

        //Borrar el inicio
        void popFront();

        bool find(T);

        //Busca un elemento por indice
        int findIndex(T);

        //Metodo que retorna la direccion del primer nodo
        Node<T>*Begin();

        //Metodo que retorna la direccion del ultimo nodo o anterior a la cola
        Node<T>*End();

        //Sobrecarga del operador de indexacion 
        //Este retorna un objeto con el fin de 
        //Utilizar dicho efecto posteriormente 
        //para posteriormente hace un cambio basico 
        //como lo seria DoublyLinkedList[Indice]=T value
        Node<T>& operator [](int num);

        //Metodo que permitira ordenar la lista 
        void sort();

        void sortReverse();

        //Metodo que permite imprimir la lista
        void print();

        void printRecursivoInicioFin(Node<T>*);

        void printRecursivoInicioFin();



        //Metodo que permite imprimir la lista en orden contrario
        void printReverseWithEnd();

        void printReverseWithoutEnd();

        void printRecursivoFinInicio(Node<T>*aux);

        void printRecursivoFinInicio();



};

//      IMPLEMENTACION DE LOS METODOS

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(){

    this->head=nullptr;
    this->longitud=0;
    this->actual=nullptr;

}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(T nodo){
            
    this->head=new Node<T>(nodo);
    this->longitud=1;
    this->actual=nullptr;

}

template<typename T>
int DoublyLinkedList<T>::getLongitud(){
    return this->longitud;
}

template<typename T>
Node<T>* DoublyLinkedList<T>::getActual()const{
    return this->actual;
}

template<typename T>
void DoublyLinkedList<T>::setActual(Node<T>* actual){
    this->actual=actual;
}

template<typename T>
void DoublyLinkedList<T>::moveNextActual(){

    if(!this->head){
        return;
    }

    /*
    else if(!actual->getNext()){
        return;
    }
    */

    this->actual=actual->getNext();
}

template<typename T>
void DoublyLinkedList<T>::movePreviusActual(){
    if(!this->head){
        return;
    }

    /*
    else if(!actual->getPrev()){
        return;
    }
    */

    this->actual=actual->getPrev();

}

template<typename T>
void DoublyLinkedList<T>::moveEndWithEnd(){
    this->actual=this->End();
}

template<typename T>
void DoublyLinkedList<T>::moveEndWithoutEnd(){

    if(!this->head){
        return;
    }

    /*
    else if(!this->actual->getNext()){
        return;
    }
    */

    while(this->actual->getNext()){
        actual=actual->getNext();
    }

}

template<typename T>
void DoublyLinkedList<T>::moveBeginWithBegin(){
    this->actual=this->Begin();
}

template<typename T>
void DoublyLinkedList<T>::moveBeginWithoutBegin(){
    this->actual=this->head;
}

template<typename T>
void DoublyLinkedList<T>::pushBack(T nodo){

    if(!this->head){
        this->head=new Node<T>(nodo);
    }

    else{

        Node<T>*aux=this->head;

        while(aux->getNext()){
            aux=aux->getNext();
        }

        aux->setNext(new Node<T>(nodo));
        aux->getNext()->setPrev(aux);
    }

        this->longitud++;

}

template<typename T>
void DoublyLinkedList<T>::popBack(){

    if(!head){
        return;
    }

    else if(this->longitud==1){

        delete this->head;
        this->head=nullptr;

    }

    else{

        Node<T>*aux=this->head;

        while(aux->getNext()){
            aux=aux->getNext();
        }

        delete aux->getNext();
        aux->setNext(nullptr);
        this->longitud--;

    }

}


template<typename T>
void DoublyLinkedList<T>::pushFront(T nodo){

    if(!head){

        this->head=new Node<T>(nodo);

    }

    else{

        this->head->setPrev(new Node<T>(nodo));
        this->head->getPrev()->setNext(this->head);
        this->head=this->head->getPrev();

    }
        this->longitud++;

}

template<typename T>
void DoublyLinkedList<T>::popFront(){

    if(!head){
        return;
    }

    else if(this->longitud==1){
        delete this->head;
    }

    else{

        //consultar esta parte
        this->head=head->getNext();
        delete this->head->getPrev();
        this->head->setPrev(nullptr);//aun funciona esta parte cuando hay un solo nodo
        this->longitud--;

    }

}

template<typename T>
bool DoublyLinkedList<T>::find(T value){

    Node<T>*aux=this->head;

    while(aux){

        if(aux->getValue()==value){
            return true;
        }

        aux=aux->getNext();

    }

    return false;

}

template<typename T>
int DoublyLinkedList<T>::findIndex(T value){
    
    int count=0;
    Node<T>*aux=this->head;

    while(aux){

        if(aux->getValue()==value){
            return count;
        }
        aux=aux->getNext();
        count++;

    }

    return -1;

}

template<typename T>
Node<T>* DoublyLinkedList<T>::Begin(){
    return this->head;
}

template<typename T>
Node<T>* DoublyLinkedList<T>::End(){


    if(!this->head){
        return nullptr;
    }

    Node<T>*aux=this->head;

    while(aux->getNext()){
        aux=aux->getNext();
    }
    return aux;


}

template<typename T>
Node<T>& DoublyLinkedList<T>::operator [](int num){

    if(num>=this->longitud){
        num=(num%longitud)-1;
    }

    else if (this->head==nullptr || num==0){
        return *(this->head);
    }

    else if(num==this->longitud-1){
        return *(this->End());
    }

    Node<T>*aux=this->head;

    for(int i=0;i<num;i++)
        aux=aux->getNext();

    return *(aux);

}

template<typename T>
void DoublyLinkedList<T>::sort(){

    Node<T> *aux1 = this->head;
    Node<T>*aux2=nullptr;
    T temp;

    while(aux1->getNext()){

        aux2 = aux1->getNext();

        while(aux2){

            if(aux2->getValue() < aux1->getValue()){

                temp = aux1->getValue();
                aux1->setValue(aux2->getValue());
                aux2->setValue(temp);

            }
            
            aux2 = aux2->getNext(); 
        
        }

        aux1 = aux1->getNext();

    }
    
}

template<typename T>
void DoublyLinkedList<T>::sortReverse(){
    
    Node<T> *aux1 = this->head;
    Node<T> *aux2=nullptr;
    T temp;

    while(aux1->getNext()){

        aux2 = aux1->getNext();

        while(aux2){

            if(aux2->getValue() > aux1->getValue()){

                temp = aux1->getValue();
                aux1->setValue(aux2->getValue());
                aux2->setValue(temp);

            }

            aux2 = aux2->getNext(); 

        }

        aux1 = aux1->getNext();

    }

}

template<typename T>
void DoublyLinkedList<T>::print(){

    Node<T>*aux=this->head;

    while (aux){

        std::cout<<"<-"<<aux->getValue()<<"->";
        aux=aux->getNext();

    }

    std::cout<<std::endl;

}

template<typename T>
void DoublyLinkedList<T>::printRecursivoInicioFin(Node<T>*aux){
    if(!aux){
        return;
    }

    else{
        std::cout<<"<-"<<aux->getValue()<<"->";
        printRecursivoInicioFin(aux->getNext());
    }

    std::cout<<std::endl;

}

template<typename T>
void DoublyLinkedList<T>::printRecursivoInicioFin(){
    printRecursivoInicioFin(this->head);
}


template<typename T>
void DoublyLinkedList<T>::printReverseWithEnd(){

    Node<T>*aux=this->End();

    while (aux){

        std::cout<<"<-"<<aux->getValue()<<"->";
        aux=aux->getPrev();

    }

    std::cout<<std::endl;

}

template<typename T>
void DoublyLinkedList<T>::printReverseWithoutEnd(){

    Node<T>*aux=this->head;
    if(!aux){
        return;
    }
    else{
        
        while(aux->getNext()){
            aux=aux->getNext();
        }
        while(aux){
            std::cout<<"<-"<<aux->getValue()<<"->";
            aux=aux->getPrev();
        }

        std::cout<<std::endl;

    }

}

template<typename T>
void DoublyLinkedList<T>::printRecursivoFinInicio(Node<T>*aux){

    if(!aux){
        return;
    }

    else{
        printRecursivoFinInicio(aux->getNext());
        std::cout<<"<-"<<aux->getValue()<<"->";
    }

}

template<typename T>
void DoublyLinkedList<T>::printRecursivoFinInicio(){
    printRecursivoFinInicio(this->head);
}


