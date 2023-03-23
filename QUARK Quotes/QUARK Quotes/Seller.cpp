#include "Seller.h"

using namespace std;

string Seller::getName() const { return name; }
string Seller::getFullName() const { return name + " " + lastname; }
string Seller::getLastname() const { return lastname; }
std::string Seller::getSellerCode() const { return sellerCode; }

void Seller::addQuotation(Quotation quotation)
{
	quotationHistory.push_back(quotation);
}

vector<Quotation> Seller::getQuotations() const { return quotationHistory; }

Quotation* Seller::quote(Garment* listedGarment, int garmentCuantity, float unitPrice) 
{
	Quotation* newQuotation;

	listedGarment->setUnitPrice(unitPrice);

	float finalPrice = listedGarment->calculateFinalPrice();

	newQuotation = new Quotation(int id, std::string operationDate, int sellerCode, Garment * garment, int garmentQuantity, float quotationResult);
	
}