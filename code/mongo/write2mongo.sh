#!/bin/bash

# mongoimport --port 27030 -u sa -p Expressin@0618 -d mapdb -c bike_bak  --type=json --file bike.csv
# mongo config
mongoimportPath=/data/wangjian10_baseline/extra_home/wangjian10/mongodb/mongodb-linux-x86_64-rhel62-3.4.17/bin/mongoimport
mongoPath=/data/wangjian10_baseline/extra_home/wangjian10/mongodb/mongodb-linux-x86_64-rhel62-3.4.17/bin/mongo
mongoHost=127.0.0.1
mongoPort=27017
mongoDB=testdb
mongoUser=work
mongoPSW=work
monogoTable=kideducation

mongoimportStr=$mongoimportPath" --host "$mongoHost" --port "$mongoPort" -u "$mongoUser" -p "$mongoPSW" -d "$mongoDB" -c "$monogoTable" --type=json --file "$1
mongocmdStr=$mongoPath" "$mongoHost":"$mongoPort"/"$mongoDB" -u"$mongoUser" -p"$mongoPSW" --eval "
deleteKidedu="db.$monogoTable.drop()"
deletecmd=$mongocmdStr$deleteKidedu

if [ $1 = delete ]
then
	$deletecmd
else
	$mongoimportStr
fi


