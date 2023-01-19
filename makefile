# makefile para proyecto
# usar tabulador (no espacios) en la línea de comando 

CPPFLAGS = -g++	-c	-std=c++17

lab	:	DTFecha.o	DTHabitacion.o	DTHostal.o	DTCalificacion.o	DTEmpleado.o	DTHuesped.o	DTReserva.o	DTReservaGrupal.o	DTReservaIndividual.o	DTEstadia.o	calificacion.o	hostal.o	empleado.o	estadia.o	habitacion.o	huesped.o	reloj.o	reserva.o	usuario.o	reservaIndividual.o	reservaGrupal.o	controladorHostal.o	controladorReserva.o	controladorUsuario.o	fabrica.o	main.o
	g++	-o	lab	DTFecha.o	DTHabitacion.o	DTHostal.o	DTCalificacion.o	DTEmpleado.o	DTHuesped.o	DTReserva.o	DTReservaGrupal.o	DTReservaIndividual.o	DTEstadia.o	calificacion.o	hostal.o	empleado.o	estadia.o	habitacion.o	huesped.o	reloj.o	reserva.o	usuario.o	reservaIndividual.o	reservaGrupal.o	controladorHostal.o	controladorReserva.o	controladorUsuario.o	fabrica.o	main.o	

calificacion.o:	src/calificacion.cpp	include/calificacion.h
	${CPPFLAGS}	src/calificacion.cpp
DTFecha.o:	src/DTFecha.cpp include/DTFecha.h
	${CPPFLAGS} src/DTFecha.cpp
DTHabitacion.o: src/DTHabitacion.cpp include/DTHabitacion.h
	${CPPFLAGS} src/DTHabitacion.cpp
DTHostal.o:	src/DTHostal.cpp	include/DTHostal.h
	${CPPFLAGS}	src/DTHostal.cpp
DTCalificacion.o:	src/DTCalificacion.cpp	include/DTCalificacion.h
	${CPPFLAGS}	src/DTCalificacion.cpp
DTEmpleado.o:	src/DTEmpleado.cpp	include/DTEmpleado.h
	${CPPFLAGS}	src/DTEmpleado.cpp
DTHuesped.o:	src/DTHuesped.cpp	include/DTHuesped.h
	${CPPFLAGS}	src/DTHuesped.cpp
DTReserva.o:	src/DTReserva.cpp	include/DTReserva.h
	${CPPFLAGS}	src/DTReserva.cpp
DTReservaGrupal.o:	src/DTReservaGrupal.cpp	include/DTReservaGrupal.h
	${CPPFLAGS}	src/DTReservaGrupal.cpp
DTReservaIndividual.o:	src/DTReservaIndividual.cpp	include/DTReservaIndividual.h
	${CPPFLAGS}	src/DTReservaIndividual.cpp
DTEstadia.o:	src/DTEstadia.cpp	include/DTEstadia.h
	${CPPFLAGS}	src/DTEstadia.cpp
hostal.o: src/hostal.cpp include/hostal.h
	${CPPFLAGS} src/hostal.cpp
empleado.o: src/empleado.cpp include/empleado.h
	${CPPFLAGS} src/empleado.cpp
estadia.o: src/estadia.cpp include/estadia.h
	${CPPFLAGS} src/estadia.cpp
habitacion.o: src/habitacion.cpp include/habitacion.h
	${CPPFLAGS} src/habitacion.cpp
huesped.o: src/huesped.cpp include/huesped.h
	${CPPFLAGS} src/huesped.cpp
reloj.o: src/reloj.cpp include/reloj.h
	${CPPFLAGS} src/reloj.cpp
reserva.o: src/reserva.cpp include/reserva.h
	${CPPFLAGS} src/reserva.cpp
usuario.o: src/usuario.cpp include/usuario.h
	${CPPFLAGS} src/usuario.cpp
reservaIndividual.o: src/reservaIndividual.cpp include/reservaIndividual.h
	${CPPFLAGS} src/reservaIndividual.cpp
reservaGrupal.o: src/reservaGrupal.cpp include/reservaGrupal.h
	${CPPFLAGS} src/reservaGrupal.cpp
controladorHostal.o:	src/controladorHostal.cpp	include/controladorHostal.h
	${CPPFLAGS}	src/controladorHostal.cpp
controladorReserva.o:	src/controladorReserva.cpp	include/controladorReserva.h
	${CPPFLAGS}	src/controladorReserva.cpp
controladorUsuario.o:	src/controladorUsuario.cpp	include/controladorUsuario.h
	${CPPFLAGS}	src/controladorUsuario.cpp
fabrica.o:	src/fabrica.cpp	include/fabrica.h
	${CPPFLAGS}	src/fabrica.cpp
main.o:	main.cpp	
	${CPPFLAGS}	main.cpp

clean:
	del	lab.exe	\
		main.o	fabrica.o	controladorHostal.o	controladorReserva.o	controladorUsuario.o	DTFecha.o	DTHabitacion.o	DTHostal.o	DTCalificacion.o	DTEmpleado.o	DTHuesped.o	DTReserva.o	DTReservaGrupal.o	DTReservaIndividual.o	calificacion.o	empleado.o	estadia.o	habitacion.o	hostal.o	huesped.o	reloj.o	reserva.o	usuario.o	DTEstadia.o	reservaGrupal.o	reservaIndividual.o
