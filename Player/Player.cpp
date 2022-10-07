
#include "Player.h"
#include "Orders.h"



using namespace std;





//defualt constructor
Player::Player() {
    int playerID = 0;
    string name = "p1";
    vector<Territory*> territories;
    vector<Territory*> territoriesOwnedByPlayer; //territoriesOwned byPlayer
    Hand* hand;
    OrdersList* order_list;
}


Player::Player(int playerID, string name) {
    this->playerID = playerID;
    this->name = name;
    vector<Territory*> territories;
    vector<Territory*> territoriesOwnedByPlayer; //territoriesOwned byPlayer
    Hand* hand;
    OrdersList* order_list;
}


//Constructor with player id, territories, hand and orders
//So, the player owns territories, owns hand cards and list of orders

Player::Player(int playerID, string name, vector<Territory*> territories, Hand* hand, OrdersList* orders) {
    this->playerID = playerID;
    this->name = name;
    this->territories = territories;
    this->hand = hand;
    this->order_list = orders;
    vector<Territory*> territoriesOwnedByPlayer;
}


//copy constructor
Player::Player(const Player& p){
        playerID = p.playerID;
        name = p.name;
        territories = p.territories;
        hand = p.hand;
        order_list = p.order_list;
        territoriesOwnedByPlayer = p.territoriesOwnedByPlayer;
    }


// Destructor
Player::~Player()
{
    delete hand;
    delete order_list;
    territoriesOwnedByPlayer.clear();
    name.clear();

}



//Assignment operator
Player& Player::operator=(const Player& p){
    playerID = p.playerID;
    name = p.name;
    territories = p.territories;
    hand = p.hand;
    order_list = p.order_list;
    territoriesOwnedByPlayer = p.territoriesOwnedByPlayer;
    }





// toDefend() - returns a list of territories that are to be defended
vector<Territory*> Player:: toDefend(){
    return this->territoriesOwnedByPlayer; //for A1, return the territories that player owns
}
// toAttack() - returns a list of territories that are to be attacked
vector<Territory*> Player:: toAttack(){
    return this->territoriesOwnedByPlayer; //for A1, return the territories that player owns

}

void Player:: issueOrder(Player* p){
    cout << p->name <<  " Adds order" << endl; //Indicate which player is issuing orders
    Order* testDeploy = new Deploy;
    Order* testAdvance = new Advance;
    Order* testBomb = new Bomb;
    Order* testBlockade = new Blockade;
    Order* testAirlift = new Airlift;
    Order* testNegotiate = new Negotiate;

    OrdersList* ol = new OrdersList;


    cout << "\nAdd orders.\n" << endl;
    ol->add(testDeploy);
    ol->add(testAdvance);
    ol->add(testBomb);
    ol->add(testBlockade);
    ol->add(testAirlift);
    ol->add(testNegotiate);
    cout << "ExecuteList" << endl;
    //ol->executeList();

    setPlayerOrderList(ol);

    p->order_list->executeList(); //it executes each player's orderlist
}

void Player::addTerritory(Territory* t){
    territoriesOwnedByPlayer.push_back(t); // can be used like p1->addTerritory(t1*)
}












//getters


int Player::getPlayerID(){
    return playerID;
}

string Player:: getName(){
    return name;
}

Hand* Player::getHand(){
    return hand;
}
OrdersList* Player :: getPlayerOrderList(){
    return order_list;
}

vector<Territory*> Player::getTerritories(){
    return territories;
}

//setters

OrdersList* Player :: setPlayerOrderList(OrdersList* orders){
    this->order_list = orders;
}
