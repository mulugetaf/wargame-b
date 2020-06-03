#include "doctest.h"
#include <iostream>
#include <stdexcept>

#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <cassert>
using namespace WarGame;

TEST_CASE("CHECK Soldier Creation")
{
	WarGame::Board b(4,4);
	b[{0,1}] = new Soldier(1);
	CHECK(b[{0,1}]!=nullptr);
	
	//can add here CHECK for any soldier type
	

	delete b[{0,1}];
}

TEST_CASE("CHECK Soldier Movement")
{
	WarGame::Board b(4,4);
	b[{0,1}] = new Soldier(1);
	
	//move up
	b.move(1,{0,1},WarGame::Board::MoveDIR::Up);
	CHECK(b[{1,1}]!=nullptr);
	
	delete b[{1,1}];
	//can add here CHECK for all directions
}

TEST_CASE("CHECK Soldier Attacks - NOT REALLY CUZ WE ARE NOT CHECKINH HEALTH POINTS")
{
	WarGame::Board b(4,4);
	b[{0,1}] = new Soldier(1);
	
	//creating enemy
	b[{3,1}] = new Soldier(2);
	CHECK(b[{3,1}]!=nullptr);
	
	//attacking
	b.move(1,{1,1}, WarGame::Board::MoveDIR::Down);
	b.move(1,{0,1}, WarGame::Board::MoveDIR::Up);
	b.move(1,{1,1}, WarGame::Board::MoveDIR::Down);
	b.move(1,{0,1}, WarGame::Board::MoveDIR::Up);
	b.move(1,{1,1}, WarGame::Board::MoveDIR::Down);
	b.move(1,{0,1}, WarGame::Board::MoveDIR::Up);
	b.move(1,{1,1}, WarGame::Board::MoveDIR::Down);
	b.move(1,{0,1}, WarGame::Board::MoveDIR::Up);

	delete b[{1,1}];

}

TEST_CASE("CHECK Enemy Killed")
{
	WarGame::Board b(4,4);
	b[{0,1}] = new Soldier(1);
	
	//creating enemy
	b[{3,1}] = new Soldier(2);
	
	//attacking
	b.move(1,{1,1}, WarGame::Board::MoveDIR::Down);
	b.move(1,{0,1}, WarGame::Board::MoveDIR::Up);
	b.move(1,{1,1}, WarGame::Board::MoveDIR::Down);
	b.move(1,{0,1}, WarGame::Board::MoveDIR::Up);
	b.move(1,{1,1}, WarGame::Board::MoveDIR::Down);
	b.move(1,{0,1}, WarGame::Board::MoveDIR::Up);
	b.move(1,{1,1}, WarGame::Board::MoveDIR::Down);
	b.move(1,{0,1}, WarGame::Board::MoveDIR::Up);
	
	//finish attack
	b.move(1,{1,1}, WarGame::Board::MoveDIR::Down);
	b.move(1,{0,1}, WarGame::Board::MoveDIR::Up);
	
	CHECK(b[{3,1}]!=nullptr);

	delete b[{1,1}];
}

TEST_CASE("CHECK Player1 Wone")
{
	WarGame::Board b(4,4);
	b[{0,1}] = new Soldier(1);
	
	//creating enemy
	b[{3,1}] = new Soldier(2);
	
	//attacking
	b.move(1,{1,1}, WarGame::Board::MoveDIR::Down);
	b.move(1,{0,1}, WarGame::Board::MoveDIR::Up);
	b.move(1,{1,1}, WarGame::Board::MoveDIR::Down);
	b.move(1,{0,1}, WarGame::Board::MoveDIR::Up);
	b.move(1,{1,1}, WarGame::Board::MoveDIR::Down);
	b.move(1,{0,1}, WarGame::Board::MoveDIR::Up);
	b.move(1,{1,1}, WarGame::Board::MoveDIR::Down);
	b.move(1,{0,1}, WarGame::Board::MoveDIR::Up);
	
	//finish attack
	b.move(1,{1,1}, WarGame::Board::MoveDIR::Down);
	b.move(1,{0,1}, WarGame::Board::MoveDIR::Up);
	
	
	CHECK(!b.has_soldiers(2));

	delete b[{1,1}];
}

TEST_CASE("WarGame::Board Edge Exceptions")
{
	WarGame::Board b(4,4);
        b[{0,1}] = new Soldier(1);

	CHECK_THROWS(b.move(1,{0,1}, WarGame::Board::MoveDIR::Down));
	
	//check other edgeds....
	
	delete b[{0,1}];
}

TEST_CASE("Other Exceptions")
{
	WarGame::Board b(4,4);
        b[{0,1}] = new Soldier(1);

	//creating enemy
	b[{1,1}] = new Soldier(2);
	CHECK(b[{1,1}]!=nullptr);
	
	//stepping on other soldier
    	CHECK_THROWS(b.move(1,{0,1}, WarGame::Board::MoveDIR::Up));
	
	//choosing wrong soldier(soldier belong to other player)
	CHECK_THROWS(b.move(2,{0,1}, WarGame::Board::MoveDIR::Down));
	
	//choosing place with no soldier
	CHECK_THROWS(b.move(2,{3,1}, WarGame::Board::MoveDIR::Down));

	delete b[{1,1}];
	delete b[{0,1}];
}
