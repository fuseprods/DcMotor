/* DcMotor.cpp- Library for control of dc motor.
Created by J.Campos for Loleando.com, December 21, 2012
www.loleando.com
Released for personal project
*/

/* DcMotor.cpp- Libreria para el control de un motor DC.
Creada por J.Campos para Loleando.com, 21 Diciembre de 2012
www.loleando.com
Desarrollada para proyecto personal
*/

#include "DcMotor.h"
#include "Arduino.h"

DcMotor::DcMotor (int pinVelocidad, int pin1, int pin2) {	//Indicamos los pines a utilizar.

	_pin1 = pin1;	//Pin 1 de la lógica del puente H.
	_pin2 = pin2;	//Pin 2 de la lógica del puente H.
	_pinVelocidad = pinVelocidad;	//Pin enable. Debe utilizarse un pin con PWM.

	//Declaramos los tres pines como salidas (OUTPUT).
	pinMode(_pin1, OUTPUT);
	pinMode(_pin2, OUTPUT);
	pinMode(_pinVelocidad, OUTPUT);

	}

void DcMotor::avanzar(int velocidad) {	//Función para que el motor avance

	if (velocidad >255){		//Si llega un valor superior al utilizado en PWM en la variable velocidad
		velocidad = 255;	//cambiamos su valor por el máximo permitido (255).
	}
	digitalWrite(_pin1, HIGH);	//Para avanzar definimos como 1-0 la lógica del puente H.
	digitalWrite(_pin2, LOW);
	analogWrite(_pinVelocidad, velocidad);	//Controlamos la velocidad del motor mediante el Enable del puente H
	}					//a través del PWM del Arduino.

void DcMotor::parar() {

	digitalWrite(_pin1, LOW); //Para parar dejamos de mandar se�al usando
	digitalWrite(_pin2, LOW); //la logica 00
	analogWrite(_pinVelocidad, 0); //Desactivamos el pin Enable.

	}

void DcMotor::atras(int velocidad) {
	
	
	if (velocidad >255){
		velocidad = 255; //con esto la velocidad nunca superara al maximo de la placa		
	}
	
	digitalWrite(_pin1, LOW); //para ir al sentido contrario cambiamos la polaridad
	digitalWrite(_pin2, HIGH); //siendo 0-1
	analogWrite(_pinVelocidad, velocidad); //y se manda al pin enable del driver

	}
