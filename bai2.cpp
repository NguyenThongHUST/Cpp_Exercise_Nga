
#include <iostream>
#include <vector>

using namespace std;


int getNumOfPeopleIsStanding(vector<bool> &rowPeoples)
{
    int m_people;
    for (auto i = 1; i < rowPeoples.size(); i++)
    {
        int cnt {0};
        for (auto j = 1; j <= i; j++)
        {
            if(i%j == 0)
                cnt++;
        }
        if(cnt%2 == 0)
        {
            rowPeoples[i] = false;
        }
        else
        {
            rowPeoples[i] = true;
        }
    }

    for (auto i = 1; i < rowPeoples.size(); i++)
    {
        if(rowPeoples[i] == true)
            m_people++;
    }

    return m_people;
}

int main()
{
    vector<bool> rowPeoples {};
    int N{0};
    int numOfPeopleStanding{0};
    cout << "Enter N:";
    cin >> N;
    rowPeoples.resize(N+1);
    numOfPeopleStanding = getNumOfPeopleIsStanding(rowPeoples);
    cout << "Have " << numOfPeopleStanding << " people is standing";

}