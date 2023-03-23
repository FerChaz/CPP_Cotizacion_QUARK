#include "View.h"
#include "Presenter.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>
#include <stdexcept>

std::string STORE_NAME = "NAN";
std::string STORE_ADDRESS = "NAN"; 
std::string SELLER_NAME = "NAN";
std::string SELLER_CODE = "NAN"; 

const std::string ANY_KEY_MESSAGE = "Escribe cualquier tecla para continuar.";
const std::string INVALID_OPTION_MESSAGE = "La opción ingresada es inválida, por favor reintente.";



Presenter::newQuotationData* data;


View::View()
{
	SetConsoleTitleW(L"Cotizaciones | QUARK");
	setlocale(LC_ALL, "es_Es");
	m_presenter = new Presenter(this);
	showMainMenu();
}

View::~View()
{
	delete m_presenter;
}

void View::showText(const std::string& text)
{
	std::cout << text << std::endl;
}

void View::showErrorScreen(const std::string& text, const std::string step)
{
	std::string option = "";
	std::system("cls");
	showText("COTIZADOR EXPRESS | HISTORIAL DE COTIZACIONES");
	showText("---------------------------------------------------");
	showText(text);
	showText(ANY_KEY_MESSAGE);
	showText("---------------------------------------------------");

	std::cin >> option;
	std::system("cls");
	loadMenu(step);
}

void View::setStoreData(const std::string storeName, const std::string storeAddress)
{
	STORE_NAME = storeName;
	STORE_ADDRESS = storeAddress;
}

void View::setSellerData(const std::string sellerName, const std::string sellerCode)
{
	SELLER_NAME = sellerName;
	SELLER_CODE = sellerCode;
}

void View::showMainMenu()
{
	std::string option;
	bool exitCondition = false;

	do
	{
		std::system("cls");
		showText("COTIZADOR EXPRESS | MENÚ PRINCIPAL");
		showText("---------------------------------------------------");
		showText(STORE_NAME + " | " + STORE_ADDRESS);
		showText("---------------------------------------------------");
		showText(SELLER_NAME + " | " + SELLER_CODE );
		showText("---------------------------------------------------");
		showText("Seleccione una opción del menu:");
		showText("");
		showText("1- Historial de Cotizaciones");
		showText("2- Realizar Cotización");
		showText("3- Salir");

		std::cin >> option;
		std::system("cls");

		runOption(option.c_str(), exitCondition, STEP_MENU);
		showText("");
		showText(ANY_KEY_MESSAGE);
		std::cin.get();
	} while (!exitCondition);
}

void View::showQuotationsHistory()
{
	std::string option = "";
	bool exitCondition = true;
	std::system("cls");
	showText("COTIZADOR EXPRESS | HISTORIAL DE COTIZACIONES");
	showText("---------------------------------------------------");
	showText("Presiona cualquier tecla para volver al menú principal");
	showText("---------------------------------------------------");

	//Ask the presenter for the history

	showText("---------------------------------------------------");
	showText("Presiona cualquier tecla para volver al menú principal");
	showText("---------------------------------------------------");

	std::cin >> option;
	std::system("cls");

	loadMenu(STEP_MENU);
}

void View::showMenuToMakeAQuotation()
{
	m_presenter->clearQuotationData(data);

	std::string option = "";
	bool exitCondition = true;
	do
	{
		std::system("cls"); 
		showText("COTIZADOR EXPRESS | MENÚ PRINCIPAL");
		showText("---------------------------------------------------");
		showText("Presiona 3 (tres) para volver al menú principal");
		showText("---------------------------------------------------");
		showText("Paso 1: Selecciona la prenda a cotizar:");
		showText("1- Camisa");
		showText("2- Pantalón");
		showText("---------------------------------------------------");

		std::cin >> option;
		std::system("cls");

		runOption(option.c_str(), exitCondition, STEP_COTIZACION);
		showText("");
		showText(ANY_KEY_MESSAGE);
		std::cin.get();
		


		std::cin.get();
	} while (!exitCondition);

	loadMenu(STEP_MENU);
}

void View::showMenuToMakeAQuotation_ShirtA()
{
	std::string option = "";
	bool exitCondition = true;
	do
	{
		std::system("cls");
		showText("COTIZADOR EXPRESS | MENÚ PRINCIPAL");
		showText("---------------------------------------------------");
		showText("Presiona 3 (tres) para volver al menú principal");
		showText("---------------------------------------------------");
		showText("Paso 2.a: La Camisa a cotizar, ¿Es Manga Corta?");
		showText("1- Sí");
		showText("2- No");
		showText("---------------------------------------------------");

		std::cin >> option;
		std::system("cls");

		std::system("cls");
		showText("COTIZADOR EXPRESS | MENÚ PRINCIPAL");
		showText("---------------------------------------------------");
		showText("Presiona 3 (tres) para volver al menú principal");
		showText("---------------------------------------------------");
		showText("Paso 2.a: La Camisa a cotizar, ¿Es Cuello Mao?");
		showText("1- Sí");
		showText("2- No");
		showText("---------------------------------------------------");

		std::cin >> option;
		std::system("cls");

		runOption(option.c_str(), exitCondition, STEP_COTI_CAMISA_A);
		showText("");
		showText(ANY_KEY_MESSAGE);
		std::cin.get();



		std::cin.get();
	} while (!exitCondition);

	loadMenu(STEP_MENU);
}

