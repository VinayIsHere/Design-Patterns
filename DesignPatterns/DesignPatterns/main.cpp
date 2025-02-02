#include <iostream>

//for strategy pattern
#include "IDuck.h"
#include "MallardDuck.h"
#include "FlyRocketPowered.h"

//for observer pattern
#include "WeatherData.h"
#include "CurrentConditionDisplay.h"

//for decorator pattern
#include "Beverage.h"
#include "Espresso.h"
#include "HouseBlend.h"
#include "Soya.h"
#include "Mocha.h"
#include "Whip.h"


//for factory pattern
#include "PizzaStore.h"
#include "NYPizzaStore.h"
#include "ChicagoPizzaStore.h"

//for command pattern
#include "SimpleRemoteController.h"
#include "LightOnCommand.h"
#include "Light.h"
#include "RemoteControl.h"
#include "VideoconPlayerStereo.h"
#include "BedroomLight.h"
#include "LivingRoomCeilngFan.h"
#include "CeilingFanOnCommand.h"
#include "CeilingFanOffCommand.h"
#include "StereoOnWithCDCommand.h"
#include "LightOffCommand.h"
#include "NoCommand.h"
#include "CeilingFanHighCommand.h"

//for adapter pattern
#include "../AdapterPattern/Turkey.h"
#include "../AdapterPattern/TurkeyAdapter.h"
#include "../AdapterPattern/WildTurkey.h"

//for template method pattern
#include "../TemplateMethodPattern/CaffeineBeverage.h"
#include "../TemplateMethodPattern/Tea.h"
#include "../TemplateMethodPattern/Coffee.h"

//for iterator pattern
//#include "../IteratorPattern/Waiteress.h"
//#include "../IteratorPattern/DinerMenu.h"
//#include "../IteratorPattern/MenuItem.h"
//#include "../IteratorPattern/PancakeHouseMenu.h"
//#include "../IteratorPattern/Iterator.h"
//#include "../IteratorPattern/Menu.h"
//#include "../IteratorPattern/CafeMenu.h"

//Composite pattern
#include "../CompositePattern/Menu.h"
#include "../CompositePattern/MenuComponent.h"
#include "../CompositePattern/MenuItem.h"
#include "../CompositePattern/Waitress.h"

//State Pattern
#include "../StatePattern/GumballMachine.h"
#include "../StatePattern/HasQuarterState.h"
#include "../StatePattern/NoQuarterState.h"
#include "../StatePattern/SoldOutState.h"
#include "../StatePattern/SoldState.h"
#include "../StatePattern/WinnerState.h"

using namespace std;

void StrategicPatternUse();

void ObserverPatternUse();

void DecoratorPatternUse();

void factoryPatterUse();

void CommandPatternUse();

void AdapterPatternUse();
void testDuck(std::shared_ptr<IDuck> duck);

void TemplateMethodPattern();
void makeBeverage(std::shared_ptr<CaffieneBeverage> beverage);

void IteratorPattern();

void CompositePattern();

void StatePattern();

int main() {

	//StrategicPatternUse();
	
	//ObserverPatternUse();
	
	//DecoratorPatternUse();
	
	//factoryPatterUse();

	//CommandPatternUse();

	//AdapterPatternUse();

	//TemplateMethodPattern();

	//IteratorPattern();

	//CompositePattern();

	StatePattern();

	return 0;
}

void StrategicPatternUse()
{
	std::unique_ptr<IDuck> mallard = std::make_unique<MallardDuck>();
	mallard.get()->display();
	mallard.get()->performQuack();
	mallard.get()->performFly();

	mallard.get()->setFlyBehavior(std::make_shared<FlyRocketPowered>());
	mallard.get()->performFly();
}

void ObserverPatternUse()
{
	std::shared_ptr<WeatherData> weatherData = std::make_shared<WeatherData>();

	std::shared_ptr<CurrentConditionDisplay> currentDisplay = std::make_shared<CurrentConditionDisplay>(weatherData);
	weatherData.get()->registerObserver(currentDisplay);

	weatherData.get()->setMeasurements(80, 65, 30.4f);
}

void DecoratorPatternUse()
{
	std::shared_ptr<Beverage> beverage = std::make_shared<Espresso>();
	std::cout << beverage.get()->getDescription() << ", cost:" << beverage.get()->cost()<<std::endl;

	std::shared_ptr<Beverage> beverage2 = std::make_shared<HouseBlend>();
	beverage2 = std::make_shared<Mocha>(beverage2);
	beverage2 = std::make_shared<Mocha>(beverage2);
	beverage2 = std::make_shared<Whip>(beverage2);
	std::cout << beverage2.get()->getDescription() << ", cost:" << beverage2.get()->cost()<<std::endl;
}

