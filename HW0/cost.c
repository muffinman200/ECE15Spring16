#include <stdio.h>
#define DOLLARS_PER_GALLON 2.97
int main()
{
  double speed, hours, miles_per_gallon;
  double gallons, cost;
  printf("Enter driving time in hours: ");
  scanf("%lf", &hours);
  printf("Enter average speed in miles per hour: ");
  scanf("%lf", &speed);
  printf("Enter the MPG of your car: ");
  scanf("%lf", &miles_per_gallon);
  gallons = hours * speed / miles_per_gallon;
  cost = gallons * DOLLARS_PER_GALLON;
  printf("Your cost is %lf dollars\n", cost);
  return 0;
}
