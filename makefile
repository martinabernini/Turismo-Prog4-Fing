# makefile para proyecto
# usar tabulador (no espacios) en la línea de comando 

CPPFLAGS = -g++	-c	-std=c++17

lab	:	DTFecha.o	DTHabitacion.o	DTHostal.o	DTCalificacion.o	DTEmpleado.o	DTHuesped.o	DTReserva.o	DTReservaGrupal.o	DTReservaIndividual.o	DTEstadia.o	calificacion.o	hostal.o	empleado.o	estadia.o	habitacion.o	huesped.o	reloj.o	reserva.o	usuario.o	reservaIndividual.o	reservaGrupal.o	controladorHostal.o	controladorReserva.o	controladorUsuario.o	fabrica.o	main.o
	g++	-o	lab	DTFecha.o	DTHabitacion.o	DTHostal.o	DTCalificacion.o	DTEmpleado.o	DTHuesped.o	DTReserva.o	DTReservaGrupal.o	DTReservaIndividual.o	DTEstadia.o	calificacion.o	hostal.o	empleado.o	estadia.o	habitacion.o	huesped.o	reloj.o	reserva.o	usuario.o	reservaIndividual.o	reservaGrupal.o	controladorHostal.o	controladorReserva.o	controladorUsuario.o	fabrica.o	main.o	

calificacion.o:	src/entidades/calificacion.cpp	include/calificacion.h
	${CPPFLAGS}	src/entidades/calificacion.cpp
DTFecha.o:	src/datatypes/DTFecha.cpp include/DTFecha.h
	${CPPFLAGS} src/datatypes/DTFecha.cpp
DTHabitacion.o: src/datatypes/DTHabitacion.cpp include/DTHabitacion.h
	${CPPFLAGS} src/datatypes/DTHabitacion.cpp
DTHostal.o:	src/datatypes/DTHostal.cpp	include/DTHostal.h
	${CPPFLAGS}	src/datatypes/DTHostal.cpp
DTCalificacion.o:	src/datatypes/DTCalificacion.cpp	include/DTCalificacion.h
	${CPPFLAGS}	src/datatypes/DTCalificacion.cpp
DTEmpleado.o:	src/datatypes/DTEmpleado.cpp	include/DTEmpleado.h
	${CPPFLAGS}	src/datatypes/DTEmpleado.cpp
DTHuesped.o:	src/datatypes/DTHuesped.cpp	include/DTHuesped.h
	${CPPFLAGS}	src/datatypes/DTHuesped.cpp
DTReserva.o:	src/datatypes/DTReserva.cpp	include/DTReserva.h
	${CPPFLAGS}	src/datatypes/DTReserva.cpp
DTReservaGrupal.o:	src/datatypes/DTReservaGrupal.cpp	include/DTReservaGrupal.h
	${CPPFLAGS}	src/datatypes/DTReservaGrupal.cpp
DTReservaIndividual.o:	src/datatypes/DTReservaIndividual.cpp	include/DTReservaIndividual.h
	${CPPFLAGS}	src/datatypes/DTReservaIndividual.cpp
DTEstadia.o:	src/datatypes/DTEstadia.cpp	include/DTEstadia.h
	${CPPFLAGS}	src/datatypes/DTEstadia.cpp
hostal.o: src/entidades/hostal.cpp include/hostal.h
	${CPPFLAGS} src/entidades/hostal.cpp
empleado.o: src/entidades/empleado.cpp include/empleado.h
	${CPPFLAGS} src/entidades/empleado.cpp
estadia.o: src/entidades/estadia.cpp include/estadia.h
	${CPPFLAGS} src/entidades/estadia.cpp
habitacion.o: src/entidades/habitacion.cpp include/habitacion.h
	${CPPFLAGS} src/entidades/habitacion.cpp
huesped.o: src/entidades/huesped.cpp include/huesped.h
	${CPPFLAGS} src/entidades/huesped.cpp
reloj.o: src/entidades/reloj.cpp include/reloj.h
	${CPPFLAGS} src/entidades/reloj.cpp
reserva.o: src/entidades/reserva.cpp include/reserva.h
	${CPPFLAGS} src/entidades/reserva.cpp
usuario.o: src/entidades/usuario.cpp include/usuario.h
	${CPPFLAGS} src/entidades/usuario.cpp
reservaIndividual.o: src/entidades/reservaIndividual.cpp include/reservaIndividual.h
	${CPPFLAGS} src/entidades/reservaIndividual.cpp
reservaGrupal.o: src/entidades/reservaGrupal.cpp include/reservaGrupal.h
	${CPPFLAGS} src/entidades/reservaGrupal.cpp
controladorHostal.o:	src/controladores/controladorHostal.cpp	include/controladorHostal.h
	${CPPFLAGS}	src/controladores/controladorHostal.cpp
controladorReserva.o:	src/controladores/controladorReserva.cpp	include/controladorReserva.h
	${CPPFLAGS}	src/controladores/controladorReserva.cpp
controladorUsuario.o:	src/controladores/controladorUsuario.cpp	include/controladorUsuario.h
	${CPPFLAGS}	src/controladores/controladorUsuario.cpp
fabrica.o:	src/fabrica.cpp	include/fabrica.h
	${CPPFLAGS}	src/fabrica.cpp
main.o:	main.cpp	
	${CPPFLAGS}	main.cpp

clean:
	del	lab.exe	\
		main.o	fabrica.o	controladorHostal.o	controladorReserva.o	controladorUsuario.o	DTFecha.o	DTHabitacion.o	DTHostal.o	DTCalificacion.o	DTEmpleado.o	DTHuesped.o	DTReserva.o	DTReservaGrupal.o	DTReservaIndividual.o	calificacion.o	empleado.o	estadia.o	habitacion.o	hostal.o	huesped.o	reloj.o	reserva.o	usuario.o	DTEstadia.o	reservaGrupal.o	reservaIndividual.o
