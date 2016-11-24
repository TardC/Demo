#! /usr/bin/env python
# -*- coding: utf-8 -*-

import json
import requests
from requests import exceptions

URL = 'https://api.github.com'

def build_uri(endpoint):
    return '/'.join([URL, endpoint])

def better_print(json_str):
    return json.dumps(json.loads(json_str), indent=4)

def request_method():
    response = requests.get(build_uri('users/TardC'))
    print better_print(response.text)

def request_params():
    response = requests.get(build_uri('users'), params={'since': 11})
    print better_print(response.text)
    print response.request.headers
    print response.url

def request_json():
    # response = requests.patch(
    #        build_uri('user'),
    #        auth=('imoocdemo', 'imoocdemo123'), 
    #        json={'name': 'babymooc0', 'email': 'helloworld0@imooc.org'}
    #        )
    response = requests.post(build_uri('user/emails'),
            auth=('imoocdemo', 'imoocdemo123'),
            json=['helloworld0@github.com']
            )
    print better_print(response.text)
    print response.request.headers
    print response.request.body
    print response.status_code

def request_timeout():
    try:
        response = requests.get(build_uri('user/emails'), timeout=10)
        response.raise_for_status()
    except exceptions.Timeout as e:
        print e.message
    except exceptions.HTTPError as e:
        print e.message
    else:
        print response.text
        print response.status_code
        
def hard_requests():
    from requests import Request, Session
    s = Session()
    headers = {'User-Agent': 'fake1.3.4'}
    req = Request('GET', build_uri('user/emails'), auth=('imoocdemo', 'imoocdemo123'), headers=headers)
    prepped = req.prepare()
    print prepped.body
    print prepped.headers

    resp = s.send(prepped, timeout=5)
    print resp.status_code
    print resp.request.headers
    print resp.text

if __name__ == '__main__':
   # request_method()
   # request_params()
   # request_json()
   # request_timeout()
   hard_requests()
