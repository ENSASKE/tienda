#pragma once
#include "EnumTypes.cpp"
#include <string>

class TipoCamisa {
    private :
        EnumTypes::camisa codigo;
        std::string descripcion;
    public :
        TipoCamisa(){};
        TipoCamisa(EnumTypes::camisa codigo, std::string descripcion) {
            this->codigo = codigo;
            this->descripcion = descripcion;
        }
        EnumTypes::camisa getCodigo() {
            return this->codigo;
        }
        std::string getDescripcion() {
            return this->descripcion;
        }
};