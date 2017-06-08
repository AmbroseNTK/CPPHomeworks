#include <iostream>
#include <conio.h>

int MONTHS[] = {31,28,31,30,31,30,31,31,30,31,30,31};
struct Date {
	int dayOfWeek;
	int day;
	int month;
	int year;
};
void dayOfWeekClamp(int &daysOfWeek) {
	if (daysOfWeek == 7)
		daysOfWeek = 0;
	if (daysOfWeek == -1)
		daysOfWeek = 6;
}
void leapYear(int year) {
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		MONTHS[1] = 29;
	else
		MONTHS[1] = 28;
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
	printf("%d/%d/%d\n", now.day, now.month, now.year);
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
	printf("%d/%d/%d\n", now.day, now.month, now.year);
	dayOfWeekClamp(now.dayOfWeek);
}
void process(Date &now, Date d) {
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
void main() {
	
	Date now;
	now.dayOfWeek = 1;
	now.day = 6;
	now.month = 6;
	now.year = 2017;

	printf("The seed: %d - %d/%d/%d\n", now.dayOfWeek, now.day, now.month, now.year);
	Date past;
	printf("Enter day, month, year: ");
	scanf("%d", &past.day);
	scanf("%d", &past.month);
	scanf("%d", &past.year);

	process(now, past);
	printf("%d\n", now.dayOfWeek);
	switch (now.dayOfWeek)
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
	getch();
}