void factoryPatterUse()
{
	//std::shared_ptr<PizzaStore> _store = std::make_shared<PizzaStore>();
	//_store.get()->orderPizza(ePizzaType::eCheese);
	std::shared_ptr<PizzaStore> nyStore = std::make_shared<NYPizzaStore>();
	nyStore.get()->orderPizza(ePizzaType::eCheese);
	
	std::cout << std::endl;

	std::shared_ptr<PizzaStore> chicagoStore = std::make_shared<ChicagoPizzaStore>();
	chicagoStore.get()->orderPizza(ePizzaType::ePepporoni);
}

void CommandPatternUse()
{
	//std::shared_ptr<SimpleRemoteController> simpleRemoteController = std::make_shared<SimpleRemoteController>();
	//std::shared_ptr<Light> light = std::make_shared<Light>();
	//std::shared_ptr<LightOnCommand> lightCommand = std::make_shared<LightOnCommand>(light);
	//
	//simpleRemoteController.get()->setCommand(lightCommand);
	//simpleRemoteController.get()->buttonPressed();

	//receivers
	std::shared_ptr<RemoteControl> remoteControl = std::make_shared<RemoteControl>();
	std::shared_ptr<BedroomLight> bedroomLight = std::make_shared<BedroomLight>();
	std::shared_ptr<LivingRoomCeilingFan> livingRoomFan = std::make_shared<LivingRoomCeilingFan>();
	std::shared_ptr<VideoconPlayerStereo> videoConPlayer = std::make_shared<VideoconPlayerStereo>();

	//commands
	std::shared_ptr<CeilingFanOnCommand> livingRoomfanOnCommand = std::make_shared<CeilingFanOnCommand>(std::static_pointer_cast<CeilingFan>(livingRoomFan));
	std::shared_ptr<CeilingFanOffCommand> livingRoomfanOffCommand = std::make_shared<CeilingFanOffCommand>(std::static_pointer_cast<CeilingFan>(livingRoomFan));
	std::shared_ptr<LightOnCommand> bedroomLightOnCommand = std::make_shared<LightOnCommand>(std::static_pointer_cast<Light>(bedroomLight));
	std::shared_ptr<LightOffCommand> bedroomLightOffCommand = std::make_shared<LightOffCommand>(std::static_pointer_cast<Light>(bedroomLight));
	std::shared_ptr<StereoOnWithCDCommand> VideoConStereoOnCommand = std::make_shared<StereoOnWithCDCommand>(std::static_pointer_cast<Stereo>(videoConPlayer));
	std::shared_ptr<CeilingFanHighCommand> livingRoomFanHighCommand = std::make_shared<CeilingFanHighCommand>(std::static_pointer_cast<CeilingFan>(livingRoomFan));

	//assing command to invoker (out remote control)
	remoteControl.get()->setCommand(0, bedroomLightOnCommand, bedroomLightOffCommand);
	remoteControl.get()->setCommand(1, livingRoomfanOnCommand, livingRoomfanOffCommand);
	remoteControl.get()->setCommand(2, VideoConStereoOnCommand, std::make_shared<NoCommand>());
	remoteControl.get()->setCommand(3, livingRoomFanHighCommand, std::make_shared<NoCommand>());

	//simulating remote control press
	remoteControl.get()->onButtonPressed(0);
	remoteControl.get()->offButtonPressed(0);
	remoteControl.get()->onButtonPressed(1);
	remoteControl.get()->offButtonPressed(1);
	remoteControl.get()->onButtonPressed(2);
	//remoteControl.get()->offButtonPressed(2);

	//lets try undo
	remoteControl.get()->undoButtonPressed();
	remoteControl.get()->onButtonPressed(0);
	remoteControl.get()->undoButtonPressed();
	remoteControl.get()->offButtonPressed(1);
	remoteControl.get()->undoButtonPressed();
	remoteControl.get()->onButtonPressed(1);
	remoteControl.get()->onButtonPressed(3);
	remoteControl.get()->undoButtonPressed();
}

