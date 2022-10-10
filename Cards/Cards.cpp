#include "Cards.h"
#include <string>
#include <iostream>
#include <random>
#include "../Orders/Orders.h"
#include "../Player/Player.h"
using namespace std;

// Set constant Card Type members
const string BombCard::cardType = "Bomb";
const string ReinforcementCard::cardType = "Reinforcement";
const string BlockadeCard::cardType = "Blockade";
const string AirliftCard::cardType = "Airlift";
const string DiplomacyCard::cardType = "Diplomacy";

// Card Class
/**
 * Initialize the number of Cards created to 0
 */
int Card::numCreatedCards = 0;

/**
 * Default constructor for Card
 * Increase the number of Cards created by 1 and assigns the value to the id member
 */
Card::Card() {
    this->id = ++numCreatedCards;
}
/**
 * Card Copy Constructor
 * Copies id member
 */
Card::Card(const Card& c){
    this->id = c.id;
}
/**
 * Default destructor for Card
 * No dynamically allocated memory
 */
Card::~Card() = default;

/**
 * Card getter for id member
 */
int Card::getId() const{
    return id;
}
/**
 * Card assignment operator
 * Copies the id member
 */
Card& Card::operator=(const Card& c){
    if(this != &c){
        this->id = c.id;
    }
    return *this;
}
/**
 * Card stream insertion operator
 * Prints id and cardType members
 */
ostream& operator<<(ostream& os, Card& c){
    os << "card " << c.getId() << ": " << c.getCardType();
    return os;
}



// BombCardOrder Class
/**
 * BombCard Class default constructor
 * Calls Card Default constructor to initialize id member
 */
BombCard::BombCard() : Card(){}

/**
 * BombCard Class copy constructor
 * Calls Card opy constructor to copy id member
 */
BombCard::BombCard(const BombCard& b) : Card(b){}

/**
 * Default destructor for BombCard
 * No dynamically allocated memory
 */
BombCard::~BombCard() = default;

/**
 * BombCard Class clone method
 * Calls copy constructor to dynamically return copy
 */
Card* BombCard::clone() {
    return new BombCard(*this);
}
/**
 * BombCard Class play method
 * @return corresponding order instance
 */
Order* BombCard::play(){
    return new BombCardOrder;
}
/**
 * BombCard Class getter
 */
string BombCard::getCardType() {
    return cardType;
}

/**
 * Card stream insertion operator
 * Prints id and cardType members
 */
ostream& operator<<(ostream& os, BombCard& c){
    os << "card " << c.getId() << ": " << c.getCardType();
    return os;
}


// ReinforcementCard Class
/**
 * ReinforcementCard Class default constructor
 * Calls Card Default constructor to initialize id member
 */
ReinforcementCard::ReinforcementCard() : Card(){}

/**
 * ReinforcementCard Class copy constructor
 * Calls Card Default constructor to initialize id member
 */
ReinforcementCard::ReinforcementCard(const ReinforcementCard& r) : Card(r){}

/**
 * Default destructor for ReinforcementCard
 * No dynamically allocated memory
 */
ReinforcementCard::~ReinforcementCard() = default;
/**
 * ReinforcementCard Class clone method
 * Calls copy constructor to dynamically return copy
 */
Card* ReinforcementCard::clone() {
    return new ReinforcementCard(*this);
}

/**
 * ReinforcementCard Class play method
 * @return corresponding order instance
 */
Order* ReinforcementCard::play(){
    return nullptr;
}
/**
 * ReinforcementCard Class getter
 */
string ReinforcementCard::getCardType() {
    return cardType;
}
/**
 * Card stream insertion operator
 * Prints id and cardType members
 */
ostream& operator<<(ostream& os, ReinforcementCard& c){
    os << "card " << c.getId() << ": " << c.getCardType();
    return os;
}



// BlockadeCardOrder Class
/**
 * BlockadeCard Class default constructor
 * Calls Card Default constructor to initialize id member
 */
BlockadeCard::BlockadeCard() : Card(){}

/**
 * BlockadeCard Class copy constructor
 * Calls Card copy constructor to initialize id member
 */
BlockadeCard::BlockadeCard(const BlockadeCard& b) : Card(b){}

