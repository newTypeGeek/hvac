#include "constants.h"
#include "chiller/gordon_ng.h"
#include <iostream>

int main() {
    GordonNg chiller(-0.05, 100, 1.3, 0.1, kWaterCooledType);

    std::cout << chiller.compute_model_power(1000, 8.5, 27.2, 30.2, 46.5) << std::endl;
    return 0;
}