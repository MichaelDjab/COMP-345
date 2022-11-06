//
// Created by Hongsuk on 11/1/2022.
//

#include "LoggingObserverDriver.h"
#include "LoggingObserver.h"
#include "../GameEngine/GameEngine.h"
#include "../Map/Map.h"
#include "../Orders/Orders.h"

#include <iostream>

class Order;
class Deploy;

int main(){


    // Order* testDeploy = new Deploy(game);

    // testDeploy->execute();

    Observer* _observers = new LogObserver();

    GameEngine* game;
    game = new GameEngine(_observers);


    //game->startupPhase();

    OrdersList* ol = new OrdersList;
    Order* testDeploy = new Deploy(game)

    testDeploy->execute();

    /*
    Order* testAdvance = new Advance(game);
    Order* testBomb = new BombCardOrder(game);
    Order* testBlockade = new BlockadeCardOrder(game);
    Order* testAirlift = new AirliftCardOrder(game);
    Order* testNegotiate = new Negotiate(game);


    // add orders
    cout << "\n============= Add orders =============\n" << endl;
    ol->add(testDeploy);
    cout << "Order added. Current list: \n" << *ol << endl;
    ol->add(testAdvance);
    cout << "Order added. Current list: \n" << *ol << endl;
    ol->add(testBomb);
    cout << "Order added. Current list: \n" << *ol << endl;
    ol->add(testBlockade);
    cout << "Order added. Current list: \n" << *ol << endl;
    ol->add(testAirlift);
    cout << "Order added. Current list: \n" << *ol << endl;
    ol->add(testNegotiate);
    cout << "Order added. Current list: \n" << *ol << endl;
*/

}
