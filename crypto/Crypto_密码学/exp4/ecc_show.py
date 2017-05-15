#!/usr/bin/env python
# -*- coding: utf-8 -*-


import math
import random
import string

p = 89
a = -1
b = 0
letters = string.lowercase


# 获取λ
def get_lam(fz, fm):
    lam = 0
    if fz % fm == 0:  # 能整除的直接取余即可
        lam = (fz / fm) % p
    else:  # 分数取余
        i = 1
        while i < p:
            if (p * i + fz) % fm == 0:  # 将分母乘到左边转换成 y = kx + b 形式计算
                lam = ((p * i + fz) / fm) % p
                break
            i += 1

    return lam


# 椭圆曲线上整数点的相加
def point_add(point1, point2):
    if point1 == 'O':
        return point2
    if point2 == 'O':
        return point1
    x1, y1 = point1
    x2, y2 = point2

    if point1 == point2:
        if point1[1] == 0:
            return 'O'
        fz = 3 * x1 * x1 + a
        fm = 2 * y1
        lam = get_lam(fz, fm)
    else:
        if x1 == x2 and y1 + y2 == p:
            return 'O'
        fz = y2 - y1
        fm = x2 - x1
        lam = get_lam(fz, fm)
    x3 = (lam * lam - x1 - x2) % p
    y3 = (lam * (x1 - x3) - y1) % p

    return x3, y3


# 倍点运算，m为点， n为倍数
def multi_point(point, n):
    if n == 1:
        return point
    if n == 2:
        return point_add(point, point)
    if n > 2:
        return point_add(point, multi_point(point, n - 1))


# 获取椭圆曲线有限域上的整数点(不包括'O')
def get_all_points():
    all_points = []

    x = 0
    while x < p:
        y = (x * x * x + a * x + b) % p
        if y == 0:
            all_points.append((x, y))
        elif pow(int(math.sqrt(y)), 2) == y:
            all_points.append((x, int(math.sqrt(y))))
            all_points.append((x, p - int(math.sqrt(y))))
        else:
            i = 1
            while i < p:
                if pow(int(math.sqrt(y + i * p)), 2) == (y + i * p):
                    all_points.append((x, int(math.sqrt(y + i * p) % p)))
                    all_points.append((x, p - int(math.sqrt(y + i * p) % p)))
                    break
                i += 1
        x += 1

    return all_points


# 获取生成元和相应的阶
def get_generator_and_order():
    gen_ord_list = []
    all_points = get_all_points()
    for point in all_points:
        i = 2
        while i <= 2 * math.sqrt(p) + p + 1:  # 进行倍点运算的时候， 每次运算得到的结果都必须是椭圆上的整数点，或者'O'
            result = multi_point(point, i)
            if result == 'O':
                gen_ord_list.append((point, i))
                break
            if result not in all_points:
                break
            i += 1

    return gen_ord_list


# 费马素性检测
def fermat_test(p):
    if p == 1:
        return False
    if p == 2:
        return True
    d = pow(2, p - 1, p)
    if d == 1:
        return True
    return False


def get_key():
    e = (a, b, p)
    gen_ord_list = get_generator_and_order()
    while True:
        gen_ord = random.choice(gen_ord_list)
        if fermat_test(gen_ord[1]):
            break
    g, n = gen_ord
    nb = random.randint(1, n - 1)
    pb = multi_point(g, nb)
    public_key = e, n, g, pb
    private_key = nb

    return public_key, private_key


def ecc_encry(public_key, plaintext):
    ciphertext = []
    e, n, g, pb = public_key
    all_points = get_all_points()
    for letter in plaintext:
        while True:
            pt = random.choice(all_points)
            if pt[0] != 0:  # 若随机选取的点 x = 0 将无法进行计算,得到m。 ((y - b)/x）% p 分子为0.
                break
        k = random.randint(1, n - 1)
        m = letters.index(letter)
        p1 = multi_point(g, k)
        p2 = multi_point(pb, k)
        c = (m * pt[0] + pt[1]) % p
        ciphertext.append((p1, point_add(pt, p2), c))

    return ciphertext


def ecc_decry(private_key, ciphertext):
    plaintext_code = []
    nb = private_key
    for i in ciphertext:
        p1, pt_p2, c = i
        nb_p1 = multi_point(p1, nb)
        re_nb_p1 = (nb_p1[0], p - nb_p1[1])
        pt = point_add(pt_p2, re_nb_p1)
        m = get_lam(c - pt[1], pt[0])  # 原计算为(c - pt[1])/pt[0]) % p，形如((y - b)/x）% p和计算λ的方法相同
        plaintext_code.append(m)
    plaintext = ''.join(letters[i] for i in plaintext_code)
    return plaintext


if __name__ == '__main__':
    all_points = get_all_points()
    gen_ord_list = get_generator_and_order()
    print 'All points:', all_points
    print 'Generator, order:', gen_ord_list

    public_key, private_key = get_key()
    c = ecc_encry(public_key, 'yes')
    print 'Ciphertext:', c
    m = ecc_decry(private_key, c)
    print 'Plaintext:', m
