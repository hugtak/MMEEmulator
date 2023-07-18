#ifndef GENERAL_FUNC_H
#define GENERAL_FUNC_H
/*Includes*/
#include <errno.h>
#include "sbcap.h"

#define SOCKETERROR 1
#define CONNECTERROR 2
#define RECVERROR 3
#define FILEERROR 4
#define ALLOCERROR 5
#define SENDERROR 6
#define SELECTERROR 7
#define FGETSERROR 8
#define SCANFERROR 9

/*Functions*/
void printBorder();
class NonASN1Exception {
private:
    const char *message;	/* can contain C format specifications */
    const char *extra_data;	/* data handled by fmt. specifications (if any) */
    int errcode;
public:
    NonASN1Exception(const char *msg, int code = 0,
	    const char *extd = NULL);
    NonASN1Exception(const NonASN1Exception & that);
    const char *get_message() const;
    const char *get_extra_data() const;
    int get_errcode() const;
};

/* Names of Criticality values */
extern const char *Criticalities[];
extern char *filesDir; /* The directory where input files reside. It is set to the
		 * command line parameter if any and to the directory where
		 * the sample is started, otherwise.
		 */

    
#endif