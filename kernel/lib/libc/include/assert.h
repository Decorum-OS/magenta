// Copyright 2016 The Fuchsia Authors
// Copyright (c) 2008 Travis Geiselbrecht
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT

#ifndef __ASSERT_H
#define __ASSERT_H

#include <magenta/compiler.h>
#include <debug.h>

#define ASSERT(x) \
    do { if (unlikely(!(x))) { panic("ASSERT FAILED at (%s:%d): %s\n", __FILE__, __LINE__, #x); } } while (0)
#define ASSERT_MSG(x, msg, msgargs...) \
    do { if (unlikely(!(x))) { panic("ASSERT FAILED at (%s:%d): %s\n" msg "\n", __FILE__, __LINE__, #x, ## msgargs); } } while (0)

#if LK_DEBUGLEVEL > 1
#define DEBUG_ASSERT(x) \
    do { if (unlikely(!(x))) { panic("DEBUG ASSERT FAILED at (%s:%d): %s\n", __FILE__, __LINE__, #x); } } while (0)
#define DEBUG_ASSERT_MSG(x, msg, msgargs...) \
    do { if (unlikely(!(x))) { panic("DEBUG ASSERT FAILED at (%s:%d): %s\n" msg "\n", __FILE__, __LINE__, #x, ## msgargs); } } while (0)
#else
#define DEBUG_ASSERT(x) \
    do { } while(0)
#define DEBUG_ASSERT_MSG(x, msg, msgargs...) \
    do { } while(0)
#endif

#define assert(e) DEBUG_ASSERT(e)

#ifndef __cplusplus
#define static_assert(e) STATIC_ASSERT(e)
#endif

#endif
