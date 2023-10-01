#include"Libro.h"
#include<string>


void Libro::establecerNombre(std::string nom){nombre = nom;}

void Libro::establecerAutor(std::string aut){autor = aut;}

void Libro::establecerEditorial(std::string edit){editorial = edit;}

std::string Libro::getNombre(){return nombre;}

std::string Libro::getAutor(){return autor;}

std::string Libro::getEditorial(){return editorial;}

Libro::Libro(){}

Libro::Libro(std::string nom,std::string aut,std::string edit){
    nombre = nom;
    autor = aut;
    editorial = edit;
}


std::istream& operator>>(std::istream& is, Libro& lib){
    is.ignore();
    std::cout<<" Nombre: ";
    getline(is,lib.nombre);
    std::cout<<" Autor: ";
    getline(is,lib.autor);
    std::cout<<" Editorial: ";
    getline(is,lib.editorial);
    return is;

}