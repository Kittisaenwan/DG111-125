#include <math.h>
#include <stdio.h>

int main()
{
    int seconds, hours, minutes, secs;

    // 1) Input: total seconds
    printf("second: ");
    scanf("%d", &seconds);

    // 2) Calculate
    hours = seconds / 3600;
    minutes = (seconds % 3600) / 60;
    secs = seconds % 60;

    // 3) Output format H:MM:SS (minutes and seconds with leading zero)
    printf("Output: %d:%02d:%02d\n", hours, minutes, secs);

    return 0;
}