#pragma once
#include "items/Prenda.cpp"
#include "Vendedor.cpp"
#include <string>
#include <list>

class Tienda {
    private :
        std::string nombre;
        std::string direccion;
        Vendedor vendedor;
        std::list<Prenda*> listaPrendas;

    public : 
        Tienda(){};
        Tienda(std::string nombre, std::string direccion, Vendedor vendedor){
            this->nombre = nombre;
            this->direccion = direccion;
            this->vendedor = vendedor;
        }

        std::string getNombre() {
            return this->nombre;
        }

        std::string getDireccion() {
            return this->direccion;
        }

        Vendedor getVendedor() {
            return this->vendedor;
        }

        std::list<Prenda*> getListaPrendas() {
            return this->listaPrendas;
        }

        void addPrenda(Prenda* prenda) {
            this->listaPrendas.push_back(prenda);
        }

        int totalStock() {
            int total = 0;
            for (Prenda* prenda : this->getListaPrendas()) {
                total += prenda->getStock();
            }

            return total;
        }

        int getStockPrenda(Prenda* prenda) {
            int stock = 0;
            Camisa* camisa = dynamic_cast<Camisa*>(prenda);
            Pantalon* pantalon = dynamic_cast<Pantalon*>(prenda);

            if (camisa != NULL) { // Es camisa
                for (Prenda* prendaTienda : this->getListaPrendas()) {
                    if (Camisa* camisaTienda = dynamic_cast<Camisa*>(prendaTienda)){
                        if(camisaTienda->getTipoCamisa().getCodigo() == camisa->getTipoCamisa().getCodigo()
                            && camisaTienda->getTipoCuello().getCodigo() == camisa->getTipoCuello().getCodigo()
                            && camisaTienda->getTipoCalidad().getCodigo() == camisa->getTipoCalidad().getCodigo()
                        ){
                            stock = camisaTienda->getStock();
                        }
                    }
                }
            } else { // Es pantalon
                for (Prenda* prendaTienda : this->getListaPrendas()) {
                    if (Pantalon* pantalonTienda = dynamic_cast<Pantalon*>(prendaTienda)){
                        if(pantalonTienda->getTipoPantalon().getCodigo() == pantalon->getTipoPantalon().getCodigo()
                            && pantalonTienda->getTipoCalidad().getCodigo() == pantalon->getTipoCalidad().getCodigo()
                        ){
                            stock = pantalonTienda->getStock();
                        }
                    }
                }
            }

            return stock;
        }

        void actualizarStock(Prenda* prenda, int cantidad) {
            Camisa* camisa = dynamic_cast<Camisa*>(prenda);
            Pantalon* pantalon = dynamic_cast<Pantalon*>(prenda);

            if (camisa != NULL) { // Es camisa
                for (Prenda* prendaTienda : this->getListaPrendas()) {
                    if (Camisa* camisaTienda = dynamic_cast<Camisa*>(prendaTienda)){
                        if(camisaTienda->getTipoCamisa().getCodigo() == camisa->getTipoCamisa().getCodigo()
                            && camisaTienda->getTipoCuello().getCodigo() == camisa->getTipoCuello().getCodigo()
                            && camisaTienda->getTipoCalidad().getCodigo() == camisa->getTipoCalidad().getCodigo()
                        ){
                            camisaTienda->setStock(camisaTienda->getStock() - cantidad);
                        }
                    }
                }
            } else { // Es pantalon
                for (Prenda* prendaTienda : this->getListaPrendas()) {
                    if (Pantalon* pantalonTienda = dynamic_cast<Pantalon*>(prendaTienda)){
                        if(pantalonTienda->getTipoPantalon().getCodigo() == pantalon->getTipoPantalon().getCodigo()
                            && pantalonTienda->getTipoCalidad().getCodigo() == pantalon->getTipoCalidad().getCodigo()
                        ){
                            pantalonTienda->setStock(pantalonTienda->getStock() - cantidad);
                        }
                    }
                }
            }
        }
};