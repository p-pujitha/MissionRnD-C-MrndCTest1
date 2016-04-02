/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};




int leapyears(int year, int month)
{
	int y = year;
	if (month <= 2)
		y--;

	return y / 4 - y / 100 + y / 400;
}

int get_difference(int date1, int date2, int month1, int month2, int year1, int year2)

{
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int n1 = (year1 * 365) + date1;
	for (int i = 0; i<month1 - 1; i++)
		n1 += monthDays[i];
	n1 += leapyears(year1, month1);

	int n2 = (year2 * 365) + date2;
	for (int i = 0; i<month2 - 1; i++)
		n2 += monthDays[i];
	n2+=leapyears(year2, month2);

	return (n2 - n1);


}


int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
		return -1;
	int arr1[20], i = 0;
	int arr2[20], j = 0;
	
	//int *arr1 = (int *)malloc(sizeof(int) * 20), i = 0;
	//int *arr2 = (int *)malloc(sizeof(int) * 20), j = 0;
	while (date1head != NULL)
	{
		arr1[i] = date1head->data;
		date1head = date1head->next;
		i++;

	}
	while (date2head != NULL)
	{
		arr2[j] = date2head->data;
		date2head = date2head->next;
		j++;

	}
	int date1=0, date2=0, month1=0, month2=0, year1=0, year2=0;
	
	for (int m = 0; m <i; m++)
	{
		if (m <= 1)
			date1 = date1 * 10 + arr1[m];
		if (m >= 2 && m <= 3)
			month1 = month1 * 10 + arr1[m];
		if (m>3)
			year1 = year1 * 10 + arr1[m];
	}
	for (int m = 0; m <= j; m++)
	{
		if (m <= 1)
			date2 = date2 * 10 + arr2[m];
		if (m >= 2 && m <= 3)
			month2 = month2 * 10 + arr2[m];
		if (m>3)
			year2 = year2 * 10 + arr2[m];
	}
	
	int get_dif= get_difference(date1, date2, month1, month2, year1, year2) + 1;
	
	return get_dif + 1;
	

	
}
