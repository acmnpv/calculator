#ifndef CALCULATOR_PARTICLE_H
#define CALCULATOR_PARTICLE_H

#include <optional>
#include <tuple>

/*! \file
 * \brief
 * Declares particle datastructure.
 *
 * \author Paul Bauer <paul.bauer.q@gmail.com>
 */


//! Single particle data.
struct ParticleData {
    //! Construct for coloumb.
    ParticleData(double partialCharge)
        : charge(partialCharge) {}
    ParticleData(double lennardJones12, double lennardJones6)
        : lj12(lennardJones12), lj6(lennardJones6) {}

    //! Access charge.
    double getCharge();
    //! Access tuple of fields for LJ data.
    std::tuple<double, double> getLennardJones();

    //! Optional charge field.
    std::optional<double> charge;
    //! Optional Lennard Jones 12 parameter.
    std::optional<double> lj12;
    //! Optional Lennard Jones 6 parameter.
    std::optional<double> lj6;    
};

#endif
