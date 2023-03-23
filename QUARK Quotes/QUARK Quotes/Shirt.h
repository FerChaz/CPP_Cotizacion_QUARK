#pragma once
#ifndef _SHIRT_
#define _SHIRT_

#include "Garment.h"
#include <string>

class Shirt : public Garment
{
private:
	bool isShortSleeved;
	bool hasMaoCollar;

public:
    Shirt(int stock, bool isPremium, bool isShortSleeved, bool hasMaoCollar, std::string itemName) : Garment(stock, isPremium, itemName), isShortSleeved(isShortSleeved), hasMaoCollar(hasMaoCollar) {}

    float calculateFinalPrice() const override;
    std::string getItemName() const override;
    bool getIsShortSleeved() const;
    bool getHasMaoCollar() const;
};

#endif