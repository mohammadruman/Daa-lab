#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity
{
    int start;
    int end;
};

bool compareActivities(const Activity &a, const Activity &b)
{
    return a.end < b.end;
}

void activitySelection(vector<Activity> &activities)
{
    sort(activities.begin(), activities.end(), compareActivities);

    cout << "Selected activities: ";
    int n = activities.size();
    int i = 0;

    // The first activity always gets selected
    cout << "(" << activities[i].start << ", " << activities[i].end << ") ";

    // Consider the rest of the activities
    for (int j = 1; j < n; j++)
    {
        // If this activity has a start time greater than or equal to the end time
        // of the previously selected activity, then select it
        if (activities[j].start >= activities[i].end)
        {
            cout << "(" << activities[j].start << ", " << activities[j].end << ") ";
            i = j;
        }
    }
}

int main()
{
    int numActivities;
    cout << "Enter the number of activities: ";
    cin >> numActivities;

    vector<Activity> activities(numActivities);

    for (int i = 0; i < numActivities; i++)
    {
        cout << "Enter start time for activity " << i + 1 << ": ";
        cin >> activities[i].start;
        cout << "Enter end time for activity " << i + 1 << ": ";
        cin >> activities[i].end;
    }

    activitySelection(activities);

    return 0;
}
