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

// ������� ��� ������� ��������
