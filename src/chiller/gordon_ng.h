#ifndef GordonNg_H
#define GordonNg_H
#include "constants.h"
#include <string>
#include <map>
#include <tuple>

class GordonNg {
    private:
        // gn_params[0] = Delta S_int  (unit: kJ / K)
        // gn_params[1] = Q_leak (unit: kJ)
        // gn_params[2] = 1 / eps_cd (unit: dimensionless)
        // gn_params[3] = (1- eps_ch) / eps_ch (unit: dimensionless)
        double gn_params[4];
        
        // Chilled Water Side
        const double spec_heat_ch = kWaterSpecHeat;
        const double density_ch = kWaterDensity;

        // Condensing Water Side (depends on ChillerType)
        double spec_heat_cd;
        double density_cd;

        double celsius_to_kelvin(double t);

    public:
        GordonNg(double a1, double a2, double a3, double a4, ChillerType ch_type);

        double compute_model_power(double cooling_load, double temp_ch_out, double temp_cd_in, double vol_flow_ch, double vol_flow_cd);
};

#endif