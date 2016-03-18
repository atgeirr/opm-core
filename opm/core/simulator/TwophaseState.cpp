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

#include <opm/core/simulator/TwophaseState.hpp>

namespace Opm
{

    TwophaseState::TwophaseState(size_t num_cells , size_t num_faces)
        : SimulationDataContainer( num_cells , num_faces , 2 )
    {
        registerCellData("PRESSURE", 1, 0.0);
        registerCellData("SATURATION", 2, 0.0);
        registerFaceData("FACEFLUX", 1, 0.0);

        setReferencePointers();
    }


    TwophaseState::TwophaseState(const TwophaseState& other)
        : SimulationDataContainer(other)
    {
        setReferencePointers();
    }


    TwophaseState& TwophaseState::operator=(const TwophaseState& other)
    {
        SimulationDataContainer::operator=(other);
        setReferencePointers();
        return *this;
    }


    void TwophaseState::setReferencePointers()
    {
        pressure_ref_   = &getCellData("PRESSURE");
        saturation_ref_ = &getCellData("SATURATION");
        faceflux_ref_   = &getFaceData("FACEFLUX");
    }
}


