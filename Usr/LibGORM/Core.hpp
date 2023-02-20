/*
 *	========================================================
 *
 *	GORM
 * 	Date Added: 08/01/2023
 * 	Copyright SKOCH Computer Division, all rights reserved.
 *
 * 	========================================================
 */
#pragma once

#include <Gorm/Ref.hpp>
#include <Gorm/Array.hpp>
#include <Gorm/String.hpp>
#include <Gorm/Foundation.hpp>

namespace GORM {
    template <typename... T>
    class GAction;
    
    class GString;
    class GNumber;
    class GVector2;
    class GBoolean;

    class GBoolean {
    private:
        explicit GBoolean() : m_Value(false) {}

        Skoch::Boolean m_Value;

        friend class Form;

    public:
        static const GBoolean Construct(Skoch::StringView& sw, Skoch::Boolean value) {
            GBoolean boolean;
            boolean.m_Value = value;

            return boolean;
        }

    };

    template <typename... T>
    class GAction {
        explicit GAction(Skoch::StringView& sw) {
            m_Name = sw;
        }

        Skoch::StringView m_Name;
        void(*m_Action)(T&&... args);

        friend class Form;

    public:
        static const GAction Construct(Skoch::StringView& sw, void(*action)(T&&... args)) {
            GAction actcls{ sw };
            actcls.m_Action = action;

            return actcls;
        }

    };

    class GVector2 {
        explicit GVector2(Skoch::StringView& sw)
            : m_Vec2()
        {}

        Skoch::Array<Skoch::Int, 3> m_Vec2;

        friend class Form;

    public:
        static const GVector2 Construct(Skoch::StringView& sw, Skoch::Array<Skoch::Int, 3>& vec2) {
            GVector2 vec{ sw };
            vec.m_Vec2 = vec2;

            return vec;
        }

    };

    class GNumber {
        Skoch::Int m_Number{ 0 };
        friend class Form;

    public:
        static const GNumber Construct(Skoch::Int& number) {
            GNumber num;
            num.m_Number = number;

            return num;
        }

    };

    class GString {
        explicit GString(Skoch::StringView& content)
        {
            m_Content = new Skoch::StringView();
            *m_Content = content;
        }

        Skoch::StringView* m_Content;

        friend class Form;

    public:
        static const GString Construct(Skoch::StringView& value) {
            GString str{ value };
            return str;
        }

    };
}
