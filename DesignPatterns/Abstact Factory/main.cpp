/*
 * Date        : 2017-07-15 11:25:11
 * Author      : Vincent Bryan
 * Description : a demo for abstract factory
 */

#include <iostream>
using namespace std;

// Product A 
class ProductA{
	public:
		ProductA(){};
		~ProductA(){};
		virtual void show() = 0;
};

class ProductA1 : public ProductA{
	public:
		ProductA1(){};
		~ProductA1(){};
		void show(){
			cout << "This is ProductA1" << endl;
		}
};

class ProductA2 : public ProductA{
	public:
		ProductA2(){};
		~ProductA2(){};
		void show(){
			cout << "This is ProductA2" << endl;
		}
};

// Product B
class ProductB{
	public:
		ProductB(){};
		~ProductB(){};
		virtual void show() = 0;
};

class ProductB1 : public ProductB{
	public:
		ProductB1(){};
		~ProductB1(){};
		void show(){
			cout << "This is ProductB1" << endl;
		}
};

class ProductB2 : public ProductB{
	public:
		ProductB2(){};
		~ProductB2(){};
		void show(){
			cout << "This is ProductB2" << endl;
		}
};

// Factory
class Factory{
	public:
		Factory(){};
		~Factory(){};
		virtual ProductA *CreateProductA() = 0;
		virtual ProductB *CreateProductB() = 0;
};

class Factory1 : public Factory{
	public:
		Factory1(){};
		~Factory1(){};
		ProductA *CreateProductA(){
			return new ProductA1();
		}
		ProductB *CreateProductB(){
			return new ProductB1();
		}	
};

class Factory2 : public Factory{
	public:
		Factory2(){};
		~Factory2(){};
		ProductA *CreateProductA(){
			return new ProductA2();
		}
		ProductB *CreateProductB(){
			return new ProductB2();
		}	
};

int main(int argc, char const *argv[]){
	Factory *factory1 = new Factory1();
	ProductA *A1 = factory1->CreateProductA();
	ProductB *B1 = factory1->CreateProductB();
	A1->show();
	B1->show();

	Factory *factory2 = new Factory2();
	ProductA *A2 = factory2->CreateProductA();
	ProductB *B2 = factory2->CreateProductB();
	A2->show();
	B2->show();

	if(factory1 != NULL){
		delete factory1;
		factory1 = NULL;
	}
	if(A1 != NULL){
		delete A1;
		A1 = NULL;
	}
	if(B1 != NULL){
		delete B1;
		B1 = NULL;
	}
	if(factory2 != NULL){
		delete factory2;
		factory2 = NULL;
	}
	if(A2 != NULL){
		delete A2;
		A2 = NULL;
	}
	if(B2 != NULL){
		delete B2;
		B2 = NULL;
	}
	return 0;
}
