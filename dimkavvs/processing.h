#ifndef PROCESSING_H
#define PROCESSING_H

#include "conference_programm.h"

int duration(conference_programm* element);

bool compare_by_duration(conference_programm* a, conference_programm* b);

bool compare_by_author_last_name(conference_programm* a, conference_programm* b);

void merge(conference_programm* array[], int left, int mid, int right, bool (*compare)(conference_programm*, conference_programm*));

void merge_sort(conference_programm* array[], int left, int right, bool (*compare)(conference_programm*, conference_programm*));

void swap(conference_programm* array[], int i, int j);

void heapify(conference_programm* array[], int size, int index, bool (*compare)(conference_programm*, conference_programm*));

void heap_sort(conference_programm* array[], int size, bool (*compare)(conference_programm*, conference_programm*));

int process(conference_programm* array[], int size);

#endif

