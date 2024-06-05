#include "conference_programm.h"
#include "processing.h"

#ifndef FILTER_H
#define FILTER_H

conference_programm** filter(conference_programm* array[], int size, bool (*check)(conference_programm* element), int& result_size);

bool check_conference_programm_by_name(conference_programm* element);

bool check_conference_programm_by_duration(conference_programm* element);

#endif