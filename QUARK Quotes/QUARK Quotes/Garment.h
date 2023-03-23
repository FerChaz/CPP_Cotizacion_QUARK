#pragma once

#ifndef _GARMENT_
#define _GARMENT_

#include <string>

class Garment
{
protected:
    std::string itemName;
    bool isPremium;
    float unitPrice;
    int stock;

public:
    Garment(int stock, bool isPremium, std::string itemName);
    virtual ~Garment();

    int getQuality() const;
    float getUnitPrice() const;
    int getStock() const;
    virtual std::string getItemName() const;

    void setQuality(std::string quality);
    void setUnitPrice(float unitPrice);
    void setStock(int stock);

    virtual float calculateFinalPrice() const = 0;
};

#endif