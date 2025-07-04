/*
 * Copyright (c) 2021, Linus Groh <linusg@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Runtime/PrototypeObject.h>

namespace JS {

class JS_API PromisePrototype final : public PrototypeObject<PromisePrototype, Promise> {
    JS_PROTOTYPE_OBJECT(PromisePrototype, Promise, Promise);
    GC_DECLARE_ALLOCATOR(PromisePrototype);

public:
    virtual void initialize(Realm&) override;
    virtual ~PromisePrototype() override = default;

private:
    PromisePrototype(Realm&);

    JS_DECLARE_NATIVE_FUNCTION(then);
    JS_DECLARE_NATIVE_FUNCTION(catch_);
    JS_DECLARE_NATIVE_FUNCTION(finally);
};

}
