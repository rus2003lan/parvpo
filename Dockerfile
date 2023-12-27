FROM alpine:latest

RUN	apk update && \
	apk add git g++ libgomp

WORKDIR .

RUN git clone https://github.com/rus2003lan/parvpo.git && \
	cd parvpo1 && \
	g++ -fopenmp lab1.cpp -o lab1

CMD ["./parvpo1/lab1"]

# docker build --no-cache -t my-alpine:latest .