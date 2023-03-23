#pragma once
#ifndef _PRESENTER_
#define _PRESENTER_

#include "IView.h"
#include "Store.h"
#include <string>

class Presenter
{
private:
	IView* view;
	Store* store;
public: 
	struct newQuotationData {
		bool garmentFeature1;
		bool garmentFeature2;
		bool garmentIsPremium;
		std::string garmentString;
		float unitPrice;
		int quantity;
	};

	Presenter(IView* view);
	~Presenter();

	void clearQuotationData(newQuotationData* newQuotationData);
	void quote(newQuotationData* newQuotationData);
	void getStoreData();
	void getSellerData();
	void getListOfItems();

	
};

#endif