void AdapterPatternUse()
{
	std::shared_ptr<MallardDuck> duck = std::make_shared<MallardDuck>();

	std::shared_ptr<WildTurkey> turkey = std::make_shared<WildTurkey>();
	std::shared_ptr<TurkeyAdapter> turkeyAdapter = std::make_shared<TurkeyAdapter>(turkey);
	turkeyAdapter.get()->setFlyBehavior(std::static_pointer_cast<IFlyBehavior>(turkeyAdapter));
	turkeyAdapter.get()->setQuackBehavior(std::static_pointer_cast<IQuackBehavior>(turkeyAdapter));

	std::cout << "The turkey says:" << std::endl;
	turkey.get()->gobble();
	turkey.get()->fly();

	std::cout << "The duck says:" << std::endl;
	testDuck(std::static_pointer_cast<IDuck>(duck));

	std::cout << "The turkey adapter says:" << std::endl;
	testDuck(std::static_pointer_cast<IDuck>(turkeyAdapter));
}

void testDuck(std::shared_ptr<IDuck> duck)
{
	duck.get()->performQuack();
	duck.get()->performFly();
}


void TemplateMethodPattern()
{
	std::shared_ptr<Tea> tea = std::make_shared<Tea>();
	std::shared_ptr<Coffee> coffee= std::make_shared<Coffee>();

	std::cout << "Making Tea:" << std::endl;
	makeBeverage(std::static_pointer_cast<CaffieneBeverage>(tea));

	std::cout << "Making Coffee:" << std::endl;
	makeBeverage(std::static_pointer_cast<CaffieneBeverage>(coffee));
}

void makeBeverage(std::shared_ptr<CaffieneBeverage> beverage)
{
	beverage.get()->prepareRecipe();
}

void IteratorPattern()
{
	//std::shared_ptr<DinerMenu> dinerMenu = std::make_shared<DinerMenu>();
	//std::shared_ptr<PancakeHouseMenu> pancakeMenu= std::make_shared<PancakeHouseMenu>();
	//std::shared_ptr<CafeMenu> cafeMenu = std::make_shared<CafeMenu>();

	//std::vector<std::shared_ptr<Menu>> menus = {
	//	std::static_pointer_cast<Menu>(dinerMenu),
	//	std::static_pointer_cast<Menu>(pancakeMenu),
	//	std::static_pointer_cast<Menu>(cafeMenu)
	//};

	//std::shared_ptr<Waitress> waitress = std::make_shared<Waitress>(menus);

	//waitress.get()->printMenu();
}

void CompositePattern()
{
	std::shared_ptr<MenuComponent> pancakeHouseMenu = std::make_shared<Menu>("PANCAKE HOUSE MENU", "Breakfast");
	std::shared_ptr<MenuComponent> dinerMenu = std::make_shared<Menu>("DINER MENU", "Lunch");
	std::shared_ptr<MenuComponent> cafeMenu = std::make_shared<Menu>("CAFE MENU", "Dinner");
	std::shared_ptr<MenuComponent> dessertMenu = std::make_shared<Menu>("DESSERT MENU", "Dessert of course");

	std::shared_ptr<MenuComponent> allMenus = std::make_shared<Menu>("ALL MENUS", "All Menus combined");
	
	allMenus.get()->add(pancakeHouseMenu);
	allMenus.get()->add(dinerMenu);
	allMenus.get()->add(cafeMenu);

	//Pancake Breakfast Menu
	pancakeHouseMenu.get()->add(std::static_pointer_cast<MenuComponent>(std::make_shared<MenuItem>(
		"K&Bs Pancake breakfast", 
		"Pancake with scrambled eggs and toast", 
		true, 
		2.99
	)));

	pancakeHouseMenu.get()->add(std::static_pointer_cast<MenuComponent>(std::make_shared<MenuItem>(
		"Regular Pancake breakfast", 
		"Pancake with fried eggs, sausage", 
		true, 
		2.99
	)));

	pancakeHouseMenu.get()->add(std::static_pointer_cast<MenuComponent>(std::make_shared<MenuItem>(
		"Bluebarry Pancakes", 
		"Pancakes made. with fresh bluebarries", 
		true, 
		3.49
	)));

	pancakeHouseMenu.get()->add(std::static_pointer_cast<MenuComponent>(std::make_shared<MenuItem>(
		"Waffles", 
		"Waffles with your choice of bluebarries or strawbarries", 
		true, 
		3.59
	)));

	//Diner Menu
	dinerMenu.get()->add(std::static_pointer_cast<MenuComponent>(std::make_shared<MenuItem>(
		"Vegetarian BLT", 
		"(Facon) Bacon with lettuce & tomato on whole wheat", 
		true, 
		2.99
	)));

	dinerMenu.get()->add(std::static_pointer_cast<MenuComponent>(std::make_shared<MenuItem>(
		"Soup of the day", 
		"Soup of the day, with a side of potato slide", 
		false, 
		3.29
	)));

	dinerMenu.get()->add(std::static_pointer_cast<MenuComponent>(std::make_shared<MenuItem>(
		"BLT", 
		"Bacon with lettuce & tomato on whole wheat", 
		false, 
		2.99
	)));

	//Dessert Menu
	dessertMenu.get()->add(std::static_pointer_cast<MenuComponent>(std::make_shared<MenuItem>(
		"Apple Pie",
		"Apple Pie with a flakey crust, topped with vanilla",
		true,
		1.59
	)));

	dinerMenu.get()->add(dessertMenu);

	//Caffee Menu

	cafeMenu.get()->add(std::static_pointer_cast<MenuComponent>(std::make_shared<MenuItem>(
		"Coffee",
		"A Simple Coffee",
		true,
		2.99
	)));

	cafeMenu.get()->add(std::static_pointer_cast<MenuComponent>(std::make_shared<MenuItem>(
		"Mocha", 
		"Coffee with white Mocha", 
		true, 
		3.99
	)));

	cafeMenu.get()->add(std::static_pointer_cast<MenuComponent>(std::make_shared<MenuItem>(
		"Cappachino", 
		"A Cappichino coffee", 
		true, 
		3.99
	)));

	//Waitress
	std::shared_ptr<Waitress> waitress = std::make_shared<Waitress>(allMenus);
	waitress.get()->printMenu();
}

