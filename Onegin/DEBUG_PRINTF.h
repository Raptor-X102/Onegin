#ifndef NDEBUG
#define DEBUG_PRINTF(...)  printf(__VA_ARGS__);
#else
#define DEBUG_PRINTF(...);
#endif
