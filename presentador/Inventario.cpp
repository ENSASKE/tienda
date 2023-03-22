#include "../modelos/items/Prenda.cpp"
#include "../modelos/items/Camisa.cpp"
#include "../modelos/items/Pantalon.cpp"
#include "../modelos/items/TipoCamisa.cpp"
#include "../modelos/items/TipoCuello.cpp"
#include "../modelos/items/TipoCalidad.cpp"
#include "../modelos/items/TipoPantalon.cpp"
#include "../modelos/Tienda.cpp"

class Inventario{
    public :
        void cargarInventario(Tienda& tienda);
};

/**
 * Se encarga de inicializar la tienda con todo el inventario
*/
void Inventario::cargarInventario(Tienda& tienda) {
    // CAMISAS
    // 1) 500 Manga corta + 200 Cuello Mao + 100 calidad Standard
    Prenda* prenda = new Camisa(
        TipoCamisa(EnumTypes::camisa::MANGA_CORTA, EnumTypes::getDescCamisa(EnumTypes::camisa::MANGA_CORTA)),
        TipoCuello(EnumTypes::cuello::CUELLO_MAO, EnumTypes::getDescCuello(EnumTypes::cuello::CUELLO_MAO)),
        TipoCalidad(EnumTypes::calidad::STANDARD, EnumTypes::getDescCalidad(EnumTypes::calidad::STANDARD)),
        100
    );
    tienda.addPrenda(prenda);
    // 2) 500 Manga corta + 200 Cuello Mao + 100 calidad Premium
    prenda = new Camisa(
        TipoCamisa(EnumTypes::camisa::MANGA_CORTA, EnumTypes::getDescCamisa(EnumTypes::camisa::MANGA_CORTA)),
        TipoCuello(EnumTypes::cuello::CUELLO_MAO, EnumTypes::getDescCuello(EnumTypes::cuello::CUELLO_MAO)),
        TipoCalidad(EnumTypes::calidad::PREMIUM, EnumTypes::getDescCalidad(EnumTypes::calidad::PREMIUM)),
        100
    );
    tienda.addPrenda(prenda);
    // 3) 500 Manga corta + 300 Cuello Común + 150 calidad Standard
    prenda = new Camisa(
        TipoCamisa(EnumTypes::camisa::MANGA_CORTA, EnumTypes::getDescCamisa(EnumTypes::camisa::MANGA_CORTA)),
        TipoCuello(EnumTypes::cuello::CUELLO_COMUN, EnumTypes::getDescCuello(EnumTypes::cuello::CUELLO_COMUN)),
        TipoCalidad(EnumTypes::calidad::STANDARD, EnumTypes::getDescCalidad(EnumTypes::calidad::STANDARD)),
        150
    );
    tienda.addPrenda(prenda);
    // 4) 500 Manga corta + 300 Cuello Común + 150 calidad Premium
    prenda = new Camisa(
        TipoCamisa(EnumTypes::camisa::MANGA_CORTA, EnumTypes::getDescCamisa(EnumTypes::camisa::MANGA_CORTA)),
        TipoCuello(EnumTypes::cuello::CUELLO_COMUN, EnumTypes::getDescCuello(EnumTypes::cuello::CUELLO_COMUN)),
        TipoCalidad(EnumTypes::calidad::PREMIUM, EnumTypes::getDescCalidad(EnumTypes::calidad::PREMIUM)),
        150
    );
    tienda.addPrenda(prenda);
    // 5) 500 Manga Larga + 150 Cuello Mao + 75 Calidad Standard
    prenda = new Camisa(
        TipoCamisa(EnumTypes::camisa::MANGA_LARGA, EnumTypes::getDescCamisa(EnumTypes::camisa::MANGA_LARGA)),
        TipoCuello(EnumTypes::cuello::CUELLO_MAO, EnumTypes::getDescCuello(EnumTypes::cuello::CUELLO_MAO)),
        TipoCalidad(EnumTypes::calidad::STANDARD, EnumTypes::getDescCalidad(EnumTypes::calidad::STANDARD)),
        75
    );
    tienda.addPrenda(prenda);
    // 6) 500 Manga Larga + 150 Cuello Mao + 75 Calidad Premium
    prenda = new Camisa(
        TipoCamisa(EnumTypes::camisa::MANGA_LARGA, EnumTypes::getDescCamisa(EnumTypes::camisa::MANGA_LARGA)),
        TipoCuello(EnumTypes::cuello::CUELLO_MAO, EnumTypes::getDescCuello(EnumTypes::cuello::CUELLO_MAO)),
        TipoCalidad(EnumTypes::calidad::PREMIUM, EnumTypes::getDescCalidad(EnumTypes::calidad::PREMIUM)),
        75
    );
    tienda.addPrenda(prenda);
    // 7) 500 Manga Larga + 350 Cuello Común + 175 Calidad Standard
    prenda = new Camisa(
        TipoCamisa(EnumTypes::camisa::MANGA_LARGA, EnumTypes::getDescCamisa(EnumTypes::camisa::MANGA_LARGA)),
        TipoCuello(EnumTypes::cuello::CUELLO_COMUN, EnumTypes::getDescCuello(EnumTypes::cuello::CUELLO_COMUN)),
        TipoCalidad(EnumTypes::calidad::STANDARD, EnumTypes::getDescCalidad(EnumTypes::calidad::STANDARD)),
        175
    );
    tienda.addPrenda(prenda);
    // 8) 500 Manga Larga + 350 Cuello Común + 175 Calidad Premium
    prenda = new Camisa(
        TipoCamisa(EnumTypes::camisa::MANGA_LARGA, EnumTypes::getDescCamisa(EnumTypes::camisa::MANGA_LARGA)),
        TipoCuello(EnumTypes::cuello::CUELLO_COMUN, EnumTypes::getDescCuello(EnumTypes::cuello::CUELLO_COMUN)),
        TipoCalidad(EnumTypes::calidad::PREMIUM, EnumTypes::getDescCalidad(EnumTypes::calidad::PREMIUM)),
        175
    );
    tienda.addPrenda(prenda);
    // PANTALONES
    // 1) 1500 Chupines + 750 Calidad Standard
    prenda = new Pantalon(
        TipoPantalon(EnumTypes::pantalon::CHUPINES, EnumTypes::getDescPantalon(EnumTypes::pantalon::CHUPINES)),
        TipoCalidad(EnumTypes::calidad::STANDARD, EnumTypes::getDescCalidad(EnumTypes::calidad::STANDARD)),
        750
    );
    tienda.addPrenda(prenda);
    // 2) 1500 Chupines + 750 Calidad Premium
    prenda = new Pantalon(
        TipoPantalon(EnumTypes::pantalon::CHUPINES, EnumTypes::getDescPantalon(EnumTypes::pantalon::CHUPINES)),
        TipoCalidad(EnumTypes::calidad::PREMIUM, EnumTypes::getDescCalidad(EnumTypes::calidad::PREMIUM)),
        750
    );
    tienda.addPrenda(prenda);
    // 3) 500 Comunes + 250 Standard
    prenda = new Pantalon(
        TipoPantalon(EnumTypes::pantalon::COMUNES, EnumTypes::getDescPantalon(EnumTypes::pantalon::COMUNES)),
        TipoCalidad(EnumTypes::calidad::STANDARD, EnumTypes::getDescCalidad(EnumTypes::calidad::STANDARD)),
        250
    );
    tienda.addPrenda(prenda);
    // 4) 500 Comunes + 250 Premium
    prenda = new Pantalon(
        TipoPantalon(EnumTypes::pantalon::COMUNES, EnumTypes::getDescPantalon(EnumTypes::pantalon::COMUNES)),
        TipoCalidad(EnumTypes::calidad::PREMIUM, EnumTypes::getDescCalidad(EnumTypes::calidad::PREMIUM)),
        250
    );
    tienda.addPrenda(prenda);
}