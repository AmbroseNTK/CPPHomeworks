#include <iostream>
#include <conio.h>
#include<ctime>

int MONTHS[] = {31,28,31,30,31,30,31,31,30,31,30,31};
struct Date {
	int dayOfWeek;
	int day;
	int month;
	int year;
};
void dayOfWeekClamp(int &daysOfWeek) {
	while (daysOfWeek > 6)
		daysOfWeek -= 7;
	while (daysOfWeek <0)
		daysOfWeek += 7;
	
}
void leapYear(int year) {
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		MONTHS[1] = 29;
	else
		MONTHS[1] = 28;
}
int isLeapYear(int year) {
	leapYear(year);
	if (MONTHS[1] == 29)
		return 1;
	return 0;
}
int afterTheDay(Date point, Date d) {
	if (d.year < point.year)
		return 0;
	if (d.year > point.year)
		return 1;
	if (d.month < point.month)
		return 0;
	if (d.month > point.month)
		return 1;
	if (d.day < point.day)
		return 0;
	if (d.day > point.day)
		return 1;
	return -1;
}
void addADay(Date &now) {
	now.dayOfWeek++;
	now.day++;
	if (now.day > MONTHS[now.month - 1]) {
		now.day = 1;
		now.month++;
		if (now.month > 12) {
			now.month = 1;
			now.year++;
			leapYear(now.year);
		}
	}
	dayOfWeekClamp(now.dayOfWeek);
}
void subtractADay(Date &now) {
	now.dayOfWeek--;
	now.day--;
	if (now.day == 0) {
		now.month--;
		if (now.month == 0) {
			now.month = 12;
			now.year--;
			leapYear(now.year);
		}
		now.day = MONTHS[now.month-1];
	}
	dayOfWeekClamp(now.dayOfWeek);
}
Date Feb28;

void addAYear(Date &now) {
	now.dayOfWeek++;
	if ((afterTheDay(now, Feb28) == 0 && isLeapYear(now.year + 1)==1)||(afterTheDay(now, Feb28) == 1 && isLeapYear(now.year)==1))
		now.dayOfWeek++;
	now.year++;
	Feb28.year = now.year;
}
void subtractAYear(Date &now) {
	now.dayOfWeek--;
	if ((afterTheDay(now, Feb28) == 0 && isLeapYear(now.year)==1)||(afterTheDay(now,Feb28)==1 && isLeapYear(now.year)==1))
		now.dayOfWeek--;
	now.year--;
	Feb28.year = now.year;
}
void processOnDay(Date &now, Date d) {
	leapYear(now.year);
	while (afterTheDay(now, d) != -1) {
		if (afterTheDay(now, d) == 1) {
			addADay(now);
		}
		if (afterTheDay(now, d) == 0) {
			subtractADay(now);
			
		}
	}
}
void processOnYear(Date &now, Date d) {
	leapYear(now.year);
	for (int i = now.year; i < d.year; i++)
		addAYear(now);
	for (int i = now.year; i > d.year; i--)
		subtractAYear(now);
	processOnDay(now, d);
}
int checkValidate(Date date) {
	if (date.month > 12 || date.month < 1)
		return 0;
	leapYear(date.year);
	if (date.day<1 || date.day>MONTHS[date.month - 1])
		return 0;
	return 1;
}
int timeSwitch = 0;
int timeTick(float &t) {
	if (timeSwitch == 0) {
		t = clock();
		timeSwitch = 1;
		return 0;
	}
	if (timeSwitch == 1) {
		t = float(clock() - t) / CLOCKS_PER_SEC;
		timeSwitch = 0;
		return 1;
	}
}
void codeToDay(int code) {
	switch (code)
	{
	case 0:
		printf("Monday");
		break;
	case 1:
		printf("Tuesday");
		break;
	case 2:
		printf("Wednesday");
		break;
	case 3:
		printf("Thursday");
		break;
	case 4:
		printf("Friday");
		break;
	case 5:
		printf("Saturday");
		break;
	case 6:
		printf("Sunday");
		break;
	}
}
void main() {

	Date now,now2;
	now.dayOfWeek = 1;
	now.day = 6;
	now.month = 6;
	now.year = 2017;

	now2 = now;

	Feb28.day = 28;
	Feb28.month = 2;
	Feb28.year = now.year;
	printf("The seed: %d - %d/%d/%d\n", now.dayOfWeek, now.day, now.month, now.year);
	Date past;
	printf("Enter day, month, year: \n");
	scanf("%d", &past.day);
	scanf("%d", &past.month);
	scanf("%d", &past.year);
	if (checkValidate(past) == 1) {
		float t = 0;
		printf("Method 1 (Faster): \n");
		timeTick(t);
		processOnYear(now, past);
		timeTick(t);
		printf("Result: ");
		codeToDay(now.dayOfWeek);
		printf("\nFinished - %fs\n", t);

		now = now2;
		printf("\nMethod 2: \n");
		timeTick(t);
		processOnDay(now, past);
		timeTick(t);
		printf("Result: ");
		codeToDay(now.dayOfWeek);
		printf("\nFinished - %fs\n", t);
		
	}
	else
	{
		printf("Wrong date!");
	}
	getch();
}