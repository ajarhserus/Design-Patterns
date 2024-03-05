/*
        -- Structural design pattern
        -- Provides a simplified interface to initiate the complex objects behind it.

        Key Concepts:
        =============
            -- Facade     : Act as an interface & used by client.
            -- Subsystem  : Classes, interfaces , various functions that is not visible to client.

*/


      // Car -- Facade
      //  Engine,HeadLight -- Subsytems


#include<iostream>

using namespace std;

class Engine{
    public:
     void on(){
        cout << "Starting Engine... \n";
     }
     void off(){
        cout<<"Stopping Engine...\n";
     }
};

class HeadLight{
    public:
        void on(){
            cout<<"Turning on headlights \n";
        }
        void off(){
            cout << "Turning off headlights \n";
        }
};

class Car{
    Engine engine;
    HeadLight headlight;

    public:
    void start(){
        headlight.on();
        engine.on();
    }

    void stop(){
        engine.off();
        headlight.off();
    }
};

int main(){
    Car car;
    car.start();
    car.stop();

    return 0;
}

