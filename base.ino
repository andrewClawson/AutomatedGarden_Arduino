// include the library code:
//#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(4, 5, 9, 10, 11, 12);
int Thermistor = A0;
double tempF;
double tempC;
int beta = 4090;
int resistence = 10;

void setup()
{
  pinMode(Thermistor,INPUT);
// set up the LCD's number of columns and rows:
//lcd.begin(16, 2);
//lcd.clear();
  Serial.begin(9600);
  Particle.variable("temperature", &tempF, DOUBLE);
}



void loop()
{
//read thermistor value

double voltage = analogRead(Thermistor)*5.0;
voltage /= 1024.0;
//the calculating formula of temperature
//float tempC = beta /(log((1025.0 * 10 / a - 10) / 10) + beta / 298.0) - 273.0;
tempC = (voltage - .5)*100;
tempF = (tempC * 9.0/5.0) + 32;
//float tempF = 1.8*tempC + 32.0;
// Print a message of "Temp: "to the LCD.
// set the cursor to column 0, line 0
//lcd.setCursor(0, 0);
//lcd.print("Temp: ");
Serial.print("Temp: ");
// Print a centigrade temperature to the LCD.
//lcd.print(tempC);
Serial.print(tempC);
// Print the unit of the centigrade temperature to the LCD.
//lcd.print(" C");
Serial.print(" C");
Serial.println();
// set the cursor to column 0, line 1
// (note: line 1 is the second row, since counting begins with 0):
//lcd.setCursor(0, 1);
//lcd.print("Fahr: ");
// Print a Fahrenheit temperature to the LCD.
//lcd.print(tempF);
// Print the unit of the Fahrenheit temperature to the LCD.
//lcd.print(" F");
delay(5000); //wait for 100 milliseconds
}
