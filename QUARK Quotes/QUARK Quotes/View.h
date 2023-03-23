#pragma once
#ifndef _VIEW_
#define _VIEW_

#include <string>
#include <map>
#include "Presenter.h"


class View : public IView
{
private:
	Presenter* m_presenter;
	void showMainMenu();
	void showQuotationsHistory();
	void showMenuToMakeAQuotation();
	void showMenuToMakeAQuotation_ShirtA();
	void showMenuToMakeAQuotation_ShirtB();
	void showMenuToMakeAQuotation_Pants();
	void showMenuToMakeAQuotation_Quality();
	void showMenuToMakeAQuotation_Price();
	void showMenuToMakeAQuotation_Stock();
	void showFinalQuotation();
	void printQuotationData(std::string id, std::string date, std::string sellerCode, std::string garment, std::string unitPrice, std::string quantity, std::string finalPrice) override;


	void runOption(const char* option, bool& exitCondition, std::string step);
	void loadMenu(std::string step);
public:
	View();
	~View() override;
	void showText(const std::string& text) override;
	void showErrorScreen(const std::string& text, const std::string step) override;
	void setStoreData(const std::string storeName, const std::string storeAddress) override;
	void setSellerData(const std::string sellerName, const std::string sellerCode) override;
};

#endif