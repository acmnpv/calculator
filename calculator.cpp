#include <stdio.h>

#include "CLI/App.hpp"
#include "CLI/Formatter.hpp"
#include "CLI/Config.hpp"

#include "enums.h"
#include "coulomb.h"
#include "lennardjones.h"
#include "geometry.h"

int main(int argc, char* argv[])
{
    CLI::App app{"Simple force calculator for two particles."};
    auto groupA = app.add_option_group("ParticleA", "Values specific for first particle");
    double chargeA = 0.0;
    double lj12A = 0.0;
    double lj6A = 0.0;
    groupA->add_option("--chargeA", chargeA, "Partial charge on first particle");
    groupA->add_option("--lennard-jones-12A", lj12A, "Lennard Jones 12 value on first particle");
    groupA->add_option("--lennard-jones-6A", lj6A, "Lennard Jones 6 value on first particle");

    auto groupB = app.add_option_group("ParticleB", "Values specific for second particle");
    double chargeB = 0.0;
    double lj12B = 0.0;
    double lj6B = 0.0;
    groupB->add_option("--chargeB", chargeB, "Partial charge on second particle");
    groupB->add_option("--lennard-jones-12B", lj12B, "Lennard Jones 12 value on second particle");
    groupB->add_option("--lennard-jones-6B", lj6B, "Lennard Jones 6 value on second particle");

    ForceFunction type = ForceFunction::Coulomb;
    app.add_option("-t,--type", type, "What kind of force evaluation should be done");

    CLI11_PARSE(app, argc, argv);

    return 0;
}
