#pragma once
#include "basic_type.h"

#include "encrypted_type/encrypted_number.h"
#include "encrypted_type/encrypted_string.h"
#include "encrypted_type/encrypted_string_view.h"

using erptr_t = encrypted_number<rptr_t>;
using ecrptr_t = const_encrypted_number<rptr_t>;
using euint64_t = encrypted_number<uint64_t>;

using estr_t = basic_encrypted_string<char32_t>;
using estrv_t = basic_encrypted_string_view<char32_t>;

using random_t = compile_time::random_t;

#define make_const_encstr make_const_encrypted_string