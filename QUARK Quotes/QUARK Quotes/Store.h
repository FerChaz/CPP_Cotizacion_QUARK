
#ifndef _STORE_
#define _STORE_

#include <string>
#include <vector>
#include "Seller.h"
#include "Garment.h"

class Store
{
private:
    std::string name;
    std::string address;
    std::vector<Garment*> availableGarments;
    std::vector<Seller*> sellers;


public:
    Store(std::string name, std::string address) :
        name(name), address(address) {}

    std::string getName() const;
    std::string getAddress() const;

    void addGarment(Garment* garment);
    std::vector<Garment*> getGarments() const;
    void addSeller(Seller* seller);
    std::vector<Seller*> getSellers() const;
};

#endif