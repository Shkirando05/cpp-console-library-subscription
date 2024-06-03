#ifndef BOOK_SUBSCRIPTION_H
#define BOOK_SUBSCRIPTION_H

#include "constants.h"

struct Time
{
    int hour;
    int minute;
};

struct person
{
    char first_name[MAX_STRING_SIZE];
    char middle_name[MAX_STRING_SIZE];
    char last_name[MAX_STRING_SIZE];
};

struct book_subscription
{
    Time start;
    Time finish;
    person author;
    char title[MAX_STRING_SIZE];
};

#endif