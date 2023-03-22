#include "../modelos/Tienda.cpp"
#include "../modelos/Vendedor.cpp"
#include "../modelos/Cotizacion.cpp"
#include <iostream>
#include <string>
#include <list>

class MenuPrincipal {
    private :
        Tienda tienda;
        Vendedor vendedor;
    public :
        std::string selCamisaPantalon;
        std::string selMangaCorta;
        std::string selCuelloMao;
        std::string selChupin;
        std::string selCalidad;
        std::string selPrecio;
        std::string selCantidad;

        MenuPrincipal(){
        };
        MenuPrincipal(Tienda tienda, Vendedor vendedor) {
            this->tienda = tienda;
            this->vendedor = vendedor;
        }

        void getEncabezado() {
            std::cout << "------------------------------------\n";
            std::cout << "<========= Tienda Online ==========>\n";
            std::cout << this->tienda.getNombre() + " | " + this->tienda.getDireccion() + "\n";
            std::cout << this->vendedor.getNombre() + " " + this->vendedor.getApellido() + 
            " | " + this->vendedor.getCodigo() + "\n";
            std::cout << "------------------------------------\n";
            std::cout << "------------------------------------\n";
        }

        std::string getPantallaInicial() {
            this->getEncabezado();
            std::cout << "1- Historial de Cotizaciones\n";
            std::cout << "2- Realizar Cotización\n";
            std::cout << "3- Ver Inventario de la Tienda\n";
            std::cout << "x- Salir\n";

            std::cout << "Seleccione opción:";
                
            std::string seleccion;
            std::cin >> seleccion;
            return seleccion;
        }

        std::string getPantallaHistorial() {
            std::cout << "\n------------------------------------\n";
            std::cout << "Lista de cotizaciones:\n";
            std::cout << "x- Salir\n";

            std::cout << "Seleccione opción:";
            std::string seleccion;
            std::cin >> seleccion;
            return seleccion;
        }

        std::string getPantallaCotizar() {
            std::cout << "\n------------------------------------\n";
            std::cout << "Paso 1 indique prenda a cotizar:\n";
            std::cout << "1- Camisa\n";
            std::cout << "2- Pantalón\n";
            std::cout << "x- Salir\n";

            std::cout << "Seleccione opción:";
            std::cin >> selCamisaPantalon;
            return selCamisaPantalon;
        }

        std::string getPantallaCamisa() {
            std::cout << "\n------------------------------------\n";
            std::cout << "Paso 2 A: ¿La camisa es Manga Corta?:\n";
            std::cout << "1- Sí\n";
            std::cout << "2- No\n";
            std::cout << "x- Salir\n";

            std::cout << "Seleccione opción:";
            std::cin >> selMangaCorta;
            return selMangaCorta;
        }

        std::string getPantallaCuello() {
            std::cout << "\n------------------------------------\n";
            std::cout << "Paso 2 B: ¿La camisa es Cuello Mao?:\n";
            std::cout << "1- Sí\n";
            std::cout << "2- No\n";
            std::cout << "x- Salir\n";

            std::cout << "Seleccione opción:";
            std::cin >> selCuelloMao;
            return selCuelloMao;
        }

        std::string getPantallaPantalon() {
            std::cout << "\n------------------------------------\n";
            std::cout << "Paso 2 ¿El pantalón es Chupín?:\n";
            std::cout << "1- Sí\n";
            std::cout << "2- No\n";
            std::cout << "x- Salir\n";

            std::cout << "Seleccione opción:";
            std::cin >> selChupin;
            return selChupin;
        }

        std::string getPantallaCalidad() {
            std::cout << "\n------------------------------------\n";
            std::cout << "Paso 3 Seleccione la calidad de la prenda:\n";
            std::cout << "1- Standard\n";
            std::cout << "2- Premium\n";
            std::cout << "x- Salir\n";

            std::cout << "Seleccione opción:";
            std::cin >> selCalidad;
            return selCalidad;
        }

        std::string getPantallaPrecio() {
            std::cout << "\n------------------------------------\n";
            std::cout << "Paso 4 Indique precio unitario a cotizar:\n";
            std::cout << "x- Salir\n";

            std::cout << "Ingrese precio:";
            std::cin >> selPrecio;
            return selPrecio;
        }

