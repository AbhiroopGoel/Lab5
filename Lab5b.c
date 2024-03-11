#include <stdio.h>

void calculateCombinations(int score, int td, int fg, int safety) {
    if (score == 0) {
        printf("%d TD + %dpt, %d TD + %dpt, %d TD + %dpt, %d TD + %dpt, %d TD + %dpt\n",
               td, 2 * safety, fg, 3 * fg, td, 6 * fg, td, 7 - fg, safety);
        return;
    }

    if (score < 0) {
        return;
    }

    calculateCombinations(score - 6, td + 1, fg, safety); // TD
    calculateCombinations(score - 3, td, fg + 1, safety); // FG
    calculateCombinations(score - 2, td, fg, safety + 1); // Safety
    calculateCombinations(score - 8, td + 1, fg, safety); // TD + 2pt
    calculateCombinations(score - 7, td + 1, fg, safety); // TD + 1pt FG
}

int main() {
    int score;

    do {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        printf("Possible combinations of scoring plays:\n");
        calculateCombinations(score, 0, 0, 0);
    } while (1);

    return 0;
}
         