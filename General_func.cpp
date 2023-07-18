#include "General_func.h"

const char *Criticalities[] = { "reject", "ignore", "notify" };
char *filesDir;


/*
 * Auxiliary function to make output prettier.
 */
void printBorder()
{
    printf("-------------------------------------------------------\n");
}


/*
 * A simple class used to report non-ASN.1/C++ errors (such as a failure to
 * create a socket) to the application. You may use any alternative error
 * handling if you wish.
 */


NonASN1Exception::NonASN1Exception(const char *msg, int code, const char *extd)
{
    message = msg;
    extra_data = extd;
    errcode = code;
}

NonASN1Exception::NonASN1Exception(const NonASN1Exception & that)
{
    message = that.message;
    errcode = that.errcode;
    extra_data = that.extra_data;
}

const char *NonASN1Exception::get_message() const
{
    return message;
}

const char *NonASN1Exception::get_extra_data() const
{
    return extra_data;
}

int NonASN1Exception::get_errcode() const
{
    return errcode;
}