void View::showMenuToMakeAQuotation_ShirtB()
{
	std::string option = "";
	bool exitCondition = true;
	do
	{
		std::system("cls");
		showText("COTIZADOR EXPRESS | MENÚ PRINCIPAL");
		showText("---------------------------------------------------");
		showText("Presiona 3 (tres) para volver al menú principal");
		showText("---------------------------------------------------");
		showText("Paso 2.a: La Camisa a cotizar, ¿Es Cuello Mao?");
		showText("1- Sí");
		showText("2- No");
		showText("---------------------------------------------------");

		std::cin >> option;
		std::system("cls");

		runOption(option.c_str(), exitCondition, STEP_COTI_CAMISA_B);
		showText("");
		showText(ANY_KEY_MESSAGE);
		std::cin.get();



		std::cin.get();
	} while (!exitCondition);

	loadMenu(STEP_MENU);
}

void View::showMenuToMakeAQuotation_Pants()
{
	std::string option = "";
	bool exitCondition = true;
	do
	{
		std::system("cls");
		showText("COTIZADOR EXPRESS | MENÚ PRINCIPAL");
		showText("---------------------------------------------------");
		showText("Presiona 3 (tres) para volver al menú principal");
		showText("---------------------------------------------------");
		showText("Paso 2: El Pantalón a cotizar, ¿Es Chupín?");
		showText("1- Sí");
		showText("2- No");
		showText("---------------------------------------------------");

		std::cin >> option;
		std::system("cls");

		runOption(option.c_str(), exitCondition, STEP_COTI_PANTALON);
		showText("");
		showText(ANY_KEY_MESSAGE);
		std::cin.get();



		std::cin.get();
	} while (!exitCondition);

	loadMenu(STEP_MENU);
}

void View::showMenuToMakeAQuotation_Quality()
{
	std::string option = "";
	bool exitCondition = true;
	do
	{
		std::system("cls");
		showText("COTIZADOR EXPRESS | MENÚ PRINCIPAL");
		showText("---------------------------------------------------");
		showText("Presiona 3 (tres) para volver al menú principal");
		showText("---------------------------------------------------");
		showText("Paso 3: Seleccione la calidad de la prenda");
		showText("1- Standard");
		showText("2- Premium");
		showText("---------------------------------------------------");

		std::cin >> option;
		std::system("cls");

		runOption(option.c_str(), exitCondition, STEP_COTI_CALIDAD);
		showText("");
		showText(ANY_KEY_MESSAGE);
		std::cin.get();



		std::cin.get();
	} while (!exitCondition);

	loadMenu(STEP_MENU);
}

void View::showMenuToMakeAQuotation_Price()
{
	std::string priceString = "";
	bool exitCondition = true;
	do
	{
		std::system("cls");
		showText("COTIZADOR EXPRESS | MENÚ PRINCIPAL");
		showText("---------------------------------------------------");
		showText("Presiona 3 (tres) para volver al menú principal");
		showText("---------------------------------------------------");
		showText("Paso 4: Ingrese el precio unitario de la prenda a cotizar");
		std::cin >> priceString;
		showText("---------------------------------------------------");

		//Validacion float
		try {
			data->unitPrice = std::stof(priceString);
		}
		catch (const std::invalid_argument& e) {
			showText("El dato ingresado es invalido.");
			exitCondition = false;
		}
		std::system("cls");
		std::cin.get();
	} while (!exitCondition);

	loadMenu(STEP_COTI_STOCK);
}

void View::showMenuToMakeAQuotation_Stock()
{
	std::string stockString = "";
	bool exitCondition = true;
	do
	{
		std::system("cls");
		showText("COTIZADOR EXPRESS | MENÚ PRINCIPAL");
		showText("---------------------------------------------------");
		showText("Presiona 3 (tres) para volver al menú principal");
		showText("---------------------------------------------------");
		showText("INFORMACIÓN:");
		showText("EXISTE X CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA\n");
		showText("Paso 5: Ingrese la cantidad de unidades a cotizar");
		std::cin >> stockString;
		showText("---------------------------------------------------");

		//Validacion int
		try {
			data->quantity = std::stoi(stockString);
		}
		catch (const std::invalid_argument& e) {
			showText("El dato ingresado es invalido.");
			exitCondition = false;
		}
		std::system("cls");
		std::cin.get();
	} while (!exitCondition);

	loadMenu(STEP_MENU);
}

