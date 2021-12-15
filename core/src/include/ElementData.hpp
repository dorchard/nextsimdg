/*!
 * @file ElementData.hpp
 * @date Sep 9, 2021
 * @author Tim Spain <timothy.spain@nersc.no>
 */

#ifndef SRC_INCLUDE_ELEMENTDATA_HPP
#define SRC_INCLUDE_ELEMENTDATA_HPP

#include "ExternalData.hpp"
#include "PrognosticData.hpp"
#include "include/PhysicsData.hpp"

namespace Nextsim {

//! A class to be used when a non-specific class derived from BaseElementData
// is needed.
class UnusedData : public BaseElementData {
};

/*!
 * @brief The class which holds all the data for a single element of the model.
 *
 * @detailed Inherits from PrognosticData, PhysicsData and ExternalData. The
 * physics implementation is provided as a template argument.
 */
template <class Phys>
class ElementData : public PrognosticData,
                    public PhysicsData,
                    public ExternalData,
                    public Phys,
                    public UnusedData,
                    public Configured<ElementData<Phys>> {
public:
    ElementData() = default;
    ~ElementData() = default;

    using PrognosticData::operator=;
    using PhysicsData::operator=;
    using ExternalData::operator=;
    using Phys::operator=;

    //! Configures the PrognosticData and physics implementation aspects of the
    // object.
    void configure() override
    {
        PrognosticData::configure();
        Phys::configure();
    }
};

} /* namespace Nextsim */

#endif /* SRC_INCLUDE_ELEMENTDATA_HPP */
