#ifndef MAZEGENERATOR_MATH_H
#define MAZEGENERATOR_MATH_H

#include "Point.h"
#include "Rect.h"

namespace myMath {
    /**
     * https://stackoverflow.com/a/306379
     */
    class Math {
    public:
        inline static bool rectOverlap(const myMath::Rect &A, const myMath::Rect &B, int enlargeCheck = 0) {
            bool xOverlap =
                    valueInRange(A.topLeft().x,B.topLeft().x,B.topRight().x + enlargeCheck) ||
                    valueInRange(B.topLeft().x,A.topLeft().x,A.topRight().x + enlargeCheck);

            bool yOverlap =
                    valueInRange(A.topLeft().y,B.topLeft().y,B.bottomLeft().y + enlargeCheck) ||
                    valueInRange(B.topLeft().y,A.topLeft().y,A.bottomLeft().y + enlargeCheck);

            return xOverlap && yOverlap;
        };

    private:
        inline static bool valueInRange(int value, int min, int max) {
            return (value >= min) && (value <= max);
        };
    };
}

#endif
