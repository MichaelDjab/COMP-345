#pragma once
#include <vector>
using std::vector;
#include <iostream>
using std::ostream;
#include <string>
using std::string;
#include "../Orders/Orders.h"
#include "../Player/Player.h"

// Card Class
class Card{
public:
    // Number of card instances counter
    static int numCreatedCards;
    // Default Constructor
    Card();
    // Copy Constructor
    Card(const Card& c);
    // Assignment Operator
    Card& operator =(const Card& c);
    // Destructor
    virtual ~Card();
    // Clone method for dynamic copies
    virtual Card* clone() = 0;
    // Virtual play method to be overridden by subclasses
    virtual Order* play() = 0;
    // Getters
    virtual string getCardType() = 0;
    int getId() const;
private:
    const static string cardType;
    int id;
};
// Stream insertion operator
ostream& operator<<(ostream& os, Card& c);

// Card Type Subclass
class BombCard : public Card{
public:
    // Default Constructor
    BombCard();
    // Copy Constructor
    BombCard(const BombCard& b);
    // Clone method for dynamic copies
    Card* clone();
    // Play method to return corresponding order
    Order* play();
    // Getter
    string getCardType();
private:
    const static string cardType;
};

// Card Type Subclass
class ReinforcementCard : public Card{
public:
    // Default Constructor
    ReinforcementCard();
    // Copy Constructor
    ReinforcementCard(const ReinforcementCard& r);
    // Clone method for dynamic copies
    Card* clone();
    // Play method to return corresponding order
    Order* play();
    // Getter
    string getCardType();
private:
    const static string cardType;
};

// Card Type Subclass
class BlockadeCard : public Card{
public:
    // Default Constructor
    BlockadeCard();
    // Copy Constructor
    BlockadeCard(const BlockadeCard& b);
    // Clone method for dynamic copies
    Card* clone();
    // Play method to return corresponding order
    Order* play();
    // Getter
    string getCardType();
private:
    const static string cardType;
};

// Card Type Subclass
class AirliftCard : public Card{
public:
    // Default Constructor
    AirliftCard();
    // Copy Constructor
    AirliftCard(const AirliftCard& a);
    // Clone method for dynamic copies
    Card* clone();
    // Play method to return corresponding order
    Order* play();
    // Getter
    string getCardType();
private:
    const static string cardType;
};

// Card Type Subclass
class DiplomacyCard : public Card{
public:
    // Default Constructor
    DiplomacyCard();
    // Copy Constructor
    DiplomacyCard(const DiplomacyCard& d);
    // Clone method for dynamic copies
    Card* clone();
    // Play method to return corresponding order
    Order* play();
    // Getter
    string getCardType();
private:
    const static string cardType;
};

// Deck Class
class Deck
{
public:
    // Default Constructor
    Deck();
    // Parameterized constructor initializes deck with vector of cards
    Deck(vector<Card *>& cards);
    // Copy Constructor
    Deck(const Deck& d);
    // Assignment Operator
    Deck& operator =(const Deck& d);
    // Destructor
    ~Deck();
    // Draw method removes card from the deck and adds it to the players hand
    Card* draw(Player& p);
    // Checks if deck is empty
    bool isEmpty();
    // Getter
    vector<Card *> &getCards();

private:
    vector<Card *> cards;
};
// Stream insertion operator
ostream& operator << (ostream& os, Deck& d);

// Hand Class
class Hand
{
public:
    // Default Constructor
    Hand();
    // Copy Constructor
    Hand(const Hand& h);
    // Assignment Operator
    Hand& operator=(const Hand& h);
    // Destructor
    ~Hand();
    // Adds passed Card to Hand
    void addCard(Card *c);
    // Removes card at index from Hand and adds it to the Deck
    Order* play(Deck& d,  int index);
    // Getter
    vector<Card *> &getCards();
    // Checks if Hand is empty
    bool isEmpty();

private:
    vector<Card *> cards;
};
// Stream insertion operator
ostream& operator << (ostream& os, Hand& h);


