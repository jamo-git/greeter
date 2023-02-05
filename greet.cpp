#include <time.h>
#include <iostream>

using namespace std;

#define COLOR_BOLD_BLINK_RED    "\e[1;5;31m"
#define COLOR_BOLD_CYAN         "\e[36m"
#define COLOR_BOLD_YELLOW       "\e[1;33m"
#define COLOR_BOLD_BLUE         "\e[1;34m"
#define COLOR_BOLD_BLINK        "\e[1;5m"
#define COLOR_BOLD              "\e[1m"
#define COLOR_BLINK             "\e[5m"
#define COLOR_YELLOW            "\e[33m"
#define COLOR_OFF               "\e[m"

// 0 - Sun, 6 - Sat
const int THE_DAY = 2; // Thuesday

int main() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[280];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char weekBuf[4];
    char dayBuf[12];
    char dayNroBuf[4];
    strftime(weekBuf, sizeof(weekBuf), "%W",timeinfo);
    strftime(dayBuf, sizeof(dayBuf), "%A",timeinfo);
    strftime(dayNroBuf, sizeof(dayNroBuf), "%w",timeinfo);
    
    printf("\n\n");

    printf("Today is %s%s%s of week %s%s%s ", 
        COLOR_BOLD_CYAN, dayBuf, COLOR_OFF, COLOR_BOLD_BLUE, weekBuf, COLOR_OFF);

    if (atoi(weekBuf) % 2 != 0) {
        if (atoi(dayNroBuf) < 2) {
            printf("and there's only %s%d%s day(s) until thing.\n",
                COLOR_BOLD_BLINK_RED, (THE_DAY - atoi(dayNroBuf)), COLOR_OFF);
        } 
        else if (atoi(dayNroBuf) == 2) {
            printf("%sand today is planning day!%s\n",
                COLOR_BLINK, COLOR_OFF);
        }
        else {
            printf("and there's still %s%d%s days until next thing.\n",
                COLOR_YELLOW, (8 + THE_DAY + (6 - atoi(dayNroBuf))), COLOR_OFF);
        }
    } 
    else {
        printf("and there's still %s%d%s days until next thing.\n",
            COLOR_BOLD_YELLOW, (7 - atoi(dayNroBuf) + THE_DAY), COLOR_OFF);
    }

    switch (atoi(dayNroBuf)) {
        case 1:
            printf("Remember to edit %sWeekly thing%s.\n", COLOR_BOLD, COLOR_OFF);
            break;
        case 3:
            printf("Remember to edit %sWeekly thing%s.\n", COLOR_BOLD, COLOR_OFF);
            break;
        case 4:
            printf("Remember to edit thing, if is to be arranged%s?%s\n", COLOR_BOLD_BLINK, COLOR_OFF);
            break;
        case 5:
            printf("Try to relax for the %sweekend!%s\n", COLOR_BOLD_BLINK, COLOR_OFF);
            break;
    }

    printf("\n\n");

    return 0;
}