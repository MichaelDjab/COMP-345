#include <fstream>
#include <iostream>
#include "LoggingObserver.h"
#include <typeinfo>


using namespace std;

ILoggable::ILoggable(){}

Observer::Observer(){}


LogObserver::LogObserver() {}


Subject::Subject() {
    _observers = new list<Observer *>;
}

void Subject::Attach(Observer* o){
    _observers->push_back(o);
}

void Subject::Detach(Observer* o){
    _observers->remove(o);
}
void Subject::Notify(ILoggable* _loggable_object){



    list<Observer *>::iterator i = _observers->begin();
    for (; i != _observers->end(); ++i) {
        cout << typeid(*i).name();
        (*i)->Update(_loggable_object);
    }
}



void LogObserver::Update(ILoggable* _loggable_object)
{
    cout << "herere" << endl;
    // opening output file stream
    ofstream logfile;
    logfile.open("gamelog.txt", ofstream::app); // append setting. If gamelog.txt is not found, it will create it.
    logfile << _loggable_object->stringToLog() << endl; // output the stringToLog to the output file
    logfile.close(); // close the output file stream
}

