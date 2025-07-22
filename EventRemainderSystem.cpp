#include <bits/stdc++.h>
using namespace std;

/*
 * 1. TiTle
 * 2. Description
 * 3. Date
 * 4. Status(Completed / pending)
 */
class Event
{
    string title;
    string desc;
    string date;
    bool isCompleted;

public:
    Event(string title, string desc, string date)
    {
        this->title = title;
        this->desc = desc;
        this->date = date;
        this->isCompleted = false;
    }

    string getTitle()
    {
        return this->title;
    }

    string getDesc()
    {
        return this->desc;
    }

    string getDate()
    {
        return this->date;
    }

    bool status()
    {
        return this->isCompleted;
    }

    void changeStatus()
    {
        this->isCompleted = !(this->isCompleted);
    }
};

/*
 * 1. Adding events
 * 2. Viewing events
 * 3. Removing events
 * 4. Marking as Complete
 * 5. Veiw Completed events
 * 6. Exit
 */
class remainderManager
{
    vector<Event> list;

public:
    void addEvent()
    {
        string title;
        string desc;
        string date;
        cin.ignore();
        while (true)
        {
            cout << "Enter the title: ";
            getline(cin, title);
            if (title.empty())
                cout << "Title cannot be empty. Please try again.\n";
            else
                break;
        }

        while (true)
        {
            cout << "Enter the description: ";
            getline(cin, desc);
            if (desc.empty())
                cout << "Description cannot be empty. Please try again\n";
            else
                break;
        }

        while (true)
        {
            cout << "Enter Date (DD-MM-YYYY): ";
            getline(cin, date);

            // Regex for DD-MM-YYYY format
            regex datePattern(R"(^(0[1-9]|[12][0-9]|3[01])-(0[1-9]|1[0-2])-(20\d{2})$)");
            if (regex_match(date, datePattern))
            {
                break;
            }
            else
            {
                cout << "Invalid date format. Please enter in DD-MM-YYYY format.\n";
            }
        }
        Event obj(title, desc, date);
        list.push_back(obj);
        cout << "Event Added Successfully\n";
    }

    void viewEvent()
    {
        if (list.size() == 0)
            cout << "No event for veiwing..." << endl;
        for (int i = 0; i < list.size(); i++)
        {
            cout << (i + 1) << ". " << list[i].getTitle() << endl;
            cout << list[i].getDesc() << endl;
            cout << list[i].getDate() << endl;
            cout << "Status: " << (list[i].status() ? "Completed" : "Pending") << "\n";
        }
    }

    void markEventAsDone(int ind)
    {
        if (ind <= 0 || ind > list.size())
            return;
        list[ind - 1].changeStatus();
        cout << "Status Changes Successfully.\n";
        return;
    }

    void viewCompletedEvents()
    {
        if (list.size() == 0)
            return;
        int c = 1;
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i].status())
            {
                cout << c << ". " << list[i].getTitle() << endl;
                cout << list[i].getDesc() << endl;
                cout << list[i].getDate() << endl;
                cout << "Status: " << (list[i].status() ? "Completed" : "Pending") << "\n";
                c++;
            }
        }
    }

    void removeEvent(int ind)
    {
        if (ind <= 0 || ind > list.size())
            return;
        list.erase(list.begin() + ind);
        cout << "Event removed Successfully.\n";
    }
};

int main()
{
    remainderManager rm;

    while (1)
    {
        cout << "*** Welcome to Event Remainder Management system***" << endl;
        cout << "1. Add event" << endl;
        cout << "2. View events" << endl;
        cout << "3. Remove Event" << endl;
        cout << "4. Change status of an Event" << endl;
        cout << "5. View completed Events" << endl;
        cout << "6. Exit" << endl;

        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1:
            rm.addEvent();
            break;
        case 2:
            rm.viewEvent();
            break;
        case 3:
            rm.viewEvent();
            cout << " Enter event number to remove: ";
            int ind;
            cin >> ind;
            rm.removeEvent(ind);
            break;
        case 4:
            rm.viewEvent();
            cout << " Enter event number to change status: ";
            cin >> ind;
            rm.markEventAsDone(ind);
            break;
        case 5:
            rm.viewCompletedEvents();
            break;
        case 6:
            cout << "Thank you for using the system.\n";
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}