#include <16F877A.h>   // liber�a del pic
//#include <rs232.h>
#device ADC=8  // bits de conversi�n ADC (convertidor anal�gico digital)
#use delay(crystal=4000000)   // definimos el crystal
#include <lcd.c>   // inclu�mos la librer�a para la lcd
#fuses xt,nowdt

//comunicaci�n rs232    // c6 tx en pic  c7  receptor  
#use rs232(baud=9600, xmit=PIN_c6,rcv=PIN_c7,stream=PIC,parity=N, bits=8)
//#use rs232(baud=9600,xmit=PIN_D0,rcv=PIN_D1,stream=PC, parity=N, bits=8)
#use standard_io(c)

void main(){
enable_interrupts(INT_RDA);
enable_interrupts(GLOBAL);

lcd_init();    // iniciamos la LCD
char c='w';
fprintf(PIC,"%c",c);


            // espera 10 microseg
  lcd_gotoxy(3, 1);                 // ubicamos la posici�n 3,1 en la lcd para escribir el msj 
 lcd_putc("Aldo");
delay_ms(200);

 while(TRUE) {   // LEEMOS LA TEMPERATURA
       lcd_gotoxy(7, 2);           // ubicamos la posici�n 7,2 en la lcd para escribir el msj
    printf("Aldox"); // Escribimos el valor de la variable temperatura (lectura del sensor)
   delay_ms(10); 
       
 }
 
}
