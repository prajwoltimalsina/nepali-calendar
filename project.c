#include <stdio.h>
#include <stdlib.h>

/**defining the function to finding 1st day of 1st month of the year
 * @param dy 1st day of the 1st month /starting day of year
 * @return d
 */

int get_1st_weekday(int year){        //defining the type of the variable

/**formula to calculate the 1st day of the 1st month*/

  int d;
  d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7+3;
  return d;
}

int main()
{
   system("Color 3F");
   int year,month,day,daysInMonth,weekDay=0,startingDay;
   printf("\nCalendar of 2078:");

   char *months[]={"Baisakh","Jestha","Asar","Shrawan","Bhadra","Asoj","Kartik","Mangsir","Poush","Magh","Falgun","Chaitra"};   //print the name of the month

   /**defining the data type of the array
     * saving the number of days in every month in array
    */
   int monthDay[]={31,31,31,32,31,31,30,29,30,29,30,30};  

   startingDay=get_1st_weekday(year);

   
       /**creating for loop*/

   for(month=0;month<12;month++){

      daysInMonth=monthDay[month];   //defining the type of variable
      printf("\n\n---------------%s-------------------\n",months[month]);
      printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");  //print the days of the week


      for(weekDay=0;weekDay<startingDay;weekDay++)
        printf("     ");

      for(day=1;day<=daysInMonth;day++){
        printf("%5d",day);

        if(++weekDay>6){      // condition to check the last weeek day
            printf("\n");     //creating the new line
            weekDay=0;
        }
        startingDay=weekDay;
      }

   }


}