#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Team {
    string name;
    int score;
};

bool compareScore(Team a, Team b) {
    return a.score > b.score; // Descending order
}

int main() {
    vector<Team> teams(8);
    vector<Team> group1, group2, group3;

    // Input 8 team names and scores
    for(int i=0; i<8; i++) {
        cout << "Enter team " << i+1 << " name: ";
        cin >> teams[i].name;

        cout << "Enter score of " << teams[i].name << ": ";
        cin >> teams[i].score;

        cout << endl;
    }

    // Divide into groups based on score
    for(auto &t : teams) {
        if(t.score >= 180)
            group1.push_back(t);
        else
            group2.push_back(t);
    }

    // Sort both groups by highest score
    sort(group1.begin(), group1.end(), compareScore);
    sort(group2.begin(), group2.end(), compareScore);

    // Pick top 2 from each group
    cout << "\nTop 2 teams from Group 1:\n";
    for(int i=0; i<2 && i<group1.size(); i++) {
        cout << group1[i].name << " (" << group1[i].score << ")\n";
        group3.push_back(group1[i]);
    }

    cout << "\nTop 2 teams from Group 2:\n";
    for(int i=0; i<2 && i<group2.size(); i++) {
        cout << group2[i].name << " (" << group2[i].score << ")\n";
        group3.push_back(group2[i]);
    }

    // Now sort group3 to choose top 2 teams
    sort(group3.begin(), group3.end(), compareScore);

    cout << "\nFinal Top 2 Teams (From Group 3):\n";
    for(int i=0; i<2 && i<group3.size(); i++) {
        cout << group3[i].name << " (" << group3[i].score << ")\n";
    }

    return 0;
}