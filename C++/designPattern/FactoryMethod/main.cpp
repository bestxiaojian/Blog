#include "Factory.h"
#include "Product.h"

#include<iostream>
using namespace std;

int main() {
	Factory* fc = new ConcreteFactory();
	Product* p = fc->CreateProduct();
	return 0;
}