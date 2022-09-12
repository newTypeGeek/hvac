#include "../constants.h"
#include "gordon_ng.h"
#include <stdexcept>
#include <sstream>
#include <string>

GordonNg::GordonNg(double a1, double a2, double a3, double a4, ChillerType ch_type) {
    if (a3 < 1) {
        std::stringstream msg;
        msg << "a3 must be >= 1, but your input is "  << a3;
        throw std::invalid_argument(msg.str());
    }

    if (a4 < 0) {
        std::stringstream msg;
        msg << "a4 must be >= 0, but your input is "  << a4;
        throw std::invalid_argument(msg.str());
    }

    if (ch_type == kWaterCooledType) {
        spec_heat_cd = kWaterSpecHeat;
        density_cd = kWaterDensity;
    } else if (ch_type == kSeawaterCooledType)
    {
        spec_heat_cd = kSeawaterSpecHeat;
        density_cd = kSeawaterDensity;
    } else {
        spec_heat_cd = kAirSpecHeat;
        density_cd = kAirDensity;
    }

    // set gordon ng params
    gn_params[0] = a1;
    gn_params[1] = a2;
    gn_params[2] = a3;
    gn_params[3] = a4;
}


double GordonNg::celsius_to_kelvin(double t) {
    return t - kAbsZero;  // kAbsZero is negative
}

double GordonNg::compute_model_power(double cooling_load, double temp_ch_out, double temp_cd_in, double vol_flow_ch, double vol_flow_cd){
    double temp_ch_out_ = celsius_to_kelvin(temp_ch_out);
    double temp_cd_in_ = celsius_to_kelvin(temp_cd_in);

    double x = gn_params[0] * temp_ch_out_ * temp_cd_in_ + gn_params[1] * (temp_cd_in_ - temp_ch_out_) + cooling_load * temp_cd_in_;
    double y = gn_params[2] / (density_cd * vol_flow_cd * spec_heat_cd);
    double z = gn_params[3] / (density_ch * vol_flow_ch * spec_heat_ch);

    return (x / (temp_ch_out_ - cooling_load * (y + z))) - cooling_load;
}
