#pragma once

#include "rapidcheck/detail/Results.h"
#include "rapidcheck/detail/TestParams.h"

#include "rapidcheck/detail/NewProperty.h"

namespace rc {
namespace detail {

//! Checks the given property using the given parameters and returns the
//! results.
TestResult checkProperty(const NewProperty &property,
                         const TestParams &params = defaultTestParams());

//! Overload which first converts the testable to a property.
template<typename Testable, typename ...Args>
TestResult newCheckTestable(Testable &&testable, const Args &...args);

} // namespace detail
} // namespace rc

#include "Check.hpp"
