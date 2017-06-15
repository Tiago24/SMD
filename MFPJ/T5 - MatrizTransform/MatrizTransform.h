#ifndef MATRIZTRANSFORM_H
#define MATRIZTRANSFORM_H

#include <cmath>
#include <ostream>
#include <iomanip>
#include <cstdarg>

enum class Axis {X, Y, Z};

class MatrizTransform final
{
    public:
        /** CONSTRUCTORS */
        explicit MatrizTransform () noexcept;
        explicit MatrizTransform (double value ...) noexcept;

        /** SETTERS */
        MatrizTransform& m (int, double) noexcept; // SETS ONE VALUE AT A TIME

        /** GETTERS */
        double m (int) const noexcept; // GETS ONE VALUE AT A TIME

        /** STATIC METHODS */
        static MatrizTransform identity () noexcept;
        static MatrizTransform translate (double, double, double) noexcept;
        static MatrizTransform scale (double, double, double) noexcept;
        static MatrizTransform rotate (Axis, double) noexcept;

        /**
         * TO DO:
         * MATRIZ * MATRIZ;
         * MATRIZ * VETOR / w;
         * ROTAÇÃO SOBRE UM EIXO a;
         * TRS;
         * TRS INVERSA;
         * ROTAÇÃO E ESCALA EM RELAÇÃO A UM PONTO P;
         */

        /** FRIEND FUNCTIONS */
        friend std::ostream& operator << (std::ostream& os, const MatrizTransform& mat) noexcept;

    protected:

    private:
        double a[16];
};

#endif // MATRIZTRANSFORM_H
