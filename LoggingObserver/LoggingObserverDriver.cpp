//
// Created by Hongsuk on 11/1/2022.
//

#include "LoggingObserverDriver.h"
#include "LoggingObserver.h"
#include "../GameEngine/GameEngine.h"
#include "../Map/Map.h"
#include "../Orders/Orders.h"

#include <iostream>

int main(){


    // Order* testDeploy = new Deploy(game);

    // testDeploy->execute();

    Observer* _observers = new LogObserver();

    GameEngine* game;
    game = new GameEngine(_observers);


    game->startupPhase();



}
