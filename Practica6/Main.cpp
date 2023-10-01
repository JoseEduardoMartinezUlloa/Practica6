#include<fstream>


#include"libro.cpp"
#include"Pila.cpp"


void compra(PilaGenerica<Libro>&);
void venta(PilaGenerica<Libro>&);
void guardarInformacion(PilaGenerica<Libro>&);


int main(){
    int opc;
    PilaGenerica<Libro>myPila;
    do{
        std::cout<<"\t ~~Libreria luigi~~\n";
        std::cout<<"\t     == Menu == \n\n";
        std::cout<<"1 - Comprar Libro "<<std::endl;
        std::cout<<"2 - Vender Libro "<<std::endl;
        std::cout<<"3 - Salir"<<std::endl;
        std::cout<<"Seleccion una opcion: ";
        std::cin>>opc;
        switch (opc){
        case 1:
            compra(myPila);
            break;
        case 2: 
            venta(myPila);
            break;
        case 3: 
            guardarInformacion(myPila);
            std::cout<<"Saliendo del sistema..."<<std::endl;
            break;
        default:
            std::cout<<"Ingrese una opcion valida..."<<std::endl;
            break;
        }
    } while (opc != 3);
    
}



void compra(PilaGenerica<Libro>& myPila){
    Libro nuevo_libro("","","");
    std::cout<<"Ingrese los datos"<<std::endl;
    std::cin>>nuevo_libro;
    myPila.insertar(nuevo_libro);
}

void venta(PilaGenerica<Libro>& myPila){
    
    Libro libro_eliminar("","","");
    libro_eliminar = myPila.quitar();
    std::cout<<"Libro vendido: "<<std::endl;
    std::cout<<libro_eliminar;
}


void guardarInformacion(PilaGenerica<Libro>& myPila){

    std::ofstream archivoLibroSalida;
    archivoLibroSalida.open("libros.dat",std::ios::out);
    while (!myPila.pilaVacia()){
        Libro l;
        l = myPila.quitar();
        archivoLibroSalida<<l.getNombre()<<" "<<l.getAutor()<<" "<<l.getEditorial()<<std::endl;
    }
    
}