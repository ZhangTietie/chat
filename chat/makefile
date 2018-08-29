ser:main.o tcpsever.o mpthread.o view_register.o  control.o
	g++ -o ser main.o tcpsever.o mpthread.o view_register.o control.o -levent -lpthread -ljson -lmysqlclient -lhiredis -L/usr/lib -g

main.o:main.cpp
	g++ -c main.cpp -g
tcpsever.o:tcpsever.cpp
	g++ -c tcpsever.cpp -g
mpthread.o:mpthread.cpp
	g++ -c mpthread.cpp -g
view_register.o:view_register.cpp
	g++ -c view_register.cpp -g
control.o:control.cpp
	g++ -c control.cpp -g

clean:
	rm -rf *.o ser

