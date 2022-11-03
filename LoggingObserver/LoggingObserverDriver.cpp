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

    Observer* _obs = new LogObserver();

    GameEngine* game;
    game = new GameEngine(_obs);

    Order* testDeploy = new Deploy(game);

    testDeploy->execute();







}