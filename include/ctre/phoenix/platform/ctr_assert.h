#ifndef ctr_assert__h_
#define ctr_assert__h_

#include "ctre/phoenix/platform/Platform-pack.h" // assert

#if defined(_DEBUG) || defined(DEBUG)
	#define CTR_DEBUGGING		(1)
#else
	#define CTR_DEBUGGING		(0)
#endif

#define CTR_STOP_DEBUGGER_ON_ASSERT	(0) /* turn this off before deploying the so, otherwise RIO goes into safe mode. */

#define  ctr_assert(cond)																						\
	do{																											\
		if(CTR_DEBUGGING && !(cond)){																			\
			if (CTR_STOP_DEBUGGER_ON_ASSERT) { CTRE_ASSERT(cond); }												\
			printf("ctr_assert : %s : %s : %i\n",#cond,__FILE__,__LINE__);										\
		}																										\
	}while(0)

#endif /* ctr_assert__h_ */

