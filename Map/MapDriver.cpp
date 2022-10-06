#include <iostream>
#include "MapDriver.h"
#include "Map.h"

// Test and Load Maps free function
void testLoadMaps(){

	// map files
	vector<string> filePaths {"Map/Maps/Annys Piratenwelt.map"};
	vector<Map*> maps;


	// read diff map_files and creates a map object
	for(string map_file: filePaths){
		maps.push_back(MapLoader::loadMap(map_file));
	}

	for(Map* map: maps){
		for(pair<int, Territory*> pair : map->territories){
			Territory* t = pair.second;
			std::cout<< *t << endl;
		}
	}

	for(Map* map: maps){
		map->validate();
	}

	//TODO: reject invalid map files
	// TODO: delete maps

}
