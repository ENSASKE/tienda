#pragma once
#include "Prenda.cpp"
#include "TipoCamisa.cpp"
#include "TipoCuello.cpp"
#include "TipoCalidad.cpp"

class Camisa : public Prenda {
    private :
        TipoCamisa tipoCamisa;
        TipoCuello tipoCuello;
        TipoCalidad tipoCalidad;
    public :
        Camisa(TipoCamisa tipoCamisa, TipoCuello tipoCuello, TipoCalidad tipoCalidad, int stock) {
            this->tipoCamisa = tipoCamisa;
            this->tipoCuello = tipoCuello;
            this->tipoCalidad = tipoCalidad;
            this->setStock(stock);
        }
        Camisa(TipoCamisa tipoCamisa, TipoCuello tipoCuello, TipoCalidad tipoCalidad) {
            this->tipoCamisa = tipoCamisa;
            this->tipoCuello = tipoCuello;
            this->tipoCalidad = tipoCalidad;
        }
        TipoCamisa getTipoCamisa() {
            return this->tipoCamisa;
        }
        TipoCuello getTipoCuello() {
            return this->tipoCuello;
        }
        TipoCalidad getTipoCalidad() {
            return this->tipoCalidad;
        }
};