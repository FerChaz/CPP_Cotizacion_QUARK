#pragma once
#ifndef _IVIEW_
#define _IVIEW_

#include <string>

class IView
{
public:
	virtual ~IView() = default;
	virtual void showText(const std::string& text) = 0;
	virtual void showErrorScreen(const std::string& text, const std::string step) = 0;
	virtual void setStoreData(const std::string storeName, const std::string storeAddress) = 0;
	virtual void setSellerData(const std::string sellerName, const std::string sellerCode) = 0;
	virtual void printQuotationData(std::string id, std::string date, std::string sellerCode, std::string garment, std::string unitPrice, std::string quantity, std::string finalPrice);

	const std::string STEP_MENU = "MenuPrincipal";
	const std::string STEP_HISTORIAL = "Historial";
	const std::string STEP_COTIZACION = "Cotizacion";

	const std::string STEP_COTI_CAMISA_A = "CamisaA";
	const std::string STEP_COTI_CAMISA_B = "CamisaB";

	const std::string STEP_COTI_PANTALON = "Pantalon";

	const std::string STEP_COTI_CALIDAD = "Calidad";
	const std::string STEP_COTI_PRECIO = "Precio";
	const std::string STEP_COTI_STOCK = "Stock";
	const std::string STEP_COTI_FINAL_COTIZACION = "FinalCoti";

};

#endif