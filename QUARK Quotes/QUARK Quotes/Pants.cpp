#include "Pants.h"

float Pants::calculateFinalPrice() const
{
    float price = unitPrice;

    if (isSkinny) {
        price *= 0.88; // Se aplica un descuento del 10% al precio si es manga corta
    }
    if (isPremium) {
        price *= 1.3; // Se aumenta el precio en un 30% si la calidad es premium
    }

    return price;
}

bool Pants::getIsSkinny() const { return isSkinny; }