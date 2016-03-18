/*
  Copyright 2012 SINTEF ICT, Applied Mathematics.

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef OPM_TWOPHASESTATE_HEADER_INCLUDED
#define OPM_TWOPHASESTATE_HEADER_INCLUDED

#include <opm/common/data/SimulationDataContainer.hpp>

namespace Opm
{

    /// A state class suitable for incompressible two-phase
    /// computations.
    class TwophaseState : public SimulationDataContainer
    {
    public:
        TwophaseState(size_t num_cells , size_t num_faces);
        TwophaseState(const TwophaseState& other);
        TwophaseState& operator=(const TwophaseState& other);

        std::vector<double>& pressure  ();
        std::vector<double>& saturation();
        std::vector<double>& faceflux  ();

        const std::vector<double>& pressure  () const;
        const std::vector<double>& saturation() const;
        const std::vector<double>& faceflux  () const;

    private:
        void setReferencePointers();

        std::vector<double>* pressure_ref_;
        std::vector<double>* saturation_ref_;
        std::vector<double>* faceflux_ref_;
    };



    // Inline definition of accessor methods.

    inline std::vector<double>& TwophaseState::pressure()
    {
        return *pressure_ref_;
    }

    inline std::vector<double>& TwophaseState::saturation()
    {
        return *saturation_ref_;
    }

    inline std::vector<double>& TwophaseState::faceflux()
    {
        return *faceflux_ref_;
    }

    const inline std::vector<double>& TwophaseState::pressure() const
    {
        return *pressure_ref_;
    }

    const inline std::vector<double>& TwophaseState::saturation() const
    {
        return *saturation_ref_;
    }

    const inline std::vector<double>& TwophaseState::faceflux() const
    {
        return *faceflux_ref_;
    }


}

#endif
