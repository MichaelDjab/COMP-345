#include "LoggingObserver.h"
#include <iostream>


// Subject class
Subject::Subject() {
}

Subject::~Subject() {
}

void Subject::Attach(Observer *o) {
    observer = o;
}

void Subject::Detach(Observer *o) {
    if(observer != nullptr){
        observer = nullptr;
    }
}

void Subject::Notify(ILoggable *_loggableObject){
    if(observer != nullptr){
        observer->Update(_loggableObject);
    }
}



//LogObserver class
LogObserver::LogObserver(string name) : outputStream(fileName){
    fileName = name;
    outputStream.open(fileName, std::ios::out);
    outputStream << "---------------------------------" << endl;
    outputStream.close();
}

LogObserver::~LogObserver() {
}

void LogObserver::Update(ILoggable *o) {
    std::cout << "We are attempting to write to file...\n\n";
    outputStream.open(fileName, std::ios::app);
    outputStream << o->stringToLog() << endl;
    outputStream.close();
}