#include<iostream>


template<typename TIPONODO>
class NodoArbol{
    friend class Arbol<TIPONODO>;
public:
    NodoArbol(const TIPONODO &d) : izquierdoPtr(0), datos(d), derechoPtr(0) { }


    TIPONODO obtenerDatos() const{
        return datos;
    }

private:
    NodoArbol<TIPONODO> *izquierdoPtr;
    TIPONODO datos;
    NodoArbol<TIPONODO> *derechoPtr;
};




