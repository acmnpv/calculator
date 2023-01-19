#ifndef CALCULATOR_IFORCE_H
#define CALCULATOR_IFORCE_H

/*! \file
 * \brief
 * Declares interface for force evaluation.
 *
 * \author Paul Bauer <paul.bauer.q@gmail.com>
 */

#include "geometry.h"

//! Interface defining force functions.
class IForceFunction
{
public:
    virtual ~IForceFunction() {}
    //! Calculation routine.
    virtual ParticleCoords evaluateForce(double distance, ParticleCoords vector) = 0;
};

#endif
