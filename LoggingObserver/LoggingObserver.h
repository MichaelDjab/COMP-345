#pragma once
#include <string>
#include <vector>
#include <fstream>
using std::string;
using std::vector;
using std::ofstream;
using std::endl;


class ILoggable{
public:
    virtual string stringToLog() = 0;
};

class Observer{
public:
    virtual void Update(ILoggable* o) = 0;
};

class Subject{
public:
    Subject();
    virtual ~Subject();
    virtual void Attach(Observer* o);
    virtual void Detach(Observer* o);
    virtual void Notify(ILoggable* _loggableObject);
private:
    Observer* observer = nullptr;
};

class LogObserver : public Observer{
public:
    LogObserver(string fileName);
    virtual ~LogObserver();
    void Update(ILoggable* o);
private:
    string fileName;
    ofstream outputStream;
};
