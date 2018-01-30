#ifndef Daisy_Print_h
#define Daisy_Print_h

#if ENABLE_DEBUG == 1 || ENABLE_C_PRINT == 1
#define MAX_OUT_CHARS 128
extern char str[MAX_OUT_CHARS + 1];
#endif

#if ENABLE_DEBUG == 1
#define DEBUG(args...) sprintf(str, args); Serial.print(str);
#define DEBUGLN(args...) sprintf(str, args); Serial.println(str);
#else
#define DEBUG(args...)
#define DEBUGLN(args...)
#endif

#if ENABLE_C_PRINT == 1
#define PRINT(args...) sprintf(str, args); Serial.print(str);
#define PRINTLN(args...) sprintf(str, args); Serial.println(str);
#else
#define PRINT(args...)
#define PRINTLN(args...)
#endif

#endif
