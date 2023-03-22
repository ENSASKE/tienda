#pragma once
#include <string>

class TipoCalidad {
    private :
        EnumTypes::calidad codigo;
        std::string descripcion;
    public :
        TipoCalidad(){};
        TipoCalidad(EnumTypes::calidad codigo, std::string descripcion) {
            this->codigo = codigo;
            this->descripcion = descripcion;
        }
        EnumTypes::calidad getCodigo() {
            return this->codigo;
        }
        std::string getDescripcion() {
            return this->descripcion;
        }
};