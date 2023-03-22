#pragma once
#include <string>

class EnumTypes {
    public : 
        enum camisa {
            MANGA_CORTA,
            MANGA_LARGA
        };

        enum cuello {
            CUELLO_MAO,
            CUELLO_COMUN
        };

        enum calidad {
            STANDARD,
            PREMIUM
        };

        enum pantalon {
            CHUPINES,
            COMUNES
        };

        static std::string getDescCamisa(camisa codigo) {
            std::string desc = "";
            switch (codigo) {
                case MANGA_CORTA : desc = "Manga corta"; break;
                case MANGA_LARGA : desc = "Manga larga"; break;
            }
            return desc;
        }

        static std::string getDescCuello(cuello codigo) {
            std::string desc = "";
            switch (codigo) {
                case CUELLO_MAO : desc = "Cuello mao"; break;
                case CUELLO_COMUN : desc = "Cuello común"; break;
            }
            return desc;
        }

        static std::string getDescCalidad(calidad codigo) {
            std::string desc = "";
            switch (codigo) {
                case STANDARD : desc = "Standard"; break;
                case PREMIUM : desc = "Premium"; break;
            }
            return desc;
        }

        static std::string getDescPantalon(pantalon codigo) {
            std::string desc = "";
            switch (codigo) {
                case CHUPINES : desc = "Chupines"; break;
                case COMUNES : desc = "Comunes"; break;
            }
            return desc;
        }
};