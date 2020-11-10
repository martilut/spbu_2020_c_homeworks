#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* scanDate(FILE* testFile, char firstSign)
{
    int i = 1;
    char* word = (char*)malloc(10 * sizeof(char));
    if (firstSign >= 48 && firstSign <= 57) {
        word[0] = firstSign;
    } else {
        --i;
    }
    while ((word[i] = (char)fgetc(testFile)) != EOF) {
        if ((word[i] >= 48 && word[i] <= 57) || word[i] == '.') {
            ++i;
        } else {
            if (word[i] == ' ') {
                word[i] = '\0';
                return word;
            } else {
                word[i] = '\0';
                --i;
            }
            ++i;
        }
    }
    word[i] = '\0';
    return word;
}

int getYear(char* date)
{
    int y1 = (date[6] - 48) * 1000;
    int y2 = (date[7] - 48) * 100;
    int y3 = (date[8] - 48) * 10;
    int y4 = (date[9] - 48);
    return y1 + y2 + y3 + y4;
}

int getMonth(char* date)
{
    int m1 = (date[3] - 48) * 10;
    int m2 = (date[4] - 48);
    return m1 + m2;
}

int getDay(char* date)
{
    int d1 = (date[0] - 48) * 10;
    int d2 = (date[1] - 48);
    return d1 + d2;
}

char* getMinDate(char* date, char* minDate)
{
    int dateValues[3] = { getYear(date), getMonth(date), getDay(date) };
    int minDateValues[3] = { getYear(minDate), getMonth(minDate), getDay(minDate) };
    int i = 0;
    while (dateValues[i] == minDateValues[i]) {
        ++i;
    }
    if (dateValues[i] > minDateValues[i]) {
        free(date);
        return minDate;
    } else {
        return date;
    }
}

int main()
{
    FILE* testFileDates;
    testFileDates = fopen("testFileDates.txt", "r");

    char firstSign = 0;
    char* minDate = "99.99.9999";
    while ((firstSign = getc(testFileDates)) != EOF) {
        char* date = scanDate(testFileDates, firstSign);
        if (strlen(date) > 0) {
            minDate = getMinDate(date, minDate);
        }
    }
    printf("%s", minDate);
    free(minDate);
    fclose(testFileDates);
    return 0;
}
