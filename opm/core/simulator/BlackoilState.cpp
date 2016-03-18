/*
  Copyright 2016 Statoil ASA.
  Copyright 2016 SINTEF ICT, Applied Mathematics.

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

#include <opm/core/simulator/BlackoilState.hpp>

namespace Opm
{


    BlackoilState::BlackoilState( size_t num_cells , size_t num_faces , size_t num_phases)
        : SimulationDataContainer( num_cells , num_faces , num_phases)
    {
        registerCellData("PRESSURE", 1, 0.0);
        registerCellData("TEMPERATURE", 1, 0.0);
        registerCellData("SATURATION", num_phases, 0.0);
        registerCellData("SURFACEVOL", num_phases, 0.0);
        registerCellData("GASOILRATIO", 1, 0.0);
        registerCellData("RV", 1, 0.0);
        registerFaceData("FACEPRESSURE", 1, 0.0);
        registerFaceData("FACEFLUX", 1, 0.0);
        setReferencePointers();
    }


    BlackoilState::BlackoilState(const BlackoilState& other)
        : SimulationDataContainer(other)
    {
        setReferencePointers();
    }


    BlackoilState& BlackoilState::operator=(const BlackoilState& other)
    {
        SimulationDataContainer::operator=(other);
        setReferencePointers();
        return *this;
    }


    void BlackoilState::setReferencePointers()
    {
        pressure_ref_     = &getCellData("PRESSURE");
        temperature_ref_  = &getCellData("TEMPERATURE");
        saturation_ref_   = &getCellData("SATURATION");
        surfacevol_ref_   = &getCellData("SURFACEVOL");
        gasoilratio_ref_  = &getCellData("GASOILRATIO");
        rv_ref_           = &getCellData("RV");
        facepressure_ref_ = &getFaceData("FACEPRESSURE");
        faceflux_ref_     = &getFaceData("FACEFLUX");
    }


} // namespace Opm
