#pragma once
#include "items/Prenda.cpp"
#include <string>
#include <ctime>
#include <cmath>

class Cotizacion {
    private :
        int numero;
        std::string fechaHora;
        std::string codigoVendedor;
        Prenda* prenda;
        int cantidad;
        double precio;
        double total;

        void setFechaHora() {
            time_t curtime;
            time(&curtime);
            char buffer[20];
            strftime(buffer, sizeof(buffer), "%d-%m-%Y %X", localtime(&curtime));

            this->fechaHora = buffer;
        }
    public :
        Cotizacion(){};
        Cotizacion(int numero, std::string codigoVendedor, Prenda* prenda, int cantidad, double precio) {
            this->numero = numero;
            this->codigoVendedor = codigoVendedor;
            this->prenda = prenda;
            this->cantidad = cantidad;
            this->precio = precio;

            this->total = (cantidad * precio);
            this->total = std::round(this->total * 100.0) / 100.0;

            this->setFechaHora();
        }

        int getNumero() {
            return this->numero;
        }

        std::string getFechaHora() {
            return this->fechaHora;
        }

        std::string getCodigoVendedor() {
            return this->codigoVendedor;
        }

        Prenda* getPrenda() {
            return this->prenda;
        }

        int getCantidad() {
            return this->cantidad;
        }

        double getPrecio() {
            return this->precio;
        }

        double getTotal() {
            return this->total;
        }

        
};