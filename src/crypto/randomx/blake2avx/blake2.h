#ifndef BLAKE2_AVX2_BLAKE2_H
#define BLAKE2_AVX2_BLAKE2_H

#if defined(_MSC_VER)
#define FORCE_INLINE __forceinline
#elif defined(__GNUC__)
#define FORCE_INLINE __attribute__((always_inline)) inline
#elif defined(__clang__)
#define FORCE_INLINE __inline__
#else
#define FORCE_INLINE
#endif

#if defined(_MSC_VER)
#define ALIGN(x) __declspec(align(x))
#else
#define ALIGN(x) __attribute__((aligned(x)))
#endif

enum blake2s_constant {
  BLAKE2S_BLOCKBYTES = 64,
  BLAKE2S_OUTBYTES   = 32,
  BLAKE2S_KEYBYTES   = 32,
  BLAKE2S_SALTBYTES  = 8,
  BLAKE2S_PERSONALBYTES = 8
};

enum blake2b_constant {
  BLAKE2B_BLOCKBYTES = 128,
  BLAKE2B_OUTBYTES   = 64,
  BLAKE2B_KEYBYTES   = 64,
  BLAKE2B_SALTBYTES  = 16,
  BLAKE2B_PERSONALBYTES = 16
};

#endif
