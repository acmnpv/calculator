#ifndef CALCULATOR_GEOMETRY_H
#define CALCULATOR_GEOMETRY_H

/*! \file
 * \brief
 * Declares basic datastructres and functions to calculate distances between particles.
 *
 * \author Paul Bauer <paul.bauer.q@gmail.com>
 */


//! Single particle 3D coordinates.
struct ParticleCoords {
    //! X coord.
    double coordX = 1.0;
    //! Y coord.
    double coordY = 0.0;
    //! Z coord.
    double coordZ = -1.0;
};

//! Get distance from vector calculated between two particles.
double distance(ParticleCoords vector);

//! Get vector difference between two particles.
ParticleCoords vector(ParticleCoords particleA, ParticleCoords particleB);

#endif
