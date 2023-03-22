#pragma once

class Prenda {
    private : 
        int stock;
    public : 
        virtual ~Prenda(){};
        void setStock(int stock) {
            this->stock = stock;
        }
        int getStock() {
            return this->stock;
        }
};