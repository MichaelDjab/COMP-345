//#include "LoggingObserver.h"
#include "../Orders/Orders.h"
#include "../GameEngine/GameEngine.h"

//class GameEngine;
//class Order;
//class OrdersList;
//class Deploy;

void testLoggingObserver(){


    Observer* obs = new LogObserver("gameLog.txt");
    GameEngine* game = new GameEngine(obs);

    OrdersList* ol = new OrdersList(game);
    Order* testDeploy = new Deploy(game);

    ol->add(testDeploy);
    testDeploy->execute();
}

