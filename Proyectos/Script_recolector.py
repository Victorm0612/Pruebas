#!/usr/bin/env python
import twitter
import json
import os


def auth():
    api = twitter.Api(consumer_key='nklRd58qeeJupeSDXBlzovfEv',
                      consumer_secret='0YpW9LMM3zAo79U73xkBpoQY8L3q8k216dEbx0NttOBHtSqpEO',
                      access_token_key='334075465-nlD6kxItb1BbepuZAQsODMDqslKfzGIPxdhRr7F4',
                      access_token_secret='QskJ1toUGzGjgKHV1bBKTLkjcpvR3AFf6BYGO98tneyp3')
    return api


def get_msg():
    api = auth()
    response = api.GetSearch(term='Uribe', count=1, result_type="recent", since='2019-09-13', return_json=True)
    with open('dataTweets.txt', 'w') as outfile:
        json.dump(response, outfile)


def get_st():
    api = auth()
    request = api.GetStatus(status_id=1172295209536954368)
    print(request)


if __name__ == '__main__':
    # get_msg()
    get_st()
