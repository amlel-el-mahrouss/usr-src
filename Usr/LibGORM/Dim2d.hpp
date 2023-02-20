#ifndef __GORG__DIM2D_HPP__
#define __GORG__DIM2D_HPP__

#include <LibGORM/Core.hpp>

namespace GORM {
    class Dim2d final {
    public:
        Dim2d() = delete;
        Dim2d(const Skoch::UInt& x, const Skoch::UInt& y) : m_X(x), m_Y(y) {}

        Dim2d& operator=(const Dim2d&) = default;
        Dim2d(const Dim2d&) = default;

        Skoch::UInt& X();
        Skoch::UInt& Y();

    private:
        Skoch::UInt m_X{ 0 };
        Skoch::UInt m_Y{ 0 };

    };
}

#endif /* __GORG__DIM2D_HPP__ */
