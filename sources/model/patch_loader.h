//          Copyright Jean Pierre Cimalando 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#include <stddef.h>
#include <stdint.h>
class Patch;

class Patch_Loader {
public:
    static bool load_realmajor_patch(const uint8_t *data, size_t length, Patch &pat);
    static bool load_sysex_patch(const uint8_t *data, size_t length, Patch &pat);
    static bool load_patch_file(const char *path, Patch &pat);
};
