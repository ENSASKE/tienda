#pragma once
#include <string>

class TipoCuello {
    private :
        EnumTypes::cuello codigo;
        std::string descripcion;
    public :
        TipoCuello(){};
        TipoCuello(EnumTypes::cuello codigo, std::string descripcion) {
            this->codigo = codigo;
            this->descripcion = descripcion;
        }
        EnumTypes::cuello getCodigo() {
            return this->codigo;
        }
        std::string getDescripcion() {
            return this->descripcion;
        }
};