//WAP to add two distances (in km-meter) by passing structure to a function.
#include <stdio.h>
struct Distance {
    int km;
    int m;
};

struct Distance addDistances(struct Distance d1, struct Distance d2) {
    struct Distance sum;
    sum.km = d1.km + d2.km;
    sum.m = d1.m + d2.m;
    if (sum.m >= 1000) {
        sum.km += sum.m / 1000;
        sum.m %= 1000;
    }
    return sum;
}
int main() {
    struct Distance d1, d2, sum;
    printf("My Roll Number is 25155278\n");
    printf("Enter first distance (km m): ");
    scanf("%d %d", &d1.km, &d1.m);
    printf("Enter second distance (km m): ");
    scanf("%d %d", &d2.km, &d2.m);
    sum = addDistances(d1, d2);
    printf("Sum of distances: %d km %d m\n", sum.km, sum.m);
    return 0;
}