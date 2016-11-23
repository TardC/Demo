#!/usr/bin/python
# -*- coding: UTF-8 -*-

import MySQLdb

# 打开数据库连接
db = MySQLdb.connect('domain', 'password', 'password', 'database')

# 使用cursor()方法获取操作游标
cursor = db.cursor()

# 使用execute方法执行SQL语句
# cursor.execute('SELECT VERSION()')
# cursor.execute('DROP TABLE IF EXISTS test')INTO
#创建数据表SQL语句
sql = ''

try:
    cursor.execute(sql)
    db.commit()
    # print sql
    # print 'seccess'
except:
    db.rollback()
    # print sql
    # print 'fail'
# 使用 fetchone() 方法获取一条数据库。
# data = cursor.fetchone()
# data = cursor.fetchall()
# print data
# print "Database version : %s " % data

# 关闭数据库连接
db.close()