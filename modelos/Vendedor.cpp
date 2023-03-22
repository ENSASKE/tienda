#pragma once
#include "Cotizacion.cpp"
#include <string>
#include <list>

class Vendedor {
    private :
        std::string codigo;
        std::string nombre;
        std::string apellido;
        std::list<Cotizacion*> listaCotizaciones;
    public : 
        Vendedor(){};
        Vendedor(std::string codigo, std::string nombre, std::string apellido) {
            this->codigo = codigo;
            this->nombre = nombre;
            this->apellido = apellido;
        }

        std::string getCodigo() {
            return this->codigo;
        }

        std::string getNombre() {
            return this->nombre;
        }

        std::string getApellido() {
            return this->apellido;
        }

        std::list<Cotizacion*> getListaCotizaciones() {
            return listaCotizaciones;
        }

        void addCotizacion(Cotizacion* cotizacion) {
            listaCotizaciones.push_back(cotizacion);
        }
};