#include "../modelos/items/Prenda.cpp"
#include "../modelos/items/Camisa.cpp"
#include "../modelos/items/Pantalon.cpp"
#include "../modelos/items/TipoCamisa.cpp"
#include "../modelos/items/TipoCuello.cpp"
#include "../modelos/items/TipoCalidad.cpp"
#include "../modelos/items/TipoPantalon.cpp"
#include "../modelos/Tienda.cpp"
#include "../modelos/Vendedor.cpp"
#include "../modelos/Cotizacion.cpp"
#include "../vistas/menuPrincipal.cpp"
#include "Inventario.cpp"

#include <iostream>
#include <ctime>
#include <sstream>
#include <cmath>

class Principal {
    private :
        Tienda tienda;
        Vendedor vendedor;
        MenuPrincipal menuPrincipal;
        const std::string salirMenu = "x";        

        void iniciarCotizador();
        void iniciarCalidadPrecioCantidad();
        void crearCotizacion(Prenda* prenda);
        double actualizarPrecio(Prenda* prenda, double precio);
        bool validarCantidad(const std::string& texto);
        bool validarPrecio(const std::string& texto);
        bool validarExistencia(int cantidad, int stock);
        void limpiar();
        double round2(double x);
        Prenda* crearPrenda();
    public : 
        void iniciarTienda();        
};

void Principal::iniciarTienda() {
    // Datos Vendedor
    this->vendedor = Vendedor("V-19288431", "Grégor", "González");
    // Datos de la tienda
    this->tienda = Tienda("Tienda de ropa C.A.", "Ave Principal Los Ilustres, Calle 107", this->vendedor);
    // Datos del items del inventario
    Inventario().cargarInventario(this->tienda);
    // Datos de la vista
    menuPrincipal = MenuPrincipal(this->tienda, this->vendedor);

    std::string seleccionMenu;
    while (seleccionMenu != salirMenu) {
        seleccionMenu = this->menuPrincipal.getPantallaInicial();

        if (seleccionMenu == "1") {
            std::string seleccionHistorial;
            while (seleccionHistorial != salirMenu) {
                seleccionHistorial = this->menuPrincipal.getPantallaHistorial();
            }
        } else if (seleccionMenu == "2") {
            this->iniciarCotizador();
        } else if (seleccionMenu == "3") {
            std::string seleccionInventario;
            while (seleccionInventario != salirMenu) {
                seleccionInventario = this->menuPrincipal.getPantallaInventario(this->tienda);
            }            
        }
    }

    this->menuPrincipal.getPantallaSalir();
    this->limpiar();
}

void Principal::iniciarCotizador() {
    std::string seleccionCotizar;
    while (seleccionCotizar != salirMenu) {
        seleccionCotizar = this->menuPrincipal.getPantallaCotizar();

        // Camisa
        if (seleccionCotizar == "1") {
            std::string seleccionManga;
            while (seleccionManga != salirMenu) {
                seleccionManga = this->menuPrincipal.getPantallaCamisa();

                if (seleccionManga == "1" || seleccionManga == "2") {
                    break;
                }
            }

            // Si seleccionó "salir", no continuar al siguiente menú
            if (seleccionManga == salirMenu) {
                return;
            }

            std::string seleccionCuello;
            while (seleccionCuello != salirMenu) {
                seleccionCuello = this->menuPrincipal.getPantallaCuello();

                if (seleccionCuello == "1" || seleccionCuello == "2") {
                    break;
                }
            }

            // Si seleccionó "salir", no continuar al siguiente menú
            if (seleccionCuello == salirMenu) {
                return;
            }

            this->iniciarCalidadPrecioCantidad();
            return;
        // Pantalon
        } else if (seleccionCotizar == "2") {
            std::string seleccionPantalon;
            while (seleccionPantalon != salirMenu) {
                seleccionPantalon = this->menuPrincipal.getPantallaPantalon();

                if (seleccionPantalon == "1" || seleccionPantalon == "2") {
                    break;
                }
            }

            // Si seleccionó "salir", no continuar al siguiente menú
            if (seleccionPantalon == salirMenu) {
                return;
            }

            this->iniciarCalidadPrecioCantidad();
            return;
        }
    }
}

