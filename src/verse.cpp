#include "verse.hpp"

#include <memory>
#include <stdexcept>
#include <thread>
#include <unistd.h>

void Verse::big_bang(){
    World the_first_world;

}

void Verse::runSimulation(){
    while (true)
    {
        this->currWorld->runNextUnitTime();
        sleep(statics::UNIT_TIME);   //wait for 1 second before executing the nextUnitTime of world
    }
}

bool Verse::createWorld(_timePoint t){
    return this->createWorld(this->currWorld, t);
}

bool Verse::createWorld(World_Ptr world, _timePoint){
    if(world == nullptr)    throw std::logic_error("createWorld called before initialising the worldTree");
    world->stopSimulation();

    World_Ptr newWorld = std::make_shared<World>(*(world.get()));   // CAUTION: dereferencing shared_ptr::get()
    this->worldTree.insert(newWorld);
    this->currWorld = newWorld;
   
}
