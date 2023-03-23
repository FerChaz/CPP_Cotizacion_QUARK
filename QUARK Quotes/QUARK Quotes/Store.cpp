#include "Store.h"

std::string Store::getName() const { return name; }
std::string Store::getAddress() const { return address; }

void Store::addGarment(Garment* garment)
{
	availableGarments.push_back(garment);
}
std::vector<Garment*> Store::getGarments() const { return availableGarments; }

void Store::addSeller(Seller* seller)
{
	sellers.push_back(seller);
}
std::vector<Seller*> Store::getSellers() const { return sellers; }