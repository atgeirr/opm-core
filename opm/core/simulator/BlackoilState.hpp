/*
  Copyright 2012 SINTEF ICT, Applied Mathematics.
  Copyright 2015 IRIS AS

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

#ifndef OPM_BLACKOILSTATE_HEADER_INCLUDED
#define OPM_BLACKOILSTATE_HEADER_INCLUDED

#include <opm/common/data/SimulationDataContainer.hpp>

#include <opm/core/grid.h>
#include <opm/core/props/BlackoilPropertiesInterface.hpp>
#include <vector>

namespace Opm
{

    /// Simulator state for a blackoil simulator.
    class BlackoilState : public SimulationDataContainer
    {
    public:
        BlackoilState(size_t num_cells, size_t num_faces, size_t num_phases);
        BlackoilState(const BlackoilState& other);
        BlackoilState& operator=(const BlackoilState& other);

        std::vector<double>& pressure    ();
        std::vector<double>& temperature ();
        std::vector<double>& saturation  ();
        std::vector<double>& surfacevol  ();
        std::vector<double>& gasoilratio ();
        std::vector<double>& rv          ();
        std::vector<double>& facepressure();
        std::vector<double>& faceflux    ();

        const std::vector<double>& pressure    () const;
        const std::vector<double>& temperature () const;
        const std::vector<double>& saturation  () const;
        const std::vector<double>& surfacevol  () const;
        const std::vector<double>& gasoilratio () const;
        const std::vector<double>& rv          () const;
        const std::vector<double>& facepressure() const;
        const std::vector<double>& faceflux    () const;

    private:
        void setReferencePointers();
        std::vector<double>* pressure_ref_;
        std::vector<double>* temperature_ref_;
        std::vector<double>* saturation_ref_;
        std::vector<double>* surfacevol_ref_;
        std::vector<double>* gasoilratio_ref_;
        std::vector<double>* rv_ref_;
        std::vector<double>* facepressure_ref_;
        std::vector<double>* faceflux_ref_;
    };



    // Inline definition of accessor methods.

    // Non-const versions.

    inline std::vector<double>& BlackoilState::pressure()
    {
        return *pressure_ref_;
    }

    inline std::vector<double>& BlackoilState::temperature()
    {
        return *temperature_ref_;
    }

    inline std::vector<double>& BlackoilState::saturation()
    {
        return *saturation_ref_;
    }

    inline std::vector<double>& BlackoilState::surfacevol()
    {
        return *surfacevol_ref_;
    }

    inline std::vector<double>& BlackoilState::gasoilratio()
    {
        return *gasoilratio_ref_;
    }

    inline std::vector<double>& BlackoilState::rv()
    {
        return *rv_ref_;
    }

    inline std::vector<double>& BlackoilState::facepressure()
    {
        return *facepressure_ref_;
    }

    inline std::vector<double>& BlackoilState::faceflux()
    {
        return *faceflux_ref_;
    }

    // Const versions.

    inline const std::vector<double>& BlackoilState::pressure() const
    {
        return *pressure_ref_;
    }

    inline const std::vector<double>& BlackoilState::temperature() const
    {
        return *temperature_ref_;
    }

    inline const std::vector<double>& BlackoilState::saturation() const
    {
        return *saturation_ref_;
    }

    inline const std::vector<double>& BlackoilState::surfacevol() const
    {
        return *surfacevol_ref_;
    }

    inline const std::vector<double>& BlackoilState::gasoilratio() const
    {
        return *gasoilratio_ref_;
    }

    inline const std::vector<double>& BlackoilState::rv() const
    {
        return *rv_ref_;
    }

    inline const std::vector<double>& BlackoilState::facepressure() const
    {
        return *facepressure_ref_;
    }

    inline const std::vector<double>& BlackoilState::faceflux() const
    {
        return *faceflux_ref_;
    }






} // namespace Opm


#endif // OPM_BLACKOILSTATE_HEADER_INCLUDED
