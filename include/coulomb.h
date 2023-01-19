#ifndef CALCULATOR_COULOMB_FORCE_H
#define CALCULATOR_COULOMB_FORCE_H

#include "iforce.h"

/*! \file
 * \brief
 * Declares force evaluation class for coulomb force.
 *
 * \author Paul Bauer <paul.bauer.q@gmail.com>
 */

//! Coulomb force calculation.
class CoulombForceFunction : public IForceFunction
{

public:
    CoulombForceFunction(double chargeA, double chargeB) : chargeA_(chargeA), chargeB_(chargeB) {}
    ~CoulombForceFunction() override;

    //! Single force evaluation.
    ParticleCoords evaluateForce(double distanceSquared, ParticleCoords vector) override;

private:
    //! Partial charge on first particle.
    double chargeA_;
    //! Partial charge on second particle.
    double chargeB_;
};

#endif
