#!/bin/env bash

#curl -X PUT -H "Content-Type: application/json"  http://localhost:8080/service/sensor/toggle/1
#curl -i -H 'Content-Type: application/json' -X POST -d '{"temperature":32, "pressure":2.3, "wind":12, "timestamp":"2019-05-01T17:00:00.000+0000", "sensor_id":3}' http://localhost:8080/service/register

for hour in $(seq -w 00 23)
do
    for sensor in $(seq 1 10)
    do
        values=$(shuf -i 1-99 --head-count=4)
        tmp=$(sed -n 1p <<< $values)
        prs=$(sed -n 2p <<< $values)
        prss=$(sed -n 3p <<< $values)
        wnd=$(sed -n 4p <<< $values)
        curl -i -H 'Content-Type: application/json' -X POST -d '{"temperature":'"$tmp"', "pressure":'"$prs"'.'"$prss"', "wind":'"$wnd"', "timestamp":"2022-02-20T'"$hour"':00:00.000+0000", "sensor_id":'"$sensor"'}' http://localhost:8080/service/register
    done
done





Comando para prender y apagar un sensor:

curl -X PUT -H "Content-Type: application/json"  http://localhost:8080/service/sensor/update/1


Comando para crear un registro nuevo:

curl -i -H 'Content-Type: application/json' -X POST -d '{"temperature":32, "pressure":2.3, "wind":12, "timestamp":"2019-05-01T17:00:00.000+0000", "sensor_id":3}' http://localhost:8080/service/register

