/*
 * Copyright (c) 2018-2020, Andreas Kling <andreas@ladybird.org>
 * Copyright (c) 2021, Tobias Christiansen <tobyase@serenityos.org>
 * Copyright (c) 2021-2025, Sam Atkins <sam@ladybird.org>
 * Copyright (c) 2022-2023, MacDue <macdue@dueutil.tech>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "StyleValueList.h"

namespace Web::CSS {

bool StyleValueList::Properties::operator==(Properties const& other) const
{
    return separator == other.separator && values.span() == other.values.span();
}

String StyleValueList::to_string(SerializationMode mode) const
{
    auto separator = ""sv;
    switch (m_properties.separator) {
    case Separator::Space:
        separator = " "sv;
        break;
    case Separator::Comma:
        separator = ", "sv;
        break;
    default:
        VERIFY_NOT_REACHED();
    }

    StringBuilder builder;
    for (size_t i = 0; i < m_properties.values.size(); ++i) {
        builder.append(m_properties.values[i]->to_string(mode));
        if (i != m_properties.values.size() - 1)
            builder.append(separator);
    }
    return MUST(builder.to_string());
}

void StyleValueList::set_style_sheet(GC::Ptr<CSSStyleSheet> style_sheet)
{
    Base::set_style_sheet(style_sheet);
    for (auto& value : m_properties.values)
        const_cast<CSSStyleValue&>(*value).set_style_sheet(style_sheet);
}

}