void View::showFinalQuotation()
{
	std::string option = "";
	bool exitCondition = true;
		std::system("cls");
		showText("COTIZADOR EXPRESS | MENÚ PRINCIPAL");
		showText("---------------------------------------------------");
		showText("Presiona una tecla para volver al menú principal");
		showText("---------------------------------------------------");
		
		//Show quotation from presenter
		m_presenter->quote(data);

		showText("---------------------------------------------------");


		std::cin.get();

	loadMenu(STEP_MENU);
}

void View::printQuotationData(std::string id, std::string date, std::string sellerCode, std::string garment, std::string unitPrice, std::string quantity, std::string finalPrice)
{
	showText("Número de identificación: " + id);
	showText("Fecha y Hora de la cotización: " + date);
	showText("Código del Vendedor: " + sellerCode);
	showText("Prenda cotizada: " + garment);
	showText("Precio unitaria: " + unitPrice);
	showText("Cantidad de unidades cotizadas: " + quantity);
	showText("Precio final: " + quantity);
}

void View::runOption(const char* option, bool& exitCondition, std::string step)
{
	std::string str_option = std::string(option);
	if ((str_option.compare("1") != 0 && str_option.compare("2") != 0 && str_option.compare("3") != 0) || ((str_option.compare("1") == 0 || str_option.compare("2") == 0) && step.compare(STEP_HISTORIAL) == 0))
	{
		showText(INVALID_OPTION_MESSAGE);
		std::cin.get();
		exitCondition = false;
		return;
	}


	if (str_option == "1")
	{
		if (step.compare(STEP_MENU))
		{
			loadMenu(STEP_HISTORIAL);
		}
		else if (step.compare(STEP_COTIZACION))
		{
			data->garmentString = "Camisa";
			loadMenu(STEP_COTI_CAMISA_A);
		}
		else if (step.compare(STEP_COTI_CAMISA_A))
		{
			data->garmentFeature1 = true;
			loadMenu(STEP_COTI_CAMISA_B);
		}
		else if (step.compare(STEP_COTI_CAMISA_B))
		{
			data->garmentFeature2 = true;
			loadMenu(STEP_COTI_CALIDAD);
		}
		else if (step.compare(STEP_COTI_PANTALON))
		{
			data->garmentFeature1 = true;
			loadMenu(STEP_COTI_CALIDAD);
		}
		else if (step.compare(STEP_COTI_CALIDAD))
		{
			data->garmentIsPremium = false;
			loadMenu(STEP_COTI_PRECIO);
		}
		exitCondition = false;
	}
	else if (str_option == "2")
	{
		if (step.compare( STEP_MENU))
		{
			loadMenu(STEP_COTIZACION);
		}
		else if (step.compare( STEP_COTIZACION))
		{
			data->garmentString = "Pantalón";
			loadMenu(STEP_COTI_PANTALON);
		}
		else if (step.compare( STEP_COTI_CAMISA_A))
		{
			data->garmentFeature1 = false;
			loadMenu(STEP_COTI_CAMISA_B);
		}
		else if (step.compare( STEP_COTI_CAMISA_B))
		{
			data->garmentFeature2 = false;
			loadMenu(STEP_COTI_CALIDAD);
		}
		else if (step.compare( STEP_COTI_PANTALON))
		{
			data->garmentFeature1 = false;
			loadMenu(STEP_COTI_CALIDAD);
		}
		else if (step.compare( STEP_COTI_CALIDAD))
		{
			data->garmentIsPremium = true;
			loadMenu(STEP_COTI_PRECIO);
		}
		exitCondition = false;
	}
	else if (str_option == "3")
	{
		std::string exitMessage = "Volviendo al menú principal...";
		if (step.compare( STEP_MENU)) exitMessage = "Saliendo...";

		showText(exitMessage);
		std::cin.get();
		exitCondition = true;
	}
	else
	{
		showText(INVALID_OPTION_MESSAGE);
		std::cin.get();
		exitCondition = false;
	}
}

void View::loadMenu(std::string step)
{
	if (step.compare( STEP_MENU))
	{
		showMainMenu();
	}
	else if (step.compare( STEP_COTIZACION))
	{
		showMenuToMakeAQuotation();
	}
	else if (step.compare( STEP_COTI_CAMISA_A))
	{
		showMenuToMakeAQuotation_ShirtA();
	}
	else if (step.compare( STEP_COTI_CAMISA_B))
	{
		showMenuToMakeAQuotation_ShirtB();
	}
	else if (step.compare( STEP_COTI_PANTALON))
	{
		showMenuToMakeAQuotation_Pants();
	}
	else if (step.compare( STEP_COTI_CALIDAD))
	{
		showMenuToMakeAQuotation_Quality();
	}
	else if (step.compare( STEP_COTI_PRECIO))
	{
		showMenuToMakeAQuotation_Price();
	}
	else if (step.compare( STEP_COTI_STOCK))
	{
		showMenuToMakeAQuotation_Stock();
	}
	else if (step.compare( STEP_COTI_FINAL_COTIZACION))
	{
		showFinalQuotation();
	}
	else
	{
		showQuotationsHistory();
	}
}

