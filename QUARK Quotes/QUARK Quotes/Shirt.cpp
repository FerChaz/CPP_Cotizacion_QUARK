#include "Shirt.h"


float Shirt::calculateFinalPrice() const 
{
    float price = unitPrice;

    if (isShortSleeved) {
        price *= 0.9; // Se aplica un descuento del 10% al precio si es manga corta
    }
    if (hasMaoCollar) {
        price *= 1.03; // Se aumenta el precio en un 3% si es de cuello mao y manga larga
    }
    if (isPremium) {
        price *= 1.3; // Se aumenta el precio en un 30% si la calidad es premium
    }

    return price;
}

bool Shirt::getIsShortSleeved() const { return isShortSleeved; }
bool Shirt::getHasMaoCollar() const { return hasMaoCollar; }
std::string Shirt::getItemName() const { return itemName; }