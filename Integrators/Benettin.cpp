#include <iostream>
#include <fstream>
#include <cmath>
#include <array>
#include "System\\Lorenz_System.hpp"

int main(){
    Lorenz system;
    
    double dt = 0.01;
    int steps = 80000;
    double sum = 0.0;
    double d_0 = 1e-8;

    std::array<double, 3> state1 = {1.0000000, 1.0000000, 1.0000000};
    std::array<double, 3> state2 = {1.0000001, 1.0000000, 1.0000000};

    std::ofstream file("lorenz_B.csv");
    file << "i,x,y,z\n";
    std::ofstream file2("lorenz2_B.csv");
    file2 << "i,x,y,z\n";
    std::ofstream divfile("lorenz_divergence_B.csv");
    divfile << "i,t,distance\n";

    for (int i = 0; i < steps; i++){
        auto k1 = system.derivatives(state1);

        std::array<double, 3> temp1;

        for (int j = 0; j < 3; j++)
            temp1[j] = state1[j] + 0.5 * dt * k1[j];
        auto k2 = system.derivatives(temp1);

        for (int j = 0; j < 3; j++)
            temp1[j] = state1[j] + 0.5 * dt * k2[j];
        auto k3 = system.derivatives(temp1);

        for(int j=0;j<3;j++)
            temp1[j] = state1[j] + dt*k3[j];
        auto k4 = system.derivatives(temp1);

        for(int j=0;j<3;j++)
            state1[j] += dt*(k1[j] + 2*k2[j] + 2*k3[j] + k4[j])/6.0;


        auto K1 = system.derivatives(state2);

        std::array<double, 3> temp2;

        for (int j = 0; j < 3; j++)
            temp2[j] = state2[j] + 0.5 * dt * K1[j];
        auto K2 = system.derivatives(temp2);

        for (int j = 0; j < 3; j++)
            temp2[j] = state2[j] + 0.5 * dt * K2[j];
        auto K3 = system.derivatives(temp2);

        for(int j=0;j<3;j++)
            temp2[j] = state2[j] + dt*K3[j];
        auto K4 = system.derivatives(temp2);

        for(int j=0;j<3;j++)
            state2[j] += dt*(K1[j] + 2*K2[j] + 2*K3[j] + K4[j])/6.0;

        double dx = state1[0] - state2[0];
        double dy = state1[1] - state2[1];
        double dz = state1[2] - state2[2];

        double distance = sqrt((double)(dx*dx + dy*dy + dz*dz));        
        double t = i * dt;

        //RENORMALISING 

        double scale = d_0 / distance;

        for (int j = 0; j < 3; j++) {
            state2[j] = state1[j] + (state2[j] - state1[j]) * scale;
        }
        
        divfile << i <<","<< t << "," << distance << "\n";
        file2 << i <<","<< state2[0] << "," << state2[1] << "," << state2[2] << "\n";
        file << i <<","<< state1[0] << "," << state1[1] << "," << state1[2] << "\n";
    }

    file.close();
    file2.close();
    divfile.close();
}