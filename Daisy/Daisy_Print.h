#ifndef Daisy_Print_h
#define Daisy_Print_h

#define MAX_OUT_CHARS 128
static char buffer[MAX_OUT_CHARS + 1];

#if ENABLE_DEBUG == 1
#define DEBUG(args...) sprintf(buffer, args); Serial.print(buffer);
#define DEBUGLN(args...) sprintf(buffer, args); Serial.println(buffer);
#else
#define DEBUG(args...)
#define DEBUGLN(args...)
#endif

#if ENABLE_C_PRINT == 1
#define PRINT(args...) sprintf(buffer, args); Serial.print(buffer);
#define PRINTLN(args...) sprintf(buffer, args); Serial.println(buffer);
#else
#define PRINT(args...)
#define PRINTLN(args...)
#endif

#endif
