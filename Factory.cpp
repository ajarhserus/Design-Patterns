/*
 --Hides the object creation logic to the client.
 --Single class for object creation.
 --Clients call the static method to create their product.
 --Creational design pattern.
*/

#include<iostream>
using namespace std;

class Product{
    public:
    virtual void get() = 0;
    virtual ~Product() {
        cout << "Product class freed\n";
    };
   
};

class ProductA:public Product{
    public:
        void get(){
            cout<<"Product A \n";
        }
         ~ProductA(){
            cout << "productA freed\n";
        }
     
};

class ProductB:public Product{
    public:
       void get(){
            cout<<"Product B \n";
        }

        ~ProductB(){
            cout << "productB freed\n";
        }
       
};


class Factory{
    public:
    static Product* createProduct(string product){
        if(product == "ProductA"){
            return new ProductA();
        }else if(product=="ProductB"){
            return new ProductB();
        }else{
            return nullptr;
        }
    }
};


int main(){

    Product* productA = Factory::createProduct("ProductA");
    Product* productB= Factory::createProduct("ProductB");

    productA->get();
    productB->get();

   delete productB;
   delete productA;

    return 0;
}