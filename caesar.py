# !/usr/bin/env python
# coding: utf-8

#原字符串
str_o = '''
Bml'r rcjj kc wms'pc y kylsyj rpylqjyrmp, ylb
rfyr'q lmr tcpw cddgagclr, rfc djye gl mpa.
'''

#移位后字符串
str_n= ''

#字母表
l = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

#对原字符串遍历移位
for i in str_o:
    for j in l:
        if i == j:
            i = l[(l.index(j) + 2) % 26]      #移位
            break
    str_n += i
    
    
print str_n