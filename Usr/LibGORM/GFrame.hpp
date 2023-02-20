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

#include <LibGORM/Core.hpp>
#include <LibGORM/Dim2d.hpp>
#include <Gorm/MutableArray.hpp>

namespace GORM {
    using namespace Skoch;

    class GFrame
    {
    public:
        explicit GFrame(GFrame *parent = nullptr) : m_ParentFrame(parent) {}
        ~GFrame() {}

        GFrame& operator=(const GFrame&) = default;
        GFrame(const GFrame&) = default;

        virtual void ProcessVideoEvents()
        {
            if (m_Frames.Count() == 0) return;

            for (int x = 0; x < m_Frames.Count(); ++x) {
                if (!m_Frames[x]->ShouldBeUpdated())
                    continue;

                m_Frames[x]->ProcessVideoEvents();
            }
        }

        virtual void ProcessKeyEvents()
        {
            if (m_Frames.Count() == 0) return;

            for (int x = 0; x < m_Frames.Count(); ++x) {
                if (!m_Frames[x]->ShouldBeUpdated())
                    continue;

                m_Frames[x]->ProcessKeyEvents();
            }
        }

        virtual bool ShouldBeUpdated() { return false; }

    private:
        MutableArray<GFrame*> m_Frames;
        GFrame* m_ParentFrame;

    };
}