/**
 * Default destructor for BlockadeCard
 * No dynamically allocated memory
 */
BlockadeCard::~BlockadeCard() = default;

/**
 * BlockadeCard Class clone method
 * Calls copy constructor to dynamically return copy
 */
Card* BlockadeCard::clone() {
    return new BlockadeCard(*this);
}

/**
 * BlockadeCard Class play method
 * @return corresponding order instance
 */
Order* BlockadeCard::play() {
    return new BlockadeCardOrder;
}

/**
 * BlockadeCard Class getter
 */
string BlockadeCard::getCardType() {
    return cardType;
}
/**
 * Card stream insertion operator
 * Prints id and cardType members
 */
ostream& operator<<(ostream& os, BlockadeCard& c){
    os << "card " << c.getId() << ": " << c.getCardType();
    return os;
}


// AirliftCardOrder Class
/**
 * AirliftCard Class default constructor
 * Calls Card Default constructor to initialize id member
 */
AirliftCard::AirliftCard() : Card(){}

/**
 * AirliftCard Class copy constructor
 * Calls Card copy constructor to initialize id member
 */
AirliftCard::AirliftCard(const AirliftCard& a) : Card(a){}

/**
 * Default destructor for AirliftCard
 * No dynamically allocated memory
 */
AirliftCard::~AirliftCard() = default;

/**
 * AirliftCard Class clone method
 * Calls copy constructor to dynamically return copy
 */
Card* AirliftCard::clone() {
    return new AirliftCard(*this);
}

/**
 * AirliftCard Class play method
 * @return corresponding order instance
 */
Order* AirliftCard::play() {
    return new AirliftCardOrder;
}

/**
 * AirliftCard Class getter
 */
string AirliftCard::getCardType() {
    return cardType;
}
/**
 * Card stream insertion operator
 * Prints id and cardType members
 */
ostream& operator<<(ostream& os, AirliftCard& c){
    os << "card " << c.getId() << ": " << c.getCardType();
    return os;
}



// DiplomacyCard Class
/**
 * DiplomacyCard Class default constructor
 * Calls Card Default constructor to initialize id member
 */
DiplomacyCard::DiplomacyCard() : Card(){}

/**
 * DiplomacyCard Class copy constructor
 * Calls Card copy constructor to initialize id member
 */
DiplomacyCard::DiplomacyCard(const DiplomacyCard& d) : Card(d){}

/**
 * Default destructor for DiplomacyCard
 * No dynamically allocated memory
 */
DiplomacyCard::~DiplomacyCard() = default;

/**
 * DiplomacyCard Class clone method
 * Calls copy constructor to dynamically return copy
 */
Card* DiplomacyCard::clone(){
    return new DiplomacyCard(*this);
}

/**
 * DiplomacyCard Class play method
 * @return corresponding order instance
 */
Order* DiplomacyCard::play() {
    return new Negotiate;
}

/**
 * DiplomacyCard Class getter
 */
string DiplomacyCard::getCardType() {
    return cardType;
}
/**
 * Card stream insertion operator
 * Prints id and cardType members
 */
ostream& operator<<(ostream& os, DiplomacyCard& c){
    os << "card " << c.getId() << ": " << c.getCardType();
    return os;
}



// Hand Class
/**
 * Hand Class default constructor
 * Initializes empty Hand (Vector of Cards)
 */
Hand::Hand(){
    vector<Card *> c;
    this->cards = c;
}

/**
 * Hand Class copy constructor
 * Copies each card and adds them to new hand.
 * Uses the overridden clone method to dynamically make copies based on card type,.
 */
Hand::Hand(const Hand& h){
    for(Card *c : h.cards){
        this->cards.push_back(c->clone());
    }
}

/**
 * Hand Class destructor
 * Deallocates memory of each card in hand.
 * Clears Hand of dangling pointers
 */
Hand::~Hand() {
    for (Card* c : this->cards){
        delete c;
    }
    this->cards.clear();
}

/**
 * Hand Class addCard method
 * Adds passed Card pointer to Hand
 */
void Hand::addCard(Card *c){
    this->cards.push_back(c);
}

