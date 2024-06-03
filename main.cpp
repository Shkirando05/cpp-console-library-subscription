#include <iostream>
#include <iomanip>

using namespace std;

#include "conference_programm.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
#include "processing.h"

void output(conference_programm* lecture) {
    /********** ����� ������� **********/
    cout << "�����....: ";
    // ����� ������� ������
    cout << setw(2) << setfill('0') << lecture->start.hour << ':';
    cout << setw(2) << setfill('0') << lecture->start.minute << " - ";
    // ����� ������� �����
    cout << setw(2) << setfill('0') << lecture->finish.hour << ':';
    cout << setw(2) << setfill('0') << lecture->finish.minute << '\n';
    /********** ����� ������� **********/
    cout << "������...: ";
    // ����� ������� 
    cout << lecture->author.last_name << " ";
    // ����� ������ ����� ����� ������
    cout << lecture->author.first_name[0] << ". ";
    // ����� ������ ����� �������� ������
    cout << lecture->author.middle_name[0] << ".\n";
    /********** ����� ���� **********/
    cout << "����.....: ";
    cout << lecture->title << '\n';
    cout << "\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ #4. GIT\n";
    cout << "������� #2. ��������� �����������\n";
    cout << "�����: Ivan Grechko\n\n";
    cout << "������: 23��1�\n";

    conference_programm* lectures[MAX_FILE_ROWS_COUNT];
    int size;

    try
    {
        read("data.txt", lectures, size);

        bool (*compare_function)(conference_programm*, conference_programm*) = NULL;
        
        cout << "�������� �������� ���������� ������:\n";
        cout << "1) �� �������� ������������ �������\n";
        cout << "2) �� ����������� ������� ������ �������, � � ������ ������ ������ �� ����������� ���� �������\n";
        cout << "\n������� ����� ���������� ������: ";
        int item;
        cin >> item;
        cout << '\n';

        switch (item)
        {
        case 1:
            compare_function = compare_by_duration;
            break;
        case 2:
            compare_function = compare_by_author_last_name;
            break;
        default:
            throw "������������ ����� ������";
        }

        cout << "�������� ������ ���������� ������:\n";
        cout << "1) ���������� ��������\n";
        cout << "2) ������������� ����������\n";
        cout << "\n������� ����� ���������� ������: ";
        cin >> item;
        cout << '\n';

        switch (item)
        {
        case 1:
            merge_sort(lectures, 0, size - 1, compare_function);
            break;
        case 2:
            heap_sort(lectures, size, compare_function);
            break;
        default:
            throw "������������ ����� ������";
        }
        

        cout << "***** ��������� ����������� *****\n\n";
        for (int i = 0; i < size; i++)
        {
            output(lectures[i]);
        }

        bool (*check_function)(conference_programm*) = NULL;

        cout << "\n�������� ������ ���������� ��� ��������� ������:\n";
        cout << "1) ������� ������� ����� ���������\n";
        cout << "2) ������� ������������� ����� 15 �����\n";
        cout << "\n������� ����� ���������� ������: ";
        cin >> item;
        cout << '\n';

        switch (item)
        {
        case 1:
            check_function = check_conference_programm_by_name; // ����������� � ��������� �� ������� ��������������� �������
            cout << "***** ������� ������� ����� ��������� *****\n\n";
            break;
        case 2:
            check_function = check_conference_programm_by_duration; // ����������� � ��������� �� ������� ��������������� �������
            cout << "***** ������� ������������� ����� 15 ����� *****\n\n";
            break;
        default:
            throw "������������ ����� ������";
        }

        if (check_function)
        {
            int new_size;
            conference_programm** filtered = filter(lectures, size, check_function, new_size);
            for (int i = 0; i < new_size; i++)
            {
                output(filtered[i]);
            }
            delete[] filtered;
        }

        for (int i = 0; i < size; i++)
        {
            delete lectures[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}