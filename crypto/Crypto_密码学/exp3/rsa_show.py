# !/usr/bin/env python
# -*- coding: utf-8 -*-


import random
import string


def fermat_test(p):
    if p == 1:
        return False
    if p == 2:
        return True
    d = pow(2, p - 1, p)
    if d == 1:
        return True
    return False


def get_big_prime():
    while True:
        p = random.randint(pow(2, 511), pow(2, 512) - 1)
        true = fermat_test(p)
        if true:
            return p


def ext_euclid(a, b):
    if b == 0:
        return 1, 0, a
    else:
        x, y, q = ext_euclid(b, a % b)
        x, y = y, (x - (a // b) * y)
        return x, y, q


def get_inverse(a, b):
    x, y, q = ext_euclid(a, b)
    if x < 0:
        x = (x + b) % b
    return x


def get_e(r):
    while True:
        e_list = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53]
        e = random.choice(e_list)
        x, y, q = ext_euclid(r, e)
        if q == 1:
            return e


def get_key():
    p = get_big_prime()
    q = get_big_prime()
    n = p * q
    r = (p - 1) * (q - 1)
    e = get_e(r)
    d = get_inverse(e, r)
    return (n, e), (n, d)


def rsa():
    print '*' * 20, 'Just encry/decry by a letter', '*' * 20
    m = raw_input('Please input plaintext: ')
    letters = string.ascii_lowercase

    public_key, private_key = get_key()
    n, e = public_key
    d = private_key[1]
    ascii_m = [letters.index(i) for i in m]
    ascii_c = [pow(i, e, n) for i in ascii_m]
    ascii_m_decryed = [int(pow(i, d, n)) for i in ascii_c]
    m_decryed = ''.join([letters[i] for i in ascii_m_decryed])
	
    print 'Public key: ' + '(' + ', '.join([str(i) for i in public_key]) + ')'
    print 'Private key: ' + '(' + ', '.join([str(i) for i in private_key]) + ')'
    print 'Coding in ascii: ' + ' '.join([str(i) for i in ascii_m])
    print 'After c≡m^e(mod n): ' + ' '.join([str(i) for i in ascii_c])
    print 'After m≡c^d(mod n): ' + ' '.join([str(i) for i in ascii_m_decryed])
    print 'After decryption: ' + m_decryed


if __name__ == '__main__':
    rsa()
