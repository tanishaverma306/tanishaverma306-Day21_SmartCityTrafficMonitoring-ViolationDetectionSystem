#include <stdio.h>

#define MAX 30

int vehicleID[MAX];
int speed[MAX];
int lane[MAX];
int n;

void inputData();
int countSpeedViolations(int *high, int *low);
int countLaneViolations(int *sevID, int *severity);
int busiestLane(int laneCount[]);
int leastBusyLane(int laneCount[]);
void displayReport();

int main() {

    int highSpeed, lowSpeed;
    int sevID, severity;
    int speedV, laneV;

    inputData();

    speedV = countSpeedViolations(&highSpeed, &lowSpeed);
    laneV = countLaneViolations(&sevID, &severity);

    int laneCount[4] = {0};
    for (int i = 0; i < n; i++) {
        laneCount[lane[i] - 1]++;
    }

    int busy = busiestLane(laneCount);
    int least = leastBusyLane(laneCount);

    printf("\n=== TRAFFIC SUMMARY ===\n");
    printf("Total Vehicles: %d\n", n);
    printf("Speed Violations: %d\n", speedV);
    printf("Highest Speed: %d\n", highSpeed);
    printf("Lowest Speed: %d\n", lowSpeed);
    printf("Lane Violations: %d\n", laneV);
    printf("Most Severe Violation Vehicle: %d\n", sevID);
    printf("Severity Value: %d\n", severity);
    printf("Busiest Lane: %d\n", busy);
    printf("Least Busy Lane: %d\n", least);

    displayReport();

    return 0;
}

void inputData() {

    printf("Enter number of vehicles (max 30): ");
    scanf("%d", &n);

    if (n > MAX) {
        n = MAX;
    }

    for (int i = 0; i < n; i++) {

        printf("\nEnter Vehicle ID: ");
        scanf("%d", &vehicleID[i]);

        do {
            printf("Enter Speed: ");
            scanf("%d", &speed[i]);
        } while (speed[i] <= 0);

        do {
            printf("Enter Lane (1-4): ");
            scanf("%d", &lane[i]);
        } while (lane[i] < 1 || lane[i] > 4);
    }
}

int countSpeedViolations(int *high, int *low) {

    int count = 0;

    *high = speed[0];
    *low = speed[0];

    for (int i = 0; i < n; i++) {

        if (speed[i] > 80) {
            count++;
        }

        if (speed[i] > *high) {
            *high = speed[i];
        }

        if (speed[i] < *low) {
            *low = speed[i];
        }
    }

    return count;
}

int countLaneViolations(int *sevID, int *severity) {

    int count = 0;
    *severity = 0;

    for (int i = 0; i < n; i++) {

        int correctLane = vehicleID[i] % 4;
        if (correctLane == 0) {
            correctLane = 4;
        }

        if (correctLane != lane[i]) {
            count++;

            int diff = correctLane - lane[i];
            if (diff < 0) {
                diff = -diff;
            }

            if (diff > *severity) {
                *severity = diff;
                *sevID = vehicleID[i];
            }
        }
    }

    return count;
}

int busiestLane(int laneCount[]) {

    int maxIndex = 0;

    for (int i = 1; i < 4; i++) {
        if (laneCount[i] > laneCount[maxIndex]) {
            maxIndex = i;
        }
    }

    return maxIndex + 1;
}

int leastBusyLane(int laneCount[]) {

    int minIndex = 0;

    for (int i = 1; i < 4; i++) {
        if (laneCount[i] < laneCount[minIndex]) {
            minIndex = i;
        }
    }

    return minIndex + 1;
}

void displayReport() {

    printf("\n=== VEHICLE REPORT ===\n");
    printf("ID\tSpeed\tLane\tSpeedV\tLaneV\n");

    for (int i = 0; i < n; i++) {

        int spV = 0;
        if (speed[i] > 80) {
            spV = 1;
        }

        int correctLane = vehicleID[i] % 4;
        if (correctLane == 0) {
            correctLane = 4;
        }

        int lnV = 0;
        if (correctLane != lane[i]) {
            lnV = 1;
        }

        printf("%d\t%d\t%d\t%d\t%d\n",
               vehicleID[i], speed[i], lane[i], spV, lnV);
    }
}

