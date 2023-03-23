#include "Quotation.h"

using namespace std;

int Quotation::getId() const { return id; }
string Quotation::getOperationDate() const { return operationDate; }
int Quotation::getSellerCode() const { return sellerCode; }
Garment* Quotation::getListedGarment() const { return listedGarment; }
int Quotation::getGarmentQuantity() const { return garmentQuantity; }
float Quotation::getQuotationResult() const { return quotationResult; }