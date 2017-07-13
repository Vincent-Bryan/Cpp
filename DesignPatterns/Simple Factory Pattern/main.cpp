/*
 * Date        : 2017-07-13 22:17:48
 * Author      : Vincent Bryan
 * Description : a demo for simple factory pattern
 */

#include <iostream>
using namespace std;

typedef enum ProductTypeTag
{
	TypeA,
	TypeB,
	TypeC	
}PRODUCT_TYPE;

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
		Factory(){};
		~Factory(){};
		Product* CreateProduct(PRODUCT_TYPE type){
			switch(type){
				case TypeA:
					return new ProductA();
				case TypeB:
					return new ProductB();
				case TypeC:
					return new ProductC();
				default:
					return NULL;
			}
		}
};

int main(int argc, char const *argv[]){
	Factory *factory = new Factory();

	Product *productA = factory->CreateProduct(TypeA);
	if(productA != NULL){
		productA->show();
	}

	Product *productB = factory->CreateProduct(TypeB);
	if(productB != NULL){
		productB->show();
	}

	Product *productC = factory->CreateProduct(TypeC);
	if(productC != NULL){
		productC->show();
	}
	return 0;
}

