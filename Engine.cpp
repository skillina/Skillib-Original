#include <iostream>
#include <ctime>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "SOIL.h"
#include "skilLib.h"

extern Engine *theEngine;

Component::Component(){

}

int Component::getID(){
	return id;
}

System::System(){

}

void System::setIndex(int ind){
	index = ind;
}

int System::getID(){
	return id;
}

Engine::Engine(){

}

void Engine::addEntity(Entity *ent){
	entities.push_back(ent);
}

void Engine::removeEntity(int entIndex){
	if(entIndex < entities.size()){
		entities.erase(entities.begin()+entIndex);
	}
}

bool Engine::addSystem(System *sys){
	for(int x = 0; x < systems.size(); x++){
		if(systems.at(x)->getID() == sys->getID()){
			return false;
		}
	}

	systems.push_back(sys);
	return true;
}

bool Engine::removeSystem(int sysID){
	for(int x = 0; x < systems.size(); x++){
		if(systems.at(x)->getID() == sysID){
			systems.erase(systems.begin()+x);
			return true;
		}
	}
	return false;
}

void Engine::update(){
	for(int x = 0; x < systems.size(); x++){
		systems.at(x)->update(0);
	}
}

void Engine::start(){
	running = true;
	while(running){
		update();
	}
}

void Engine::shutDown(){
	running = false;
}

void shutDownEverything(){
	theEngine->shutDown();
}