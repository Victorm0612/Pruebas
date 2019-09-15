#!/usr/bin/env bash
#
# Este script sube datos relativos a temperatura, humedad y velocidad del viento
# a un canal de ThingSpeak.
#
# Author: John Sanabria - john.sanabria@correounivalle.edu.co
# Date: 2019-09-04
#
apiKey="JZV5YEPMU8NEE7M1"
device="dataTweets.txt"

RPiTS_HOME="${HOME}/Escritorio/Proyectos"
PATH=${RPiTS_HOME}:${PATH}
if [ $# -eq 1 ]; then
  device=${1}
fi

if [ ! -f ${RPiTS_HOME}/${device} ]; then
  echo "[subirDatosTS] ${RPiTS_HOME}/${device} no existe"
  exit -1
fi
Likes=$(Script_procesador.py)
RT=$(Script_procesador.py 1)

update=$(curl --silent --request POST --header "X-THINGSPEAKAPIKEY: $apiKey" --data "field1=$Likes&field2=$RT" "http://api.thingspeak.com/update")

if [ ${update} -eq 0 ]; then
  echo "[subirDatosTS] Error al subir datos"
  exit -1
else
  exit 0
fi
