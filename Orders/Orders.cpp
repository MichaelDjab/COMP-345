//
// Created by Alice on 2022-09-26.
//

/**
 * To do:
 * assignment operators for Orders and OrdersList
 * comments
 */

#include "Orders.h"

using namespace std;

// set constant members
const string Deploy::_orderType = "Deploy";
const string Advance::_orderType = "Advance";
const string Bomb::_orderType = "Bomb";
const string Blockade::_orderType = "Blockade";
const string Airlift::_orderType = "Airlift";
const string Negotiate::_orderType = "Negotiate";

/**
 * Default constructor for Order
 */
Order::Order() = default;

/**
 * Default destructor for Order
 */
Order::~Order() = default;

/**
 * Stream insertion operator for Order
 * @param o - Orders object
 * @param out - ostream object
 * @return ostream object
 */
ostream& operator << (ostream& out,  const Order& o) {
    out << o.getOrderType();
    return out;
}

Order& Order::operator=(const Order& o) {

}


/**
 * Default constructor for Deploy
 */
Deploy::Deploy() = default;

/**
 * Default destructor for Deploy
 */
Deploy::~Deploy() = default;

/**
 * Validate method - prints a string then returns true for a1
 * @return boolean
 */
bool Deploy::validate() const {
    cout << "Validating order. \n";
    return true;
}

/**
 * Execute method - prints order effect if validate returns true
 */
void Deploy::execute() const {
    if (validate()) {
        cout << "Executing " << *this << " order. \n";
        cout << orderEffect() << "\n\n";
    }
}

/**
 * Getter for order type
 * @return constant string for type of order
 */
string Deploy::getOrderType() const {
    return _orderType;
}

/**
 * Clone method - invokes default copy constructor since there is no object data member
 * @return Deploy - cloned object
 */
Order* Deploy::clone() const {
    return new Deploy(*this);
}

/**
 * Method returning order's effect
 * @return string
 */
string Deploy::orderEffect() const {
    return "Put a certain number of army units on a target territory.";
}

/**
 * Default constructor for Advance
 */
Advance::Advance() = default;

/**
 * Default destructor for Advance
 */
Advance::~Advance() = default;

/**
 * Validate method - prints a string for a1
 * @return boolean
 */
bool Advance::validate() const {
    cout << "Validating order. \n";
    return true;
}

/**
 * Execute method - prints order effect if validate returns true
 */
void Advance::execute() const {
    if (validate()) {
        cout << "Executing " << *this << " order. \n";
        cout << orderEffect() << "\n\n";
    }
}

/**
 * Getter for order type
 * @return constant string for type of order
 */
string Advance::getOrderType() const {
    return _orderType;
}

/**
 * Clone method - invokes default copy constructor since there is no object data member
 * @return Advance - cloned object
 */
Order* Advance::clone() const {
    return new Advance(*this);
}

/**
 * Method returning order's effect
 * @return string
 */
string Advance::orderEffect() const {
    return "Move a certain number of army units from one territory (source) to another (target).";
}

/**
 * Default constructor for Bomb
 */
Bomb::Bomb() = default;

/**
 * Default destructor for Bomb
 */
Bomb::~Bomb() = default;

/**
 * Validate method - prints a string for a1
 * @return boolean
 */
bool Bomb::validate() const {
    cout << "Validating order. \n";
    return true;
}

/**
 * Execute method - prints order effect if validate returns true
 */
void Bomb::execute() const {
    if (validate()) {
        cout << "Executing " << *this << " order. \n";
        cout << orderEffect() << "\n\n";
    }
}

/**
 * Getter for order type
 * @return constant string for type of order
 */
string Bomb::getOrderType() const {
    return _orderType;
}

/**
 * Clone method - invokes default copy constructor since there is no object data member
 * @return Bomb - cloned object
 */
Order* Bomb::clone() const {
    return new Bomb(*this);
}
/**
 * Method returning order's effect
 * @return string
 */
string Bomb::orderEffect() const {
    return "Destroy half of the army units located on a target territory. (Requires card)";
}

/**
 * Default constructor for Blockade
 */
Blockade::Blockade() = default;

/**
 * Default destructor for Blockade
 */
Blockade::~Blockade() = default;

/**
 * Validate method - prints a string for a1
 * @return boolean
 */
bool Blockade::validate() const {
    cout << "Validating order. \n";
    return true;
}

/**
 * Execute method - prints order effect if validate returns true
 */
void Blockade::execute() const {
    if (validate()) {
        cout << "Executing " << *this << " order. \n";
        cout << orderEffect() << "\n\n";
    }
}

/**
 * Getter for order type
 * @return constant string for type of order
 */
string Blockade::getOrderType() const {
    return _orderType;
}

/**
 * Clone method - invokes default copy constructor since there is no object data member
 * @return Blockade - cloned object
 */
Order* Blockade::clone() const {
    return new Blockade(*this);
}

/**
 * Method returning order's effect
 * @return string
 */
string Blockade::orderEffect() const {
    return "Triple the number of army units on a target territory and make it neutral. (Requires card)";
}

/**
 * Default constructor for Airlift
 */
Airlift::Airlift() = default;

