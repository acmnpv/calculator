#ifndef CALCULATOR_ENUMS_H
#    define SFDC_HASH_H

/*! \file
 * \brief
 * Declares enums for selecting function types.
 *
 * \author Paul Bauer <paul.bauer.q@gmail.com>
 */

//! Enum class for different force functions.
enum class ForceFunction : int
{
    //! Value for Coulomb potential
    Coulomb,
    //! Value for 12-6 (Lennard Jones) potential
    LennardJones
};


#endif
