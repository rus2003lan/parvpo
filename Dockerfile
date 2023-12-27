FROM alpine:latest

COPY . .

RUN	apk update && \
	apk add git g++ libgomp

RUN g++ -fopenmp lab1.cpp -o lab1

CMD ["./lab1"]
