/*****************************************************************************
 * Copyright (c) 2014-2020 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../drawing/ImageId.hpp"
#include "Object.h"

namespace STATION_OBJECT_FLAGS
{
    const uint32_t HAS_PRIMARY_COLOUR = 1 << 0;
    const uint32_t HAS_SECONDARY_COLOUR = 1 << 1;
    const uint32_t IS_TRANSPARENT = 1 << 2;
    const uint32_t NO_PLATFORMS = 1 << 3;
    const uint32_t HAS_SHELTER = (1 << 4);
} // namespace STATION_OBJECT_FLAGS

class StationObject final : public Object
{
public:
    StringId NameStringId{};
    ImageIndex BaseImageId = ImageIndexUndefined;
    ImageIndex ShelterImageId = ImageIndexUndefined;
    uint32_t Flags{};
    int32_t Height{};
    uint8_t ScrollingMode{};

    void ReadJson(IReadObjectContext* context, json_t& root) override;
    void Load() override;
    void Unload() override;

    void DrawPreview(rct_drawpixelinfo* dpi, int32_t width, int32_t height) const override;
};
