#pragma once
#include <array>

class Lorenz{
    public:
    double sigma = 10;
    double rho = 28;
    double beta = 8 / 3;

    std::array<double,3> derivatives(const std::array<double,3>& state){
        double x = state[0];
        double y = state[1];
        double z = state[2];

        double dx = sigma * (y - x);
        double dy = x * (rho - z) - y;
        double dz = (x * y) - (beta * z);
        
        return {dx, dy, dz};
    }
};