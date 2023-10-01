

template<class T>
class node{

    private: 
        T data;
        node<T>* sig;
    public:
        node();
        node(const T&);

        void setData(const T&);
        void setSiguiente(node<T>*);

        T getData();
        node<T>* getSiguiente();

};

template<class T >
node<T>::node(){sig == nullptr;}


template<class T>
node<T>::node(const T& dat){
    data  = dat;
    sig  = nullptr;
}


template<class T>
void node<T>::setData(const T& dat){
    data = dat;
}

template<class T>
void node<T>::setSiguiente(node<T>* pos){
    sig = pos;
}

template<class T>
T node<T>::getData(){
    return data;
}

template<class T>
node<T>* node<T>::getSiguiente(){
    return sig;
}


template<class T>
class PilaGenerica{
    private: 
        node<T>* cima;
    public: 
        PilaGenerica(){ cima = nullptr;}
        void insertar(T);
        T quitar();
        T cimaPila()const;
        bool pilaVacia();
        void LimpiarPila();
        ~PilaGenerica(){ LimpiarPila(); }
};



template<class T>
bool PilaGenerica<T>::pilaVacia(){ return cima == nullptr;}

template<class T>
void PilaGenerica<T>::insertar(T elem){
    node<T>* nuevo(new node<T>(elem));
    nuevo-> setSiguiente(cima);
    cima = nuevo;
}

template<class T>
T PilaGenerica<T>::quitar(){
    if(pilaVacia()){
        std::cout<<"Pila vacia, no se puede extraer... "<<std::endl;   
    }else{
        T aux = cima->getData();
        cima = cima->getSiguiente();
        return aux;
    }
}

template<class T>
T PilaGenerica<T>::cimaPila()const{
    if(pilaVacia()){
        std::cout<<"Pila vacia, nada en la cima..."<<std::endl;
    }else{
        return cima->getData();
    }
}


template<class T>
void PilaGenerica<T>::LimpiarPila(){
    node<T>* n;
    while (!pilaVacia()){
        n = cima;
        cima = cima->getSiguiente();
        delete n;
    }
}

