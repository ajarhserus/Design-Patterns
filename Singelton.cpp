// Desc : Only one instance will be created for the entire system.
/* Classical example is logging in a system . System may have several resources , but we need a single log for any event 
that occurs in the system 

Constraints:
   1. No Copy Constructor allowed or No copying of objects.
   2. No assignment operations
   3. Constructor should be private to prevent the creation of multiple instances.
   4. Class should be thread safety
   5. A static method for returning the instance.
*/

#include<iostream>

using namespace std;

class Singleton{
    private:
    Singleton(){

    }
  
    protected:
      static Singleton* singelton;
    public:
        Singleton(Singleton& object) = delete;
        Singleton& operator = (Singleton&) = delete;

        static Singleton* retrieveInstance(){
                if(singelton==nullptr){
                        singelton = new Singleton(); 
                        cout<<"Instance created first time"          ;            
                }
                return singelton;
        }
          ~Singleton(){
        cout<<"\n destructor";
    }


};

Singleton* Singleton::singelton=nullptr;

int main(){

    Singleton* a = Singleton::retrieveInstance();
    Singleton* b = Singleton::retrieveInstance();


    delete b;
   // delete a; // won't work  because its already deleted in above line.
    return 0;
}