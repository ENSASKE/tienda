#pragma once
#include <string>

class TipoPantalon {
    private :
        EnumTypes::pantalon codigo;
        std::string descripcion;
    public :
        TipoPantalon(){};
        TipoPantalon(EnumTypes::pantalon codigo, std::string descripcion) {
            this->codigo = codigo;
            this->descripcion = descripcion;
        }
        EnumTypes::pantalon getCodigo() {
            return this->codigo;
        }
        std::string getDescripcion() {
            return this->descripcion;
        }
};