/**
 * Hand Class play method
 * Transfers played card from Hand to Deck
 * Creates corresponding Order based on the played Card's type
 * @return Order created by playing card
 */
Order* Hand::play(Deck& d, int index){
    Order* o = nullptr;
        if(index >= 0 && index < this->cards.size()){
            o = this->cards.at(index)->play();
            d.getCards().push_back(this->cards.at(index));
            this->cards.erase(this->cards.begin() + index);
        }
        else{
            cout << "Play failed - Invalid Index: " << index;
        }
        return o;
    }

/**
* Hand Class getter
* @return reference to the Hand's cards
*/
vector<Card *> &Hand::getCards(){
    return this->cards;
}

/**
* Hand Class isEmpty method
* @return if Hand is empty
*/
bool Hand::isEmpty(){
    return this->cards.empty();
}

/**
* Hand Class assignment operator
* copies each card from passed Hand
*/
Hand& Hand::operator=(const Hand& h) {
    if (this != &h) {
        for (Card *c: h.cards) {
            this->cards.push_back(c->clone());
        }
    }
    return *this;
}

/**
* Hand Class stream insertion operator
* Prints Cards in comma seperated format
*/
ostream& operator<<(ostream& os, Hand& h){
    int numCards = h.getCards().size();
    for (int i = 0; i < numCards; i++){
        if (i !=  numCards - 1){
            os << *h.getCards().at(i) << ", ";
        }
        else {
            os << *h.getCards().at(i);
        }
    }
    return os;
}



//Deck Class
/**
* Deck Class default constructor
* Initializes deck with 3 Cards of each type
*/
Deck::Deck(){
    for (int i = 0; i < 3; i++){
        this->cards.push_back(new BombCard());
    }
    for (int i = 0; i < 3; i++){
        this->cards.push_back(new ReinforcementCard());
    }
    for (int i = 0; i < 3; i++){
        this->cards.push_back(new BlockadeCard());
    }
    for (int i = 0; i < 3; i++){
        this->cards.push_back(new AirliftCard());
    }
    for (int i = 0; i < 3; i++){
        this->cards.push_back(new DiplomacyCard());
    }
}

/**
* Deck Class parameterized constructor
* Initializes deck with passed vector of cards
*/
Deck::Deck(vector<Card *>& cards){
    this->cards = cards;
}

/**
* Deck Class copy constructor
* Initializes deck with copy of vector of cards
*/
Deck::Deck(const Deck &d){
    for (Card *c : d.cards){
        this->cards.push_back(c->clone());
    }
}

/**
* Deck Class destructor
* Deallocates memory for each card in Deck
* Clears deck of dangling pointers
*/
Deck::~Deck() {
    for(Card* c : this->cards){
        delete c;
    }
    this->cards.clear();
}

/**
* Deck Class Draw method
* Removes random card from deck and places it in the Players Hand
* @return Pointer to Drawn Card
*/
Card* Deck::draw(Player& p){
    if (!cards.empty()){
        random_device rd;
        uniform_int_distribution<int> dist(0, cards.size() - 1);
        int randomIndex = dist(rd);
        p.getHand()->getCards().push_back(this->getCards().at(randomIndex));
        this->cards.erase(this->cards.begin() + randomIndex);
        return p.getHand()->getCards().back();
    }
    else{
        cout << "Draw Failed: Deck is Empty";
    }
    return nullptr;
}

/**
* Deck Class isEmpty method
* Tests if Deck is empty
*/
bool Deck::isEmpty(){
    return this->cards.empty();
}

/**
* Deck class getter
* @return reference to Deck's cards
*/
vector<Card*> &Deck::getCards(){
    return this->cards;
}

/**
* Deck Class assignment operator
* Copies each card in deck
*/
Deck& Deck::operator=(const Deck &d){
    for (Card* c : d.cards){
        this->cards.push_back(c->clone());
    }
    return *this;
}

/**
* Deck Class stream insertion operator
* Prints each Card in Deck
*/
ostream& operator <<(ostream& os, Deck& d){
    os << "Deck: " << endl;
    if (d.getCards().empty()){
        os << "deck is empty" << endl;
    }
    else{
        for (Card* c : d.getCards()) {
            os << *c << endl;
        }
    return os;
    }
    return os;
}