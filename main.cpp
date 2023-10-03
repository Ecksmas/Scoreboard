#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

    // This method checks if an array consists of equal scores.
bool allEqual(int arr[], int n) {
    int firstNum = arr[1];

    for (int i = 1; i < n; ++i) {
        if (arr[i] != firstNum) {
            return false;
        }
    }
    return true;
}

    // I have completed the original and extra task while also making a third scenario where all the scores are equal.

int main() {

    // Uncomment this section and please comment out line 32-34, line 41 and 46-48.
    // Modify this arrays to fill either the criteria of 2 equal scores or 3.
    /*
    int contestant1[3] = {1,1,1},
    contestant2[3] = {1,1,1},
    contestant3[3] = {1,1,1};
     */

    // This array initialisation assumes that the score will be random at every runtime
    int contestantSize = 3,
    contestant1[contestantSize],
    contestant2[contestantSize],
    contestant3[contestantSize],
    totalScore[4],
    totalScoreSize = sizeof(totalScore)/sizeof(int),
    maxScore = 0,
    prevMaxScore = 0,
    firstPlace = 0,
    secondPlace = 0;

    // Allows for new random numbers every runtime
    srand(time(0));

    // Fills all 3 arrays with 3 random scores per array between 1-100
    for (int i = 0; i < sizeof(contestant1) / sizeof(int); ++i) {

        contestant1[i] = 1 + rand() % 100;
        contestant2[i] = 1 + rand() % 100;
        contestant3[i] = 1 + rand() % 100;

    }

    // Sums the scores and adds them to the total score array in corresponding order
    totalScore[1] = contestant1[0] + contestant1[1] + contestant1[2];
    totalScore[2] = contestant2[0] + contestant2[1] + contestant2[2];
    totalScore[3] = contestant3[0] + contestant3[1] + contestant3[2];

    // Checks for maxNum and prevMaxNum and assigns the index(contestant) for them
    for (int i = 1; i < totalScoreSize; ++i) {

        if (totalScore[i] >= maxScore) {
            prevMaxScore = maxScore;
            maxScore = totalScore[i];
            secondPlace = firstPlace;
            firstPlace = i;
        }
    }

    // Prints the individual contestants score
    cout << "\n\tThe contestants points are:\n"
         << "\n\tContestant 1:\t" << totalScore[1]
         << "\n\tContestant 2:\t" << totalScore[2]
         << "\n\tContestant 3:\t" << totalScore[3];

    // Logic to check for 3 different outcomes: All 3 win, 2 win or 1 win.
    if(allEqual(totalScore, totalScoreSize)) {
        cout << "\n\n\tImpossible... all of the contestants scored equally, a fight to the death will decide the victor!\n\n";
    } else if (maxScore == prevMaxScore) {
        cout << "\n\n\tThe contestants " << secondPlace << " and " << firstPlace << " have won the competition by achieving an equal score.\n\n";
    } else {
        cout << "\n\n\tContestant " << firstPlace << " has won the competition.\n\n";
    }

}
