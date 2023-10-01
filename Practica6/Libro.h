#include<iostream>
#include<string>


class Libro{

private:
    std::string nombre;
    std::string autor;
    std::string editorial;

public:
    void establecerNombre(std::string);
    void establecerAutor(std::string);
    void establecerEditorial(std::string);

    std::string getNombre();
    std::string getAutor();
    std::string getEditorial();
    Libro();
    Libro(std::string,std::string ,std::string  );

    friend std::istream& operator>>(std::istream& is , Libro& obj);


    friend std::ostream& operator<<(std::ostream& os, Libro& obj){
        os<< "Nombre: "<<obj.nombre<<std::endl;
        os<<" Autor: "<<obj.autor<<std::endl;
        os<<"Editorial: "<<obj.editorial<<std::endl;
        return os;
    }


};
