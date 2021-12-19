#include "Filter.h"
#include "Utils.h"

bool Check_By_Repair(const PIPE& smth, bool param)
{
    return smth.repair != param;
}
bool Check_By_Number_Of_Workshops(const KS& smth, double param)
{
    return (smth.GetNumbOfWorkWorkshops() / smth.GetNumbOfWorkshops()) * 100 == param;
}

void PipeFilter(unordered_map<int, PIPE>& pipes) {
    if (pipes.size() == 0)
        return;
    cout << "What do you want to do?" << endl
        << "Enter 1 if you want to filter by name." << endl
        << "Enter 2 if you want to filter by repair." << endl;
    switch (Get_Correct_Number(1, 2))
    {
    case 1:
    {
        string name;
        cin >> ws;
        cin.ignore(2000, '\n');
        cout << "Please, enter pipe name: ";
        getline(cin, name);
        vector <int> IDs = Find_By_Filter(pipes, Check_By_Name, name);
        for (auto& id : IDs)
            cout << id << pipes[id] << endl;
        cout << "Do you want delete pipes? Please, enter 1 if yes and 0 if no: ";
        bool number = Get_Correct_Number(0, 1);
        if (number)
            for (auto& id : IDs)
                pipes.erase(id);
        break;
    }
    case 2:
    {
        cout << "Please, enter 0 if pipes don't work and 1 if pipes work: ";
        bool repair = Get_Correct_Number(0, 1);
        vector <int> IDs = Find_By_Filter(pipes, Check_By_Repair, repair);
        for (auto& id : IDs)
            cout << id << pipes[id] << endl;
        cout << "Do you want delete pipes? Please, enter 1 if yes and 0 if no: ";
        bool number = Get_Correct_Number(0, 1);
        if (number)
            for (auto& id : IDs)
                pipes.erase(id);
        break;
    }
    default:
    {
        cout << "Error! Please try again!" << endl;
    }
    }
}

void KSFilter(unordered_map<int, KS>& kss) {
    if (kss.size() == 0)
        return;
    cout << "What do you want to do?" << endl
        << "Enter 1 if you want to filter by name." << endl
        << "Enter 2 if you want to filter by number of workshops." << endl;
    switch (Get_Correct_Number(1, 2))
    {
    case 1:
    {
        string name;
        cin >> ws;
        cout << "Please, enter ks name: ";
        cin.ignore(2000, '\n');
        getline(cin, name);
        vector <int> IDs = Find_By_Filter(kss, Check_By_Name, name);
        for (auto& id : IDs)
            cout << id << kss[id] << endl;
        cout << "Do you want delete kss? Please, enter 1 if yes and 0 if no: ";
        bool number = Get_Correct_Number(0, 1);
        if (number)
            for (auto& id : IDs)
                kss.erase(id);
        break;
    }
    case 2:
    {
        cout << "Please, enter the percentage of unused workshops: ";
        double percent = Get_Correct_Number(0.0, 100.0);
        vector <int> IDs = Find_By_Filter(kss, Check_By_Number_Of_Workshops, percent);
        for (auto& id : IDs)
            cout << id << kss[id] << endl;
        cout << "Do you want delete kss? Please, enter 1 if yes and 0 if no: ";
        bool number = Get_Correct_Number(0, 1);
        if (number)
            for (auto& id : IDs)
                kss.erase(id);
        break;
    }
    default:
    {
        cout << "Error! Please try again!" << endl;
    }
    }
}

