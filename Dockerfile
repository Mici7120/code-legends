FROM gcc:4.9

RUN mkdir /code
WORKDIR /code
COPY Test.cpp /code
RUN g++ -o Test main.cpp avatar.cpp box.cpp ejercito.cpp tablero.cpp juegoBase.cpp menu.cpp
CMD ["./Test"]
