#include "processing.h"

#include <cstring>
#include <iostream>

int duration(conference_programm* element)
{
	return (element->finish.hour*60 + element->finish.minute - element->start.hour * 60 - element->start.minute);
}

bool compare_by_duration(conference_programm* a, conference_programm* b) {
    return duration(a) > duration(b);
}

bool compare_by_author_last_name(conference_programm* a, conference_programm* b) {
    int last_name_comparison = strcmp(a->author.last_name, b->author.last_name);
    if (last_name_comparison < 0) {
        return true;
    }
    else if (last_name_comparison > 0) {
        return false;
    }
    else {
        int theme_comparison = strcmp(a->title, b->title);
        if (theme_comparison < 0) {
            return true;
        }
        else {
            return false;
        }
    }
}

// 
void merge(conference_programm* array[], int left, int mid, int right, bool (*compare)(conference_programm*, conference_programm*)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    conference_programm** L = new conference_programm * [n1];
    conference_programm** R = new conference_programm * [n2];

    for (int i = 0; i < n1; ++i)
        L[i] = array[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j])) {
            array[k] = L[i];
            ++i;
        }
        else {
            array[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        array[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        array[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;
}

// 
void merge_sort(conference_programm* array[], int left, int right, bool (*compare)(conference_programm*, conference_programm*)) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(array, left, mid, compare);
        merge_sort(array, mid + 1, right, compare);

        merge(array, left, mid, right, compare);
    }
}

void swap(conference_programm* array[], int i, int j) {
    conference_programm* temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// 

void heapify(conference_programm* array[], int size, int index, bool (*compare)(conference_programm*, conference_programm*)) {
    int largest = index;  
    int left = 2 * index + 1; 
    int right = 2 * index + 2;  


    if (left < size && compare(array[left], array[largest]) == false)
        largest = left;

    if (right < size&& compare(array[right], array[largest]) == false)
        largest = right;

    if (largest != index) {
        swap(array, index, largest);
        heapify(array, size, largest, compare);
    }
}

// 

void heap_sort(conference_programm* array[], int size, bool (*compare)(conference_programm*, conference_programm*)) {
    for (int i = size / 2 - 1; i >= 0; --i)
        heapify(array, size, i, compare);

    for (int i = size - 1; i > 0; --i) {
        swap(array, 0, i);

        heapify(array, i, 0, compare);
    }
}

int process(conference_programm* array[], int size) {

    int max = 0;
    for (int i = 0; i < size; i++) {
        if (duration(array[i]) > max) {
            max = duration(array[i]);
        }
    }

    return max;
}
