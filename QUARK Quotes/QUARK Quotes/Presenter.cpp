#include "Presenter.h"
#include <typeinfo>
#include <ctime>


Presenter::Presenter(IView* view) : view(view)
{
	store = new Store("La Roperia", "Calle Falsa 123");
	getStoreData();

	Seller* seller = new Seller("Juan", "Perez", "5009");
	store->addSeller(seller);

	//Shirt(int stock, bool isPremium, bool isShortSleeved, bool hasMaoCollar)
	Garment* premiumShirtsShortSleves = new Shirt(150, true, true, false, "CamisaPremiumShort");
	Garment* premiumShirtsShortSlevesMao = new Shirt(100, true, true, true, "CamisaPremiumShortMao");
	Garment* shirtsShortSleves = new Shirt(150, false, true, false, "CamisaShort");
	Garment* shirtsShortSlevesMao = new Shirt(100, false, true, true, "CamisaShortMao");

	Garment* premiumShirts = new Shirt(175, true, false, false, "CamisaPremium");
	Garment* premiumShirtsMao = new Shirt(75, true, false, true, "CamisaPremiumMao");
	Garment* shirts = new Shirt(175, false, false, false, "Camisa");
	Garment* shirtsMao = new Shirt(75, false, false, true, "CamisaMao");

	//Pants(int stock, bool isPremium, bool isSkinny)
	Garment* premiumPants = new Pants(250, true, false, "PantPremium");
	Garment* premiumPantsSkinny = new Pants(750, true, true, "PantPremiumSkinny");
	Garment* pants = new Pants(250, false, false, "Pant");
	Garment* pantsSkinny = new Pants(750, false, true, "PantSkinny");

	store->addGarment(premiumShirtsShortSleves);
	store->addGarment(premiumShirtsShortSlevesMao);
	store->addGarment(shirtsShortSleves);
	store->addGarment(shirtsShortSlevesMao);

	store->addGarment(premiumShirts);
	store->addGarment(premiumShirtsMao);
	store->addGarment(shirts);
	store->addGarment(shirtsMao);

	store->addGarment(premiumPants);
	store->addGarment(premiumPantsSkinny);
	store->addGarment(pants);
	store->addGarment(pantsSkinny);
}

Presenter::~Presenter()
{
	delete store;
}

void Presenter::getStoreData()
{
	std::string storeName = store->getName();
	std::string storeAddress = store->getAddress();

	view->setStoreData(storeName, storeAddress); // seteamos en la vista los ítems de menú
}

void Presenter::getSellerData()
{
	Seller* seller = store->getSellers()[0];

	view->setSellerData(seller->getFullName(), seller->getSellerCode()); // seteamos en la vista los ítems de menú
}

void Presenter::getListOfItems()
{
	Seller* seller = store->getSellers()[0];

	view->setSellerData(seller->getFullName(), seller->getSellerCode()); // seteamos en la vista los ítems de menú
}

void Presenter::quote(newQuotationData *newQuotationData)
{
	Quotation* newQuotation;
	Seller* seller = store->getSellers()[0];
	for (Garment* garment : store->getGarments())
	{
		if (garment->getItemName().compare(newQuotationData->garmentString))
		{
			if (garment->getStock() < newQuotationData->quantity) 
			{
				view->showErrorScreen("No hay stock suficiente para hacer la cotización.", view->STEP_COTIZACION);
				return;
			}
			newQuotation = seller->quote(garment, newQuotationData->quantity, newQuotationData->unitPrice);
		}
	}
	int id = seller->getQuotations().size() + 1;
	time_t now = time(0);
	view->printQuotationData(std::to_string(newQuotation->getId()), newQuotation->getOperationDate(), seller->getSellerCode(), newQuotationData->garmentString,
		std::to_string(newQuotationData->unitPrice), std::to_string(newQuotationData->quantity), std::to_string(newQuotation->getQuotationResult()));
}

void Presenter::clearQuotationData(newQuotationData* newQuotationData)
{
	newQuotationData->garmentFeature1 = false;
	newQuotationData->garmentFeature2 = false;
	newQuotationData->garmentString = "";
	newQuotationData->quantity = 0;
	newQuotationData->unitPrice = 0.0;
}