/**
 * Default destructor for Airlift
 */
Airlift::~Airlift() = default;

/**
 * Validate method - prints a string for a1
 * @return boolean
 */
bool Airlift::validate() const {
    cout << "Validating order. \n";
    return true;
}

/**
 * Execute method - prints order effect if validate returns true
 */
void Airlift::execute() const {
    if (validate()) {
        cout << "Executing " << *this << " order. \n";
        cout << orderEffect() << "\n\n";
    }
}

/**
 * Getter for order type
 * @return constant string for type of order
 */
string Airlift::getOrderType() const {
    return _orderType;
}

/**
 * Clone method - invokes default copy constructor since there is no object data member
 * @return Airlift - cloned object
 */
Order* Airlift::clone() const {
    return new Airlift(*this);
}

/**
 * Method returning order's effect
 * @return string
 */
string Airlift::orderEffect() const {
    return "Advance a certain number of army units from one from one territory (source) to another (target). (Requires card)";
}

/**
 * Default constructor for Negotiate
 */
Negotiate::Negotiate() = default;

/**
 * Default destructor for Negotiate
 */
Negotiate::~Negotiate() = default;

/**
 * Validate method - prints a string for a1
 * @return boolean
 */
bool Negotiate::validate() const {
    cout << "Validating order. \n";
    return true;
}

/**
 * Execute method - prints order effect if validate returns true
 */
void Negotiate::execute() const {
    if (validate()) {
        cout << "Executing " << *this << " order. \n";
        cout << orderEffect() << "\n\n";
    }
}

/**
 * Getter for order type
 * @return constant string for type of order
 */
string Negotiate::getOrderType() const {
    return _orderType;
}

/**
 * Clone method - invokes default copy constructor since there is no object data member
 * @return Negotiate - cloned object
 */
Order* Negotiate::clone() const {
    return new Negotiate(*this);
}

/**
 * Method returning order's effect
 * @return string
 */
string Negotiate::orderEffect() const {
    return "Prevent attacks between the current player and another target player until the end of the turn. (Requires card)";
}

/**
 * Default constructor for OrdersList
 */
OrdersList::OrdersList() = default;

/**
 * Destructor for OrdersList
 */
OrdersList::~OrdersList(){
    int size = _ordersList.size();

    for (int i = 0; i < size; i++) {
        delete _ordersList[i];
    }
};

/**
 * Copy constructor for OrdersList - makes deep copy
 * @param ol - OrdersList object
 */
OrdersList::OrdersList(const OrdersList& ol) {
    int size = ol._ordersList.size();

    _ordersList = vector<Order*>(size);

    for (int i = 0; i < size; i++) {
        _ordersList[i] = ol._ordersList[i]->clone();
    }
}

/**
 * Stream insertion operator for OrdersList
 * @param ol - OrdersList object
 * @param out - ostream object
 * @return ostream object
 */
ostream& operator << (ostream& out, const OrdersList& ol) {
    int size = ol._ordersList.size();
    for (int i = 0; i < size; i++) {
        out << "[ " << *ol._ordersList[i] << " ] \n";
    }
    return out;
}


//OrdersList& OrdersList::operator=(const OrdersList& ol) {
//}

/**
 * Method to add an order to the player's orders' list
 * @param o - order object
 */
void OrdersList::add(Order* o) {
    // add new order to vector
    _ordersList.push_back(o);
}

/**
 * Method to remove an order from the player's orders' list
 * @param pos - an int for the position of the order to be removed
 */
void OrdersList::remove(int pos) {
    int size = _ordersList.size();

    if (size == 0)
        cout << "No order in list." << endl;
    else if (pos < 1 || pos > size)
        cout << "Invalid order position." << endl;
    else {
        // delete pointer
        delete _ordersList[pos-1];
        // resize vector
        _ordersList.erase(_ordersList.begin()+pos-1);
    }
}

/**
 * Method to move an order from one position to another in the player's orders' list
 * @param currentPos - an int for current position of the order
 * @param newPos - an int for the new position of the order
 */
void OrdersList::move(int currentPos, int newPos) {
    int size = _ordersList.size();

    if (size == 0)
        cout << "No order to move." << endl;
    else if (size == 1)
        cout << "Cannot swap with 1 order in list." << endl;
    else if (currentPos < 1 || newPos < 1 || currentPos > size || newPos > size)
        cout << "Invalid order position." << endl;
    else {
        // temp object storing order at current position
        Order* temp = _ordersList[currentPos-1];
        // move the order at target position to current position
        _ordersList[currentPos-1] = _ordersList[newPos-1];
        // move the order at current position to target position
        _ordersList[newPos-1] = temp;
    }
}

/**
 * Method to execute then remove orders sequentially from player's orders' list
 */
void OrdersList::executeList() {
    int size = _ordersList.size();

    if (size == 0)
        cout << "No order to execute." << endl;
    else {
        // execute each order in vector then delete pointer
        for (int i = 0; i < size; i++) {
            _ordersList[i]->execute();
            delete _ordersList[i];
        }
        // remove all elements from vector (now size 0)
        _ordersList.clear();
        // print new order list
        cout << "\nExecuted all orders. List is now empty." << endl;
    }
}