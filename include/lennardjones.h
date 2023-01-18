#ifndef CALCULATOR_LENNARDJONES_FORCE_H
#define CALCULATOR_LENNARDJONES_FORCE_H

#include <cmath>

#include "iforce.h"

/*! \file
 * \brief
 * Declares force evaluation class for Lennard Jones.
 *
 * \author Paul Bauer <paul.bauer.q@gmail.com>
 */

//! LJ force calculation.
class LennardJonesForceFunction : public IForceFunction {

    public:
        LennardJonesForceFunction(double lj12A, double lj6A, double lj12B, double lj6B)
            : lj12_(std::sqrt(lj12A * lj12B)), lj6_(std::sqrt(lj6A*lj6B))
        {}

        ~LennardJonesForceFunction() override;

        ParticleCoords evaluateForce(double distance, ParticleCoords vector) override;
    private:
        //! LennardJones 12 parameter for particle pair.
        double lj12_;
        //! LennardJones 6 parameter for particle pair.
        double lj6_;

};

#endif
