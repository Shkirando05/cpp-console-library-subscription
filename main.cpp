#include "conference_programm.h"
#include <iostream>

using namespace std;

#include "file_reader.h"

int main()
{
    cout << "Laboratory work #8. GIT\n";
    cout << "Variant #2. Conference Programm\n";
    cout << "Author: Dmitry Shkirando\n";
    cout << "Group: 23AI1d\n";
    conference_programm* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        {
            cout << subscriptions[i]->start.hour << ' ';
            cout << subscriptions[i]->start.minute << '\n';
            cout << subscriptions[i]->finish.hour << ' ';
            cout << subscriptions[i]->finish.minute << '\n';
            cout << subscriptions[i]->author.last_name << '\n';
            cout << subscriptions[i]->author.first_name << '\n';
            cout << subscriptions[i]->author.middle_name << '\n';
            cout << subscriptions[i]->title << '\n';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}