void Principal::iniciarCalidadPrecioCantidad() {
    std::string seleccionCalidad;
    while (seleccionCalidad != salirMenu) {
        seleccionCalidad = this->menuPrincipal.getPantallaCalidad();

        if (seleccionCalidad == "1" || seleccionCalidad == "2") {
            break;
        }
    }

    // Si seleccionó "salir", no continuar al siguiente menú
    if (seleccionCalidad == salirMenu) {
        return;
    }

    std::string ingresarPrecio;
    while (ingresarPrecio != salirMenu) {
        ingresarPrecio = this->menuPrincipal.getPantallaPrecio();

        if(this->validarPrecio(ingresarPrecio)){
            break;
        }
    }

    // Si seleccionó "salir", no continuar al siguiente menú
    if (ingresarPrecio == salirMenu) {
        return;
    }

    Prenda* prenda = this->crearPrenda();
    int stock = this->tienda.getStockPrenda(prenda);

    std::string ingresarCantidad;
    while (ingresarCantidad != salirMenu) {
        ingresarCantidad = this->menuPrincipal.getPantallaCantidad(stock);

        if (this->validarCantidad(ingresarCantidad) 
            && this->validarExistencia(std::stoi(ingresarCantidad), stock)) {
            break;
        }
    }

    if (ingresarCantidad == salirMenu) {
        return;
    }

    // Crear cotización
    this->crearCotizacion(prenda);
};

Prenda* Principal::crearPrenda(){
    Prenda* prenda;
    TipoCamisa tipoCamisa;
    TipoCuello tipoCuello;    
    TipoPantalon tipoPantalon;
    TipoCalidad tipoCalidad;

    if (this->menuPrincipal.selMangaCorta == "1") {
        tipoCamisa = TipoCamisa(EnumTypes::camisa::MANGA_CORTA, EnumTypes::getDescCamisa(EnumTypes::camisa::MANGA_CORTA));
    } else {
        tipoCamisa = TipoCamisa(EnumTypes::camisa::MANGA_LARGA, EnumTypes::getDescCamisa(EnumTypes::camisa::MANGA_LARGA));
    }

    if (this->menuPrincipal.selCuelloMao == "1") {
        tipoCuello = TipoCuello(EnumTypes::cuello::CUELLO_MAO, EnumTypes::getDescCuello(EnumTypes::cuello::CUELLO_MAO));
    } else {
        tipoCuello = TipoCuello(EnumTypes::cuello::CUELLO_COMUN, EnumTypes::getDescCuello(EnumTypes::cuello::CUELLO_COMUN));
    }

    if (this->menuPrincipal.selChupin == "1") {
        tipoPantalon = TipoPantalon(EnumTypes::pantalon::CHUPINES, EnumTypes::getDescPantalon(EnumTypes::pantalon::CHUPINES));
    } else {
        tipoPantalon = TipoPantalon(EnumTypes::pantalon::COMUNES, EnumTypes::getDescPantalon(EnumTypes::pantalon::COMUNES));
    }

    if (this->menuPrincipal.selCalidad == "1") {
        tipoCalidad = TipoCalidad(EnumTypes::calidad::STANDARD, EnumTypes::getDescCalidad(EnumTypes::calidad::STANDARD));
    } else {
        tipoCalidad = TipoCalidad(EnumTypes::calidad::PREMIUM, EnumTypes::getDescCalidad(EnumTypes::calidad::PREMIUM));
    }

    if (this->menuPrincipal.selCamisaPantalon == "1") {
        prenda = new Camisa(tipoCamisa, tipoCuello, tipoCalidad);
    } else {
        prenda = new Pantalon(tipoPantalon, tipoCalidad);
    }

    return prenda;
}

