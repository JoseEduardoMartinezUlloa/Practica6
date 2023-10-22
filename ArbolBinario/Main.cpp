#include<iostream>
#include<iomanip>
#include<ctime>
#include"ArbolBinario.h"

void Opcion1(Arbol<int>&);


int main(){
    Arbol<int> intArbol;
    int opc;
    do{
        
        std::cout<<"\t ---- Menu ---- \n\n";
        std::cout<<"[1] - Insertar valores"<<std::endl;
        std::cout<<"[2] - Recorrido preOrden"<<std::endl;
        std::cout<<"[3] - Recorrido inOrden"<<std::endl;
        std::cout<<"[4] - Recorrido postOrden"<<std::endl;
        std::cout<<"[5] - Salir"<<std::endl;
        std::cin>>opc;

        switch (opc){
        case 1:
            Opcion1(intArbol);
            break;
        case 2: 
            intArbol.recorridoPreOrden();
            intArbol.guardadoPreOrden();
            break;
        case 3: 
            intArbol.recorridoInOrden();
            intArbol.guardadoInOrden();
            break;
        case 4: 
            intArbol.recorridoPostOrden();
            intArbol.guardadoPostOrden();
            break;

        case 5: 
            break;

        default:
            std::cout<<"Opcion invalida..."<<std::endl;
            break;
        }

    } while (opc != 5);
    
}



void Opcion1(Arbol<int>& myArbol){
    int valor;
    srand(static_cast<unsigned>(time(nullptr)));  

    std::cout << "Generando 10 números enteros aleatorios en el rango de 1 a 100:\n";
    
    for (int i = 0; i < 10; i++) {
        valor = rand() % 100 + 1;  
        std::cout << valor << ' ';
        myArbol.insertarNodo(valor);
    }
}