void StatePattern()
{

	std::shared_ptr<GumballMachine> gumballMachine = std::make_shared<GumballMachine>(20);

	std::shared_ptr<State> soldOutState = std::static_pointer_cast<State>(std::make_shared<SoldOutState>(gumballMachine));
	std::shared_ptr<State> soldState = std::static_pointer_cast<State>(std::make_shared<SoldState>(gumballMachine));
	std::shared_ptr<State> noQuarterState = std::static_pointer_cast<State>(std::make_shared<NoQuarterState>(gumballMachine));
	std::shared_ptr<State> hasQuarterState = std::static_pointer_cast<State>(std::make_shared<HasQuarterState>(gumballMachine));
	std::shared_ptr<State> winnerState = std::static_pointer_cast<State>(std::make_shared<WinnerState>(gumballMachine));

	gumballMachine.get()->InitializeStates(
		soldOutState,
		soldState,
		noQuarterState,
		hasQuarterState,
		winnerState);

	gumballMachine.get()->InsertQuarter();
	gumballMachine.get()->TurnCrank();

	std::cout << "\n-----------------------------------------------\n" << std::endl;

	gumballMachine.get()->InsertQuarter();
	gumballMachine.get()->TurnCrank();
	gumballMachine.get()->InsertQuarter();
	gumballMachine.get()->TurnCrank();

	std::cout << "\n-----------------------------------------------\n" << std::endl;

	gumballMachine.get()->InsertQuarter();
	gumballMachine.get()->TurnCrank();
	gumballMachine.get()->InsertQuarter();
	gumballMachine.get()->TurnCrank();

	std::cout << "\n-----------------------------------------------\n" << std::endl;

	gumballMachine.get()->InsertQuarter();
	gumballMachine.get()->TurnCrank();
	gumballMachine.get()->InsertQuarter();
	gumballMachine.get()->TurnCrank();

	std::cout << "\n-----------------------------------------------\n" << std::endl;

	gumballMachine.get()->InsertQuarter();
	gumballMachine.get()->TurnCrank();
	gumballMachine.get()->InsertQuarter();
	gumballMachine.get()->TurnCrank();

	gumballMachine.get()->InsertQuarter();
	gumballMachine.get()->TurnCrank();
	gumballMachine.get()->InsertQuarter();
	gumballMachine.get()->TurnCrank();

	gumballMachine.get()->InsertQuarter();
	gumballMachine.get()->TurnCrank();
	gumballMachine.get()->InsertQuarter();
	gumballMachine.get()->TurnCrank();

	gumballMachine.get()->InsertQuarter();
	gumballMachine.get()->TurnCrank();
	gumballMachine.get()->InsertQuarter();
	gumballMachine.get()->TurnCrank();
}