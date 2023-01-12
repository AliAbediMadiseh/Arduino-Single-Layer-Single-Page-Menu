# Arduino Single Layer-Single Page Menu

#Connect 2 push buttons as Yes and No buttons into 1 Analog Input pin.
Arduino Single Layer-Single Page Menu With Yes No push buttons

This menu containes 4 items. If "No" button pressed change selection and if "Yes" button pressed show " item<bumber> selected" in LCD.

With lcd.clear(); function lcd will cleared periodly(dependent to delay time).
So in this project don't appears lcd clear periodly.:)
<h3>
For find each button analog values use this code :<br>	
keyvalue = analogRead(A0)       #keys connected to A0 pin <br>
<br>
My Key Values:
<br>Yes = 42
<br>No = 64
<br>Normal = 1023
    
</h3>
	
	#Idea by Ali Abedi Madiseh
	#1.12.2023#
	
	#include <LiquidCrystal_I2C.h>

	LiquidCrystal_I2C lcd (0x27 , 16, 2);

	int buttonst = 0;  //button status
	int btn = A0;
	int buttonvalue;

	int item = 0;

	void setup() {
		lcd.backlight();
		lcd.clear();
		lcd.init();
	}

	
	void loop() {
	
	   buttonvalue = analogRead(A0);

	   selected(buttonst);

	   if(buttonvalue == 64){
		  if(buttonst < 3){
		  buttonst++;
		  delay(400);

		 }
		  else{
		  buttonst = -1;
		  selected(buttonst);
		 }
	   }

	   else if (buttonvalue == 42){
		  yes_selected();
	   }
	}

	void selected(int buttonst){

		lcd.setCursor(1,0);
		lcd.print("item1");

		lcd.setCursor(9,0);
		lcd.print("item2");

		lcd.setCursor(1,1);
		lcd.print("item3");

		lcd.setCursor(9,1);
		lcd.print("item4");



		if (buttonst == 0){
		  lcd.setCursor(8,1);
		  lcd.print(" ");
		  lcd.setCursor(0,0);
		  lcd.print(">");
		}

		if (buttonst == 1){
		  lcd.setCursor(0,0);
		  lcd.print(" ");
		  lcd.setCursor(8,0);
		  lcd.print(">");
		}

		if (buttonst == 2){
		  lcd.setCursor(8,0);
		  lcd.print(" ");
		  lcd.setCursor(0,1);
		  lcd.print(">");
		}

		if (buttonst == 3){
		  lcd.setCursor(0,1);
		  lcd.print(" ");
		  lcd.setCursor(8,1);
		  lcd.print(">");
		}
	}



	void yes_selected(){

		if (buttonst == 0){
		  lcd.clear();
		  lcd.setCursor(0,0);
		  lcd.print("item1 selected");
		  delay(1000);

		  lcd.setCursor(0,0);
		  lcd.print(" ");

		  lcd.setCursor(6,0);
		  lcd.print("   ");

		  lcd.setCursor(6,1);
		  lcd.print("   ");

		  selected(buttonst);

		}

		if (buttonst == 1){
		  lcd.clear();
		  lcd.setCursor(0,0);
		  lcd.print("item2 selected");
		  delay(1000);

		  lcd.setCursor(0,0);
		  lcd.print(" ");

		  lcd.setCursor(6,0);
		  lcd.print("   ");

		  lcd.setCursor(6,1);
		  lcd.print("   ");

		  selected(buttonst);

		}

		if (buttonst == 2){
		  lcd.clear();
		  lcd.setCursor(0,0);
		  lcd.print("item3 selected");
		  delay(1000);

		  lcd.setCursor(0,0);
		  lcd.print(" ");

		  lcd.setCursor(6,0);
		  lcd.print("   ");

		  lcd.setCursor(6,1);
		  lcd.print("   ");

		  selected(buttonst);

		}

		if (buttonst == 3){
		  lcd.clear();
		  lcd.setCursor(0,0);
		  lcd.print("item4 selected");
		  delay(1000);

		  lcd.setCursor(0,0);
		  lcd.print(" ");

		  lcd.setCursor(6,0);
		  lcd.print("   ");

		  lcd.setCursor(6,1);
		  lcd.print("   ");

		  selected(buttonst);

		}
	}
