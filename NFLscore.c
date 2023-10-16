#include <stdio.h>
#include <stdlib.h>

int main() {
    int targetScore = 999;

    while (targetScore != 1 && targetScore != 0 && targetScore > 1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &targetScore);
        if (targetScore <= 1) {
            break;
        }
        printf("possible combinations of scoring plays:\n");
        int touchdown;
        int fieldGoal;
        int safety;
        for (touchdown = 0; touchdown <= targetScore / 6; touchdown++) {
            for (fieldGoal = 0; fieldGoal <= targetScore / 3; fieldGoal++) {
                for (safety = 0; safety <= targetScore / 2; safety++) {
                    if (6 * touchdown + 3 * fieldGoal + 2 * safety == targetScore) {
                        printf("%d TD + %d FG + %d Safety\n", touchdown, fieldGoal, safety);
                    }
                }
            }
        }
    }

    return 0;
}
