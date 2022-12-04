#include "Cards.h"
#include <string>
#include <iostream>
#include <random>
#include "../Orders/Orders.h"
#include "../Player/Player.h"
#include "../GameEngine/GameEngine.h"
#include "../Strategy/PlayerStrategies.h"
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
    os << "card : " << c.getCardType() << " [" << c.getId() << "]";
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
 */
void BombCard::play(Player *player){
    Territory* targetTerr = player->toAttack().back();
    player->addOrder(new Bomb(targetTerr, player, player->getGame()));
    cout << *player << " played a Bomb card on " << targetTerr->get_name() << endl;
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
ReinforcementCard::ReinforcementCard() : Card(){
}

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
void ReinforcementCard::play(Player *player){
    player->setReinforcementPool(player->getReinforcementPool() + 5);
    cout << *player << " played a Reinforcement card and gained 5 additional army units" << endl;
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
void BlockadeCard::play(Player *player) {
    Territory *targetTerr = player->toDefend().back();
    player->addOrder(new Blockade(targetTerr, player, player->getGame()));
    cout << *player << " played a Blockade card on " << targetTerr->get_name() << endl;
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
void AirliftCard::play(Player *player) {
    // if player is aggressive
    if (player->getStrategy() != nullptr && player->getStrategy()->getStrategyName() == "Aggressive") {
        // get player's owned territories, # of owned territories and # of airlift card order issued this turn
            vector<Territory*> ownedTers = player->toDefend();
            int defendListSize = ownedTers.size();
            int airliftCardIssued = dynamic_cast<AggressivePlayerStrategy &>(*player->getStrategy()).getAirliftCardIssued();
            // default source territory is the weakest owned territory
            Territory *sourceTerr = ownedTers.front();
            // if there are 3+ territories, source territory is the nth strongest
            // n starts at 2nd, going down the list as more airlift card orders are issued
            if ((defendListSize - 2 - airliftCardIssued) >= 0) {
                sourceTerr = ownedTers.at(defendListSize - 2 - airliftCardIssued);
            }
            // target is the strongest territory
            Territory *targetTerr = ownedTers.back();
            // add airlift order to player's orderlist, increment # airlift order issued
            player->addOrder(new Airlift(sourceTerr, targetTerr, player, sourceTerr->get_army_units() + sourceTerr->get_issued_army_units(), player->getGame()));
            dynamic_cast<AggressivePlayerStrategy&>(*player->getStrategy()).setAirliftCardIssued(++airliftCardIssued);
            cout << *player << " played a Airlift card from " << sourceTerr->get_name() << " to " << targetTerr->get_name() << endl;
    }
    else {
        vector<Territory *> toDefendTerritories = player->toDefend();
        Territory *targetTerr = toDefendTerritories.front();
        Territory *sourceTerr = toDefendTerritories.back();
        // send half the armies of the most populated territory to the least populated
        player->addOrder(new Airlift(sourceTerr, targetTerr, player,
                                     (sourceTerr->get_army_units() + sourceTerr->get_issued_army_units()) / 2, player->getGame()));
        cout << *player << " played a Airlift card from " << sourceTerr->get_name() << " to " << targetTerr->get_name()
             << endl;
    }
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
void DiplomacyCard::play(Player *player) {
    Player* enemyPlayer = player->toAttack().back()->get_owner();
    player->addOrder(new Negotiate(player, enemyPlayer, player->getGame()));
    cout << *player << " played a Diplomacy card on " << *enemyPlayer << endl;
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
void Hand::play(Deck &d, Player* player, int index){
        if (!cards.empty()) {
            if(index >= 0 && index < this->cards.size()){
                this->cards.at(index)->play(player);
                d.getCards().push_back(this->cards.at(index));
                this->cards.erase(this->cards.begin() + index);
            }
            else{
                cout << "Play failed - Invalid Index: " << index;
            }
        }
        return;
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
    for (Card *c : cards){
        delete c;
    }
    this->cards.clear();
}

/**
* Deck Class Draw method
* Removes random card from deck and places it in the Players Hand
*/
void Deck::draw(Player& p){
    // if player has a strategy, call drawStrategy method
    if (p.getStrategy() != nullptr) {
        drawStrategy(p);
    }
    else if (!cards.empty()) {
        random_device rd;
        uniform_int_distribution<int> dist(0, cards.size() - 1);
        int randomIndex = dist(rd);
        p.getHand()->getCards().push_back(this->getCards().at(randomIndex));
        this->cards.erase(this->cards.begin() + randomIndex);
        return;
    }
    else{
        cout << "Draw Failed: Deck is Empty";
    }
    return;
}

/**
* Deck Class acceptCard method
* Check if a drawn card is valid for the player strategy
 * Neutral/Agressive - no Blockade/Diplomacy
 * Benevolent - no Bomb
* @return bool
*/
bool Deck::acceptCard(string ps, string cardType) {
    if (ps == "Benevolent" && cardType == "Bomb")
        return false;
    else if ((ps == "Aggressive" || ps == "Neutral") && (cardType == "Blockade" || cardType == "Diplomacy"))
        return false;
    else {
        return true;
    }
}

/**
* Deck Class drawStrategy method
 * draw appropriate cards for players with strategies
*/
void Deck::drawStrategy(Player &p) {
    // Cheater doesn't use cards
    if (p.getStrategy()->getStrategyName() == "Cheater") {
        return;
    }
    else if (!cards.empty()){
        random_device rd;
        uniform_int_distribution<int> dist(0, cards.size() - 1);
        int randomIndex = dist(rd);
        Card *drawnCard = this->getCards().at(randomIndex);

        // if drawn card is not acceptable for player strategy, draw again
        while (!acceptCard(p.getStrategy()->getStrategyName(), drawnCard->getCardType())) {
            randomIndex = dist(rd);
            drawnCard = this->getCards().at(randomIndex);
        }

        p.getHand()->getCards().push_back(drawnCard);
        this->cards.erase(this->cards.begin() + randomIndex);
        return;
    }
    else{
        cout << "Draw Failed: Deck is Empty";
        return;
    }
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
    }
    return os;
}