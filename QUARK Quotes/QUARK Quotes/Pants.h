#pragma once
#ifndef _PANTS_
#define _PANTS_

#include "Garment.h"
class Pants : public Garment
{
private:
    bool isSkinny;

public:
    Pants(int stock, bool isPremium, bool isSkinny, std::string itemName) : Garment(stock, isPremium, itemName), isSkinny(isSkinny) {}

    float calculateFinalPrice() const override;
    bool getIsSkinny() const;
};

#endif