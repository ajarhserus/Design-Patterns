//Belongs to behavioural design pattern. Notifies any statechanges to all of the dependents.
// one to many relationship , can be considered as publisher subscriber model.

#include<iostream>
#include<vector>

using namespace std;

class Subscribers{
    public:
        virtual void update() = 0;
};

class Publisher{
    public:
        vector<Subscribers*> subs;

        void subscribe(Subscribers* sub){
            subs.push_back(sub);
        }

        void notify(){
            for(auto sub:subs){
                sub->update();
            }
        }

};


class SubscriberA:public Subscribers{
    public:
    void update(){
        cout<<"Notification Arrived A";
    }
};

class SubscriberB:public Subscribers{
    public:
    void update(){
        cout<<"Notification Arrived B";
    }
};


int main(){

    Publisher* p = new Publisher();

    Subscribers* subA = new SubscriberA();
    Subscribers* subB = new SubscriberB();

    p->subscribe(subA);
    p->subscribe(subB);

    p->notify();
    return 0;
}