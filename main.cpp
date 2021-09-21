/*
crear pila hacer q imprima al reves
escribir code necesario para imprimir al reves
usando pop empty o push top retorna el valor
*/
#include<iostream>
#include<conio.h>
using namespace std;

template<typename T>
class Node
{
public:
    T dato;
    Node<T>*anterior;
public:
    Node(T _dato){
        dato=_dato;
        anterior=0;
    }
};
template<typename T>
class pila
{
private:
    Node<T>*tope;

public:
    pila(){
        tope=0;
    }
/*
    void push(T dato){
        
        if(!tope){
            this->tope=new Node<T>(dato);
        }
        else{
            Node<T>*aux=this->tope;
            while (aux->anterior)
            {
                aux=aux->anterior;
            }
            aux->anterior=new Node<T>(dato);

        }
    }
*/
    bool push(T dato){
        if(!tope){
            this->tope=new Node<T>(dato);
            return true;
        }
        else{
            
            Node <T>*aux=this->tope;
            while(aux->anterior){
                if(aux->dato==dato){
                    return false;
                }
                cout<<aux->dato<<" -> ";
                aux=aux->anterior;
            }
            cout<<aux->dato<<" -> ";
            
            if(aux->dato!=dato){
                aux->anterior=new Node<T>(dato);
                cout<<aux->anterior->dato<<" -> ";
                cout<<endl;
                return true;
            }
            return false;
            


        }
    }
/*
    void pop(){
        if(!tope){
            return;
        }
        else{
            Node<T>*aux=this->tope;
            while (aux->anterior)
            {
                aux=aux->anterior;
            }
            delete aux;
            aux=0;

        }
    }
    */
    bool pop(){
        if(!tope){
            return false;
        }
        else{

            Node<T>*aux=this->tope;
            this->tope=aux->anterior;
            delete aux;
            return true;

        }
    }

    bool isEmpty(){
        if(this->tope==0){
            return true;
        }
        return false;
    }

    T top(){
        return (this->tope)? this->tope->dato:0;
    }
    void print(){
        if(isEmpty()==true){
            return;
        }

    }

};

int main(){
    pila<int>testPila;
    //testPila.push(7);
    cout<<testPila.top()<<endl;
    cout<<testPila.isEmpty()<<endl;

    testPila.push(7);
    testPila.push(8);
    testPila.push(9);
    testPila.push(10);
    testPila.push(11);
    testPila.push(12);
    getch();
    return 0;
}



