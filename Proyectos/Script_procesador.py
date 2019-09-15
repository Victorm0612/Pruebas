#!/usr/bin/env python
import json
import sys
import os

myCmd = 'python /root/Escritorio/Proyectos/Script_recolector.py > dataTweets.txt'
os.system(myCmd)

with open('dataTweets.txt') as json_file:
    data = json.load(json_file)
    Likes = data['favorite_count']
    RT = data['retweet_count']

    if len(sys.argv) == 1:
        print(Likes)
    else:
        print(RT)