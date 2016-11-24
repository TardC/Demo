#! /usr/bin/env python
# -*- coding: utf-8 -*-

import requests

def download_image():
    '''demo: 下载图片，文件
    '''
    headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.99 Safari/537.36'}
    url = 'http://image.lxway.com/upload/0/b2/0b2b7eb5ce674e66c6a728e85afae0f3_thumb.jpg'
    response = requests.get(url, headers=headers, stream=True)
    with open('demo.jpg', 'wb') as fd:
        for chunk in response.iter_content(128):
            fd.write(chunk)

def download_image_improved():
    '''demo: 下载图片，文件
    '''
    # 伪造headers信息
    headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/54.0.2840.99 Safari/537.36'}
    # 限定url
    url = 'http://image.lxway.com/upload/0/b2/0b2b7eb5ce674e66c6a728e85afae0f3_thumb.jpg'   
    from contextlib import closing
    with closing(requests.get(url, headers=headers, stream=True)) as response:
        # 打开文件
        with open('demo1.jpg', 'wb') as fd:
            # 每123写入一次
            for chunk in response.iter_content(128):
                fd.write(chunk)
download_image_improved()
