#pragma once
#include "Prenda.cpp"
#include "TipoPantalon.cpp"
#include "TipoCalidad.cpp"

class Pantalon : public Prenda {
    private :
        TipoPantalon tipoPantalon;
        TipoCalidad tipoCalidad;
    public :
        Pantalon(TipoPantalon tipoPantalon, TipoCalidad tipoCalidad, int stock) {
            this->tipoPantalon = tipoPantalon;
            this->tipoCalidad = tipoCalidad;
            this->setStock(stock);
        }
        Pantalon(TipoPantalon tipoPantalon, TipoCalidad tipoCalidad) {
            this->tipoPantalon = tipoPantalon;
            this->tipoCalidad = tipoCalidad;
        }
        TipoPantalon getTipoPantalon() {
            return this->tipoPantalon;
        }
        TipoCalidad getTipoCalidad() {
            return this->tipoCalidad;
        }
};