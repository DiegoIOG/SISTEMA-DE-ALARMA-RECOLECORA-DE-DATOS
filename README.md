# SISTEMA DE ALARMA RECOLECTORA DE DATOS 

Se activan una variedad de sensores en este caso deteccion de fuego, deteccion de temperatura, luz, estos activan una variedad de actuadores en este caso un reele , un LED RGB, que representan las alarmas para una respuesta inmediata , toda la informacion luego es recolectada para su preservacion en un SQL en el cual se pueden analizar los problemas que del sistema o maquina, esta informacion se recolecta mediante python.

## Circuito

![CIRCUITO](https://github.com/user-attachments/assets/eafdf8a8-0513-4a8c-96e6-78bffd4ad6ea)

## Video del funcionamiento


## MICROSOFT SQL SERVER 
<img width="542" height="333" alt="REGISTROS_ENTRADA" src="https://github.com/user-attachments/assets/e5c7f17c-c229-45d8-bfce-18395220014d" />


## Dashboard



## Sensores y actuadores 
- KY-015	 Sensor de temperatura y humedad
- KY-018	 Foto módulo de resistencia
- KY-002	 Modulo interruptor de vibración
- KY-026	 Sensor de llama
- KY-012	 Módulo Buzzer activo
- KY-019	 Módulo relé SV
- KY-009     Led SMD

## Conexiones

Módulo	Pin
- KY-015	Pin 2
- KY-018	A0
- KY-002	Pin 3
- KY-026	Pin 4
- KY-012	Pin 5
- KY-019	Pin 6
- RGB R	 10 
- RGB G	 9
- RGB B	 11

Nota:En mi caso el R y G estan invertidos 

## Librerias
-pyodbc
-pyserial


