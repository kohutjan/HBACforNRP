#include "HBAC.hpp"

using namespace std;

void HBAC::InitRosters(int numberOfRosters)
{
  for (int i = 0; i < numberOfRosters; ++i)
  {
    Roster roster;
    roster.Init(this->schedulingPeriod.startDate, this->schedulingPeriod.endDate,
                this->schedulingPeriod.employees, this->schedulingPeriod.shifts,
                this->schedulingPeriod.dayOfWeekCover,
                this->schedulingPeriod.dateSpecificCover);
    roster.Print();
    this->rosters.push_back(roster);
  }
}

void HBAC::TestRosters()
{
  int index = 0;
  ObjectiveFunction objectiveFunction(this->schedulingPeriod);
  for (auto& roster: rosters)
  {
    int penalty = objectiveFunction.CountPenalty(roster);
    cout << endl;
    cout << endl;
    cout << "Objective function output for roster " << index << ": " << penalty;
    cout << endl;
    cout << endl;
    ++index;
  }

}
