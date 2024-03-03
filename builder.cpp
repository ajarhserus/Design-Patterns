/* Title : Builder Design Pattern
   Builder design pattern is a creational design pattern that focuses on how to construct a complex product step by step.
   It consists of a director class , abstract builder , concrete builders and product classe.
*/

#include<iostream>
using namespace std;

class Product{

    public:
      void setFeatures(){
        cout << " Setting the features ...\n";
      }
    
};

class AbstractBuilder{
    public:
    virtual void buildProduct() = 0;
    virtual Product* getProduct()=0;
};

class ConcreteBuilder:public AbstractBuilder{
    public:
    void buildProduct(){
        product->setFeatures();
        cout << " Building Product .." << "\n" ;
    }
    Product* getProduct(){
        cout << " Product returned. \n";
        return product;
    }
    private:
    Product* product;
};

class Director{
    public:
        AbstractBuilder* abstractBuilder;
        Director(){

        }

        void setBuilder(AbstractBuilder* builder){
            cout<<"Builder Assigned \n";
            abstractBuilder  =  builder;
        }

        Product* getProduct(){
            return abstractBuilder->getProduct();
        }

        void orderBuilder(){
            abstractBuilder->buildProduct();
        }
};

int main(){

    Director* director = new Director();
    ConcreteBuilder* builder = new ConcreteBuilder();

    director->setBuilder(builder);
    director->orderBuilder();


    Product* product = director->getProduct();

    

    delete product;
    delete builder;
    delete director;

    return 0;
}