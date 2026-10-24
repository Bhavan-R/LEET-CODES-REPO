class Solution {
public:
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int calculateDayOfYear(string date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        
        int totalDays = day;
        for (int i = 0; i < month - 1; ++i) {
            totalDays += days[i];
        }
        return totalDays;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startA = calculateDayOfYear(arriveAlice);
        int endA = calculateDayOfYear(leaveAlice);
        int startB = calculateDayOfYear(arriveBob);
        int endB = calculateDayOfYear(leaveBob);

        int start = max(startA, startB);
        int end = min(endA, endB);

        return max(0, end - start + 1);
    }
};
