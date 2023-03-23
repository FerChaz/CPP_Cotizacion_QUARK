
#ifndef _QUOTATION_
#define _QUOTATION_

#include "Garment.h"
#include "Shirt.h"
#include "Pants.h"
#include <string>


class Quotation
{
private:
    int id;
    std::string operationDate;
    int sellerCode;
    Garment* listedGarment;
    int garmentQuantity;
    float quotationResult;

public:
    Quotation(int id, std::string operationDate, int sellerCode, Garment* garment, int garmentQuantity, float quotationResult) :
        id(id), operationDate(operationDate), sellerCode(sellerCode), listedGarment(listedGarment), garmentQuantity(garmentQuantity), quotationResult(quotationResult) {}

    int getId() const;
    std::string getOperationDate() const;
    int getSellerCode() const;
    Garment* getListedGarment() const;
    int getGarmentQuantity() const;
    float getQuotationResult() const;
};

#endif