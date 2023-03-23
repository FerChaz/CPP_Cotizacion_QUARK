#ifndef _SELLER_
#define _SELLER_

#include <string>
#include <vector>
#include "Quotation.h"
#include "Garment.h"
#include "Shirt.h"
#include "Pants.h"

class Seller
{
private:
    std::string name;
    std::string lastname;
    std::string sellerCode;
    std::vector<Quotation> quotationHistory;

public:
    Seller(std::string name, std::string lastname, std::string sellerCode) :
        name(name), lastname(lastname), sellerCode(sellerCode) {}

    std::string getName() const;
    std::string getLastname() const;
    std::string getFullName() const;
    std::string getSellerCode() const;

    void addQuotation(Quotation quotation);
    std::vector<Quotation> getQuotations() const;

    Quotation* quote(Garment* listedGarment, int garmentCuantity, float unitPrice);
};

#endif