#ifndef BLAKE2_AVX2_BLAKE2B_H
#define BLAKE2_AVX2_BLAKE2B_H

#include <stddef.h>

#if defined(__cplusplus)
extern "C" {
#endif
	int blake2bavx_512(unsigned char* out, const unsigned char* in, size_t inlen);
	int blake2bavx_256(unsigned char* out, const unsigned char* in, size_t inlen);

#if defined(__cplusplus)
}
#endif

#endif
