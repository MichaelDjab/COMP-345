#include "Map/MapDriver.h"
#include "Cards/CardsDriver.h"
#include "Orders/OrdersDriver.h"
#include "Player/PlayerDriver.h"
#include "../GameEngine/GameEngineDriver.h"
#include "CommandProcessing/CommandProcessingDriver.h"
#include "LoggingObserver/LoggingObserverDriver.h"
#include "Strategy/PlayerStrategiesDriver.h"
#include "../Tournament/TournamentDriver.h"



using namespace std;

int main()
{

    //Assignment 1:

    // Map
    //testLoadMaps();

    // Player
    //testPlayers();

    //Orders list
    //testOrdersList();

    //Cards
    //testCards();

    //GameEngine
    //testGameStates();


    //Assignment 2:

    //Part 1
    //testCommandProcessor();

    //Part 2
    //testStartupPhase();

    //Part 3
    //testMainGameLoop();

    //Part 4
    //testOrdersExecution();

    //Part 5
    //testLoggingObserver();

    //Assignment 3:

    //Part 1
    // testPlayerStrategies();

    //Part 2
    testTournament();
}

