#ifndef CTREXPORT

	#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
			#define CTREXPORT	__declspec(dllexport)
    #elif (defined(__GNUC__) && ((__GNUC__ > 4) || (__GNUC__ == 4) && (__GNUC_MINOR__ > 2))) || __has_attribute(visibility)
    	    #define CTREXPORT     __attribute__((visibility("default")))
    #else
        #define CTREXPORT
    #endif
#endif