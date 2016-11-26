# -*- coding: utf-8 -*-

class Programer(object):
    def __new__(cls, *args, **kwargs):
        print 'Call __new__ methon'
        print args
        return super(Programer, cls).__new__(cls, *args, **kwargs)

    def __init__(self, name, age):
        print 'Call __init__ methon'
        self.name = name
        self.age = age

if __name__ == '__main__':
    programer = Programer('Albert', 25)
    print programer.__dict__