void Principal::crearCotizacion(Prenda* prenda) {
    int cantidad;
    double precio;

    cantidad = std::stoi(this->menuPrincipal.selCantidad);
    precio = std::stod(this->menuPrincipal.selPrecio);
    precio = this->actualizarPrecio(prenda, precio);
    this->tienda.actualizarStock(prenda, cantidad);

    Cotizacion* cotizacion = new Cotizacion(
        (vendedor.getListaCotizaciones().size() + 1),
        vendedor.getCodigo(),
        prenda,
        cantidad,
        precio
    );

    vendedor.addCotizacion(cotizacion);

    std::string seleccionMostrarCotizacion;
    while (seleccionMostrarCotizacion != salirMenu) {
        seleccionMostrarCotizacion = this->menuPrincipal.getPantallaCotizacion(vendedor);
    }

}

double Principal::actualizarPrecio(Prenda* prenda, double precio) {
    Camisa* camisa = dynamic_cast<Camisa*>(prenda);
    Pantalon* pantalon = dynamic_cast<Pantalon*>(prenda);

    if (camisa != NULL) { // Es camisa
        // Si es manga corta 10% descuento
        if (camisa->getTipoCamisa().getCodigo() == EnumTypes::camisa::MANGA_CORTA) {
            precio = round2(precio - (round2(precio*10)/100));
        }
        // Si es cuello mao 3% aumento
        if (camisa->getTipoCuello().getCodigo() == EnumTypes::cuello::CUELLO_MAO) {
            precio = round2(precio * 1.03);
        }
        // Si la calidad es Premium 30% aumento
        if (camisa->getTipoCalidad().getCodigo() == EnumTypes::calidad::PREMIUM) {
            precio = round2(precio * 1.30);
        }
    } else { // Es pantalon
        // Si es chupin 12% descuento
        if (pantalon->getTipoPantalon().getCodigo() == EnumTypes::pantalon::CHUPINES) {
            precio = round2(precio - (round2(precio*12)/100));
        }
        // Si la calidad es Premium 30% aumento
        if (pantalon->getTipoCalidad().getCodigo() == EnumTypes::calidad::PREMIUM) {
            precio = round2(precio * 1.30);
        }
    }

    return precio;
}

bool Principal::validarCantidad(const std::string& texto){
    bool valido = true;

    if (texto.empty() || texto == "0"){
        valido = false;
    }

    for (char const &ch : texto) {
        if (std::isdigit(ch) == 0) {
            valido = false;
        }
    }

    if(valido == false){
        std::cout << "\n------------------------------------\n";
        std::cout << "ERROR: Debe ingresar un número entero";
    }

    return valido;    
 }

bool Principal::validarExistencia(int cantidad, int stock){
    bool valido = true;
    if (cantidad > stock){
        valido = false;
        std::cout << "\n------------------------------------\n";
        std::cout << "ERROR: No tenemos esa cantidad disponible en stock :(";
    }

    return valido;
} 

bool Principal::validarPrecio(const std::string& texto){
    double ld;
    bool valido = ((std::istringstream(texto) >> ld >> std::ws).eof());
    
    if (valido == false) {
        std::cout << "\n------------------------------------\n";
        std::cout << "ERROR: Debe ingresar un precio con formato númerico";
    }

    return valido;
}

void Principal::limpiar() {
    for (auto &prenda : this->tienda.getListaPrendas()) {
        delete prenda;
    }
    this->tienda.getListaPrendas().clear();

    for (auto &cotizacion : this->vendedor.getListaCotizaciones()) {
        delete cotizacion;
    }
    this->vendedor.getListaCotizaciones().clear();
}

double Principal::round2(double x) { 
    return std::round(x * 100.0) / 100.0; 
};
