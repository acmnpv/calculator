/*! \file
 * \brief
 * Implements distance calculation.
 *
 * \author Paul Bauer <paul.bauer.q@gmail.com>
 */

#include "geometry.h"

#include <cmath>

ParticleCoords vector(ParticleCoords particleA, ParticleCoords particleB)
{
    ParticleCoords result;
    result.coordX = particleB.coordX - particleA.coordX;
    result.coordY = particleB.coordY - particleA.coordY;
    result.coordZ = particleB.coordZ - particleA.coordZ;
    return result;
}

double distance(ParticleCoords vector)
{
    return std::sqrt((vector.coordX * vector.coordX) + (vector.coordY * vector.coordY) + (vector.coordZ * vector.coordZ));
}
