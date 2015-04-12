#pragma once

#include "Util.h"

namespace rc {

template<typename T>
void newpropConformsToEquals() {
    newprop(
        "copies are equal",
        [] (const T &x) {
            T copy(x);
            RC_ASSERT(x == copy);
            RC_ASSERT(copy == x);
            RC_ASSERT(!(x != copy));
            RC_ASSERT(!(copy != x));
        });

    newprop(
        "== is the opposite of !=",
        [] (const T &x1, const T &x2) {
            RC_ASSERT((x1 == x2) == !(x1 != x2));
            RC_ASSERT((x2 == x1) == !(x2 != x1));
        });
}

template<typename T>
void newpropConformsToOutputOperator() {
    newprop(
        "output equality reflects input equality",
        [] (const T &x1, const T &x2) {
            std::ostringstream s1;
            s1 << x1;
            std::ostringstream s2;
            s2 << x2;
            RC_ASSERT((s1.str() == s2.str()) == (x1 == x2));
        });
}

#define NEWPROP_REPLACE_MEMBER_INEQUAL(Type, Member)            \
    newprop(                                                    \
        "not equal if " #Member " not equal",                   \
        [] (const Type &x) {                                    \
            auto other(x);                                      \
            other.Member = *newgen::distinctFrom(other.Member); \
            RC_ASSERT(x != other);                              \
            RC_ASSERT(other != x);                              \
            RC_ASSERT(!(x == other));                           \
            RC_ASSERT(!(other == x));                           \
        })

} // namespace rc
