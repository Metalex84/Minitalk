# 42 Cursus - MINITALK

![Minitalk Score](/minitalk_score.png)

## Información del proyecto

### Resumen
El propósito de este proyecto es crear un pequeño programa de intercambio de datos utilizando señales UNIX.

### Parte obligatoria

* Crear un programa de comunicación en la forma de un cliente y un servidor.
* El servidor debe lanzarse primero, tras lanzarse debe mostrar su PID.
* El cliente tomará como parámetros el PID del servidor y la string que debería mandarse.
* El cliente debe comunicar la string pasada como parámetro al servidor. Una vez la string se haya recibido, el servidor debe mostrarla.
* El servidor debe poder recibir strings de distintos clientes consecutivamente, sin necesidad de reiniciar.
* La comunicación entre el cliente y el servidor debe hacerse SOLO utilizando las señales UNIX `SIGUSR1` y `SIGUSR2`.

### Instrucciones específicas

* Los ejecutables deben llamarse `client` y `server`.
* Se permite utilizar una variable global por programa (una para el cliente y otra para el servidor).
* FUNCIONES PERMITIDAS:
  * `malloc`
  * `free`
  * `write`
  * `getpid`
  * `signal`
  * `sigemptyset` & `sigaddset`
  * `sigaction`
  * `pause`
  * `kill`
  * `sleep`
  * `usleep`
  * `exit`

## Compilación
```
make
make fclean
make clean
```

## Ejecución
```
./server
./client <server_pid> <string>
```
