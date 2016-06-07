/*
  Serial Interrupt
 * Test example is for use with arduino MEGA
 * This example show how to make a serial
 * comunication with interrupts because serialEvent();
 * is not interrupt driven.
  
  Ricardo Mena C
  ricardo@crcibernetica.com
  http://crcibernetica.com

  License
  **********************************************************************************
  This program is free software; you can redistribute it 
  and/or modify it under the terms of the GNU General    
  Public License as published by the Free Software       
  Foundation; either version 3 of the License, or        
  (at your option) any later version.                    
                                                        
  This program is distributed in the hope that it will   
  be useful, but WITHOUT ANY WARRANTY; without even the  
  implied warranty of MERCHANTABILITY or FITNESS FOR A   
  PARTICULAR PURPOSE. See the GNU General Public        
  License for more details.                              
                                                        
  You should have received a copy of the GNU General    
  Public License along with this program.
  If not, see <http://www.gnu.org/licenses/>.
                                                        
  Licence can be viewed at                               
  http://www.gnu.org/licenses/gpl-3.0.txt

  Please maintain this license information along with authorship
  and copyright notices in any redistribution of this code
  **********************************************************************************

*/

const byte interruptPin = 19;//In arduino MEGA RX 19. TX 18
String msg = "";//Incomming message

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);//Serial Monitor
  Serial1.begin(115200);//Incomming serial messages
  attachInterrupt(digitalPinToInterrupt(interruptPin), serial_read, HIGH);
}//end setup

void loop() {
  // put your main code here, to run repeatedly:
}//end loop

void serial_read(){
  char _bite;
  sei();//Disable hardware interrupts for a moment
  while(Serial1.available()>0){
    delay(1);//Do not delet this delay
    if(Serial1.available()>0){
      _bite = (char)Serial1.read();
      msg += _bite;
      if(_bite == '\n'){
        Serial.print(msg);//Do what you whant whit your message
        msg = "";//Clean message for new one
        break;
      }//end if
    }//end if
  }//end while
  cli();//reenabling hardware interrupts
}//end serial_read