        std::string getPantallaCantidad(int stock) {
            std::cout << "\n------------------------------------\n";
            std::cout << "Paso 5 Indique cantidad a cotizar:\n";
            std::cout << "INFORMACIÓN:\n";
            std::cout << "HAY "+ std::to_string(stock) +" UNIDADES DE LA PRENDA SELECCIONADA \n";
            std::cout << "x- Salir\n";

            std::cout << "Ingrese cantidad:";
            std::cin >> selCantidad;
            return selCantidad;
        }

        std::string getPantallaCotizacion(Vendedor vendedor) {
            this->getEncabezado();
            Cotizacion* cotizacion = vendedor.getListaCotizaciones().back();
            
            Prenda* prenda = cotizacion->getPrenda();
            std::string prendaCotizada;

            // Si la prenda es una camisa
            Camisa* camisa = dynamic_cast<Camisa*>(prenda);
            if (camisa != NULL) {
                prendaCotizada = "Camisa: " + camisa->getTipoCamisa().getDescripcion() + " "
                + camisa->getTipoCuello().getDescripcion() + " "
                + camisa->getTipoCalidad().getDescripcion();
            }

            // Si la prenda es un pantalon
            Pantalon* pantalon = dynamic_cast<Pantalon*>(prenda);
            if (pantalon != NULL) {
                prendaCotizada = "Pantalón: " + pantalon->getTipoPantalon().getDescripcion() + " "
                + pantalon->getTipoCalidad().getDescripcion();
            }

            std::cout << "\n------------------------------------\n";
            std::cout << "Cotización creada satisfactoriamente:\n";
            std::cout << "Nro Cotización: "+ std::to_string(cotizacion->getNumero()) +"\n";
            std::cout << "Fecha y Hora Cotización: "+ cotizacion->getFechaHora() +"\n";
            std::cout << "Código del Vendedor: "+ cotizacion->getCodigoVendedor() +" \n";
            std::cout << "Prenda Cotizada: "+ prendaCotizada +" \n";
            printf("Precio Unitario: %.2f\n", cotizacion->getPrecio());
            std::cout << "Cantidad Cotizada: "+ std::to_string(cotizacion->getCantidad()) +"\n";
            printf("Total: %.2f\n", cotizacion->getTotal());
            std::cout << "x- Salir\n";

            std::cout << "Seleccione opción:";
            std::string seleccion;
            std::cin >> seleccion;
            return seleccion;
        }

        std::string getPantallaInventario(Tienda tienda) {
            std::cout << "\n------------------------------------\n";
            std::cout << "Items y cantidades en Inventario:\n";

            for (Prenda* prenda : tienda.getListaPrendas()) {
                // Si la prenda es una camisa
                Camisa *camisa = dynamic_cast<Camisa*>(prenda);
                if (camisa != NULL) {
                    std::cout <<  "\nCamisa: " + camisa->getTipoCamisa().getDescripcion();
                    std::cout <<  " - " + camisa->getTipoCuello().getDescripcion();
                    std::cout <<  " - " + camisa->getTipoCalidad().getDescripcion();
                    std::cout <<  " - Stock: " + std::to_string(camisa->getStock());
                }

                // Si la prenda es un pantalon
                Pantalon *pantalon = dynamic_cast<Pantalon*>(prenda);
                if (pantalon != NULL) {
                    std::cout <<  "\nPantalón: " + pantalon->getTipoPantalon().getDescripcion();
                    std::cout <<  " - " + pantalon->getTipoCalidad().getDescripcion();
                    std::cout <<  " - Stock: " + std::to_string(pantalon->getStock());
                }
            }

            std::cout <<  "\nTotal Lista Items: " + std::to_string(tienda.getListaPrendas().size());
            std::cout <<  "\nTotal en STOCK : " + std::to_string(tienda.totalStock());

            std::cout << "\nx- Salir";
            std::cout << "\nSeleccione opción:";
            std::string seleccion;
            std::cin >> seleccion;
            return seleccion;
        }

        void getPantallaSalir() {
            std::cout << "\n<==Gracias por su visita, esperemos que vuelva pronto==>\n";
        }
};