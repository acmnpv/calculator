/*! \file
 * \brief
 * Implements lennard jones force calculation.
 *
 * \author Paul Bauer <paul.bauer.q@gmail.com>
 */

#include "lennardjones.h"

namespace {

static double singleForce(double coord, double lj12, double lj6, double r, double r6, double r12)
{
    return ((12 * lj12 / (r12 * r)) - ( 6 * lj6 / (r6 * r))) * coord / r;
} 

}

ParticleCoords LennardJonesForceFunction::evaluateForce(double distance, ParticleCoords vector)
{
    const double r2 = distance * distance;
    const double r6 = r2*r2*r2;
    const double r12 = r6*r6;
    ParticleCoords result;
    result.coordX = singleForce(vector.coordX, lj12_, lj6_, distance, r6, r12);    
    result.coordY = singleForce(vector.coordY, lj12_, lj6_, distance, r6, r12);    
    result.coordZ = singleForce(vector.coordZ, lj12_, lj6_, distance, r6, r12);   
   return result; 
}

LennardJonesForceFunction::~LennardJonesForceFunction()
{}
