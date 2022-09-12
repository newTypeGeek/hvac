#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

enum ChillerType {
    kWaterCooledType,
    kSeawaterCooledType,
    kAircooledType,
};

// density in unit kg / L
static const double kWaterDensity = 0.997;
static const double kSeawaterDensity = 1.025;
static const double kAirDensity = 0.001204;

// specific heat capacity in unit kJ / (kg K)
static const double kWaterSpecHeat = 4.18;
static const double kSeawaterSpecHeat = 3.85;
static const double kAirSpecHeat = 1.012;

// absolute zero in degree celsius
static const double kAbsZero = -273.15;

#endif