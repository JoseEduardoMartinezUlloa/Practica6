#include<fstream>
#include<iostream>

using namespace std;


/*------------------------------------------
----------------NodoArbol-------------------
------------------------------------------*/

template <typename TIPONODO>
class Arbol;

template<typename TIPONODO>
class NodoArbol {
    friend class Arbol<TIPONODO>;
public:
    NodoArbol(const TIPONODO &d) : izquierdoPtr(0), datos(d), derechoPtr(0) { }

    TIPONODO obtenerDatos() const {
        return datos;
    }

private:
    NodoArbol<TIPONODO> *izquierdoPtr;
    TIPONODO datos;
    NodoArbol<TIPONODO> *derechoPtr;
};


/*------------------------------------------
----------------ArbolBinario----------------
------------------------------------------*/

template <typename TIPONODO> class Arbol{

public:
    Arbol();
    void insertarNodo(const TIPONODO &);
    void recorridoPreOrden() const;
    void recorridoInOrden() const;
    void recorridoPostOrden() const;

    void guardadoPreOrden() const;
    void guardadoInOrden() const;
    void guardadoPostOrden() const;

private:
    NodoArbol<TIPONODO> *raizPtr;
    void ayudanteInsertarNodo(NodoArbol<TIPONODO> **, const TIPONODO &);
    void ayudantePreOrden(NodoArbol<TIPONODO> *) const;
    void ayudanteInOrden(NodoArbol<TIPONODO> *) const;
    void ayudantePostOrden(NodoArbol<TIPONODO> *)const;

    void ayudantePreOrdenFile(NodoArbol<TIPONODO> *,std::ofstream&) const;
    void ayudanteInOrdenFile(NodoArbol<TIPONODO> *,std::ofstream&) const;
    void ayudantePostOrdenFile(NodoArbol<TIPONODO> *,std::ofstream&)const;
    
};

template<typename TIPONODO>
Arbol<TIPONODO>::Arbol(){
    raizPtr=0;
}

template<typename TIPONODO>
void Arbol<TIPONODO>::insertarNodo(const TIPONODO &valor){
	ayudanteInsertarNodo(&raizPtr, valor);
}

template<typename TIPONODO>
void Arbol<TIPONODO>::ayudanteInsertarNodo(NodoArbol<TIPONODO> **ptr, const TIPONODO &valor){
	if(*ptr == 0)
	*ptr = new NodoArbol<TIPONODO>(valor);
	else
	{
		if(valor < (*ptr)->datos)
			ayudanteInsertarNodo(&((*ptr)->izquierdoPtr), valor);
		else{
			if(valor > (*ptr)->datos)
				ayudanteInsertarNodo(&((*ptr)->derechoPtr), valor);
			else
				cout<<valor<<" dup"<<endl;
		}
	}	
}

template<typename TIPONODO>
void Arbol<TIPONODO>::recorridoPreOrden() const{
	ayudantePreOrden(raizPtr);
}

template<typename TIPONODO>
void Arbol<TIPONODO>::ayudantePreOrden(NodoArbol<TIPONODO> *ptr) const{
	if(ptr !=0)
	{
		cout<<ptr->datos<<' '<<endl;
		ayudantePreOrden(ptr->izquierdoPtr);
		ayudantePreOrden(ptr->derechoPtr);
	}
}

template<typename TIPONODO>
void Arbol<TIPONODO>::recorridoInOrden() const{
	ayudanteInOrden(raizPtr);
}

template<typename TIPONODO>
void Arbol<TIPONODO>::ayudanteInOrden(NodoArbol<TIPONODO> *ptr) const{
	if(ptr != 0)
	{
		ayudanteInOrden(ptr->izquierdoPtr);
		cout<<ptr->datos<<' '<<endl;
		ayudanteInOrden(ptr->derechoPtr);
	}
}

template<typename TIPONODO>
void Arbol<TIPONODO>::recorridoPostOrden() const{
	ayudantePostOrden(raizPtr);
}

template<typename TIPONODO>
void Arbol<TIPONODO>::ayudantePostOrden(NodoArbol<TIPONODO> *ptr) const{
	if(ptr != 0)
	{
		ayudantePostOrden(ptr->izquierdoPtr);
		ayudantePostOrden(ptr->derechoPtr);
		cout<<ptr->datos<<' '<<endl;
	}
}

template<typename TIPONODO>
void Arbol<TIPONODO>::ayudantePreOrdenFile(NodoArbol<TIPONODO> *ptr, std::ofstream& archivoSalida) const {
    if (ptr != nullptr) {
        archivoSalida << ptr->datos << ' ' << std::endl;
        ayudantePreOrdenFile(ptr->izquierdoPtr, archivoSalida);
        ayudantePreOrdenFile(ptr->derechoPtr, archivoSalida);
    }
}

template<typename TIPONODO>
void Arbol<TIPONODO>::ayudanteInOrdenFile(NodoArbol<TIPONODO> *ptr, std::ofstream& archivoSalida) const {
    if (ptr != nullptr) {
        ayudanteInOrdenFile(ptr->izquierdoPtr, archivoSalida);
        archivoSalida << ptr->datos << ' ' << std::endl;
        ayudanteInOrdenFile(ptr->derechoPtr, archivoSalida);
    }
}

template<typename TIPONODO>
void Arbol<TIPONODO>::ayudantePostOrdenFile(NodoArbol<TIPONODO> *ptr, std::ofstream& archivoSalida) const {
    if (ptr != nullptr) {
        ayudantePostOrdenFile(ptr->izquierdoPtr, archivoSalida);
        ayudantePostOrdenFile(ptr->derechoPtr, archivoSalida);
        archivoSalida << ptr->datos << ' ' << std::endl;
    }
}

template<typename TIPONODO>
void Arbol<TIPONODO>::guardadoPreOrden() const {
    std::ofstream archivoPreOrdenSalida("recorrido_preorden.txt");
    ayudantePreOrdenFile(raizPtr, archivoPreOrdenSalida);
    archivoPreOrdenSalida.close();
}

template<typename TIPONODO>
void Arbol<TIPONODO>::guardadoInOrden() const {
    std::ofstream archivoInOrdenSalida("recorrido_inorden.txt");
    ayudanteInOrdenFile(raizPtr, archivoInOrdenSalida);
    archivoInOrdenSalida.close();
}

template<typename TIPONODO>
void Arbol<TIPONODO>::guardadoPostOrden() const {
    std::ofstream archivoPostOrdenSalida("recorrido_postorden.txt");
    ayudantePostOrdenFile(raizPtr, archivoPostOrdenSalida);
    archivoPostOrdenSalida.close();
}
