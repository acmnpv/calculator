/*! \file
 * \brief
 * Implements coulomb force calculation.
 *
 * \author Paul Bauer <paul.bauer.q@gmail.com>
 */

#include "coulomb.h"

static constexpr double factor = 322;

namespace
{
static double singleForce(double prefactor, double coord, double r3)
{
    return prefactor * coord / r3;
}
} // namespace

CoulombForceFunction::~CoulombForceFunction() {}

ParticleCoords CoulombForceFunction::evaluateForce(double distance, ParticleCoords vector)
{
    const double   r3        = distance * distance * distance;
    const double   prefactor = factor * chargeA_ * chargeB_;
    ParticleCoords result;
    result.coordX = singleForce(prefactor, vector.coordX, r3);
    result.coordY = singleForce(prefactor, vector.coordY, r3);
    result.coordZ = singleForce(prefactor, vector.coordZ, r3);

    return result;
}
