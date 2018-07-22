#ifndef SHOP_H
#define SHOP_H
#include <avr/pgmspace.h>
#include "DataClasses.h"
#include "ArrayUtils.h"

// This file contains all data for the shop system
// We store the data in progmem.

// Here we store the prices of every unit buyable at a building.
// The order of the prices is the same as of UnitType
const uint8_t unitPrices[] PROGMEM = {
  10,
  30,
  50,

  40,
  50,
  70,
  160,
  60,
  150,
  120,

  90,
  200,
  220,

  180,
  255,
  120
};

class ShopDefinition
{
private:
	UnitType minUnitType = UnitType::None;
	UnitType maxUnitType = UnitType::None;

public:
	constexpr ShopDefinition(void) = default;

	constexpr ShopDefinition(UnitType minUnitType, UnitType maxUnitType)
		: minUnitType(minUnitType), maxUnitType(maxUnitType)
	{
	}

	constexpr UnitType getMinUnitType(void) const
	{
		return this->minUnitType;
	}
	
	constexpr UnitType getMaxUnitType(void) const
	{
		return this->maxUnitType;
	}
	
	constexpr uint8_t getNumberOfBuyableUnits(void) const
	{
		return 1 + (static_cast<uint8_t>(this->maxUnitType) - static_cast<uint8_t>(this->minUnitType));
	}
	
	constexpr bool isBuyable(UnitType unitType) const
	{
		return (unitType >= this->minUnitType) && (unitType <= this->maxUnitType);
	}

	constexpr UnitType getUnitTypeAtIndex(uint8_t index) const
	{
		return static_cast<UnitType>(static_cast<uint8_t>(this->minUnitType) + index);
	}
};

const ShopDefinition ShopDefinitions[] PROGMEM = 
{
	// Factory
	ShopDefinition(UnitType::Soldier, UnitType::Missiles),
	// Airport
	ShopDefinition(UnitType::Heli, UnitType::Bomber),
	// Shipyard
	ShopDefinition(UnitType::Cruiser, UnitType::Transportship),
};

#endif
