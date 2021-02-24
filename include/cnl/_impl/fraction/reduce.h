
//          Copyright John McFarlane 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file ../LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#if !defined(CNL_IMPL_FRACTION_REDUCE_H)
#define CNL_IMPL_FRACTION_REDUCE_H

#include "definition.h"
#include "gcd.h"
#include "make_fraction.h"

/// compositional numeric library
namespace cnl {
    namespace _impl {
        template<typename Numerator, typename Denominator, typename Gcd>
        [[nodiscard]] constexpr auto reduce_from_gcd(
                fraction<Numerator, Denominator> const& f, Gcd const& gcd)
        {
            return make_fraction(f.numerator / gcd, f.denominator / gcd);
        }

        template<typename Numerator, typename Denominator>
        [[nodiscard]] constexpr auto reduce(fraction<Numerator, Denominator> const& f)
        {
            return reduce_from_gcd(f, gcd(f));
        }
    }
}

#endif  // CNL_IMPL_FRACTION_REDUCE_H
