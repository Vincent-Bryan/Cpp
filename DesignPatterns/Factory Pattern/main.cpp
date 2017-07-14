/*
 * Date        : 2017-07-14 10:24:25
 * Author      : Vincent Bryan
 * Description : a demo for factory pattern
 */

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

// Here is the product class
class Product{
	public:
		Product(){};
		~Product(){};
		virtual void show() = 0;
};

class ProductA : public Product{
	public:
		void show(){
			cout << "This is product A" << endl; 
		}
};

class ProductB : public Product{
	public:
		void show(){
			cout << "This is product B" << endl; 
		}
};

class ProductC : public Product{
	public:
		void show(){
			cout << "This is product C" << endl; 
		}
};

// Here is the factory pattern
class Factory{
	public:
		Factory(){
			//cout << "create" << endl;
		};
		~Factory(){
			cout << "quit!" << endl; 
		};
		virtual Product* CreateProduct() = 0;
};

class FactoryA : public Factory{
	public:
		Product *CreateProduct(){
			return new ProductA();
		}	
};

class FactoryB : public Factory{
	public:
		Product *CreateProduct(){
			return new ProductB();
		}	
};

class FactoryC : public Factory{
	public:
		Product *CreateProduct(){
			return new ProductC();
		}	
};

int main(int argc, char const *argv[]){
	Factory *factoryA = new FactoryA();
	Product *productA = factoryA->CreateProduct();
	productA->show();

	Factory *factoryB = new FactoryB();
	Product *productB = factoryB->CreateProduct();
	productB->show();

	Factory *factoryC = new FactoryC();
	Product *productC = factoryC->CreateProduct();
	productC->show();	
	

	if (factoryA != NULL)
	{
		delete factoryA;
		factoryA = NULL;
	}
	if (factoryB != NULL)
	{
		delete factoryB;
		factoryB = NULL;
	}
	if (factoryC != NULL)
	{
		delete factoryC;
		factoryC = NULL;
	}

	return 0;
}
