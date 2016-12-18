#! /usr/bin/env python
# -*- coding: utf-8 -*-

import sys
# 获取明文二进制
def get_bin(text):
    text_bin = []
    for i in text:
        if len(hex(ord(i))) == 3:
            i_bin = bin(int('10' + hex(ord(i))[2:], 16))[3:]
        elif len(hex(ord(i))) == 4:
            i_bin = bin(int('1' + hex(ord(i))[2:], 16))[3:]
        text_bin += [j for j in i_bin]
    return text_bin


# IP置换
def ip(text_bin):
    _ip = (
        58, 50, 42, 34, 26, 18, 10, 2,
        60, 52, 44, 36, 28, 20, 12, 4,
        62, 54, 46, 38, 30, 22, 14, 6,
        64, 56, 48, 40, 32, 24, 16, 8,
        57, 49, 41, 33, 25, 17, 9, 1,
        59, 51, 43, 35, 27, 19, 11, 3,
        61, 53, 45, 37, 29, 21, 13, 5,
        63, 55, 47, 39, 31, 23, 15, 7
    )
    text_bin_ip = [text_bin[i - 1] for i in _ip]
    return text_bin_ip


# PC1置换
def pc1(key_bin):
    _pc1 = (
        57, 49, 41, 33, 25, 17, 9,
        1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27,
        19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15,
        7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29,
        21, 13, 5, 28, 20, 12, 4,
    )
    key_bin_pc1 = [key_bin[i - 1] for i in _pc1]
    return key_bin_pc1


# PC2置换
def pc2(key_bin_pc1_mv):
    _pc2 = (
        14, 17, 11, 24, 1, 5,
        3, 28, 15, 6, 21, 10,
        23, 19, 12, 4, 26, 8,
        16, 7, 27, 20, 13, 2,
        41, 52, 31, 37, 47, 55,
        30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34, 53,
        46, 42, 50, 36, 29, 32
    )
    subkey_bin = [key_bin_pc1_mv[i - 1] for i in _pc2]
    return subkey_bin


# 获取子密钥
def get_subkey_bin(key_bin_pc1, count):
    c = key_bin_pc1[:28]
    d = key_bin_pc1[28:]

    if count in (1, 2, 9, 16):
        c = c[1:] + c[:1]
        d = d[1:] + d[:1]
    else:
        c = c[2:] + c[:2]
        d = d[2:] + d[:2]
    key_bin_pc1_mv = c + d
    subkey_bin = pc2(key_bin_pc1_mv)
    return key_bin_pc1_mv, subkey_bin


# f函数
def f(r, subkey_bin):
    _e = (
        32, 1, 2, 3, 4, 5,
        4, 5, 6, 7, 8, 9,
        8, 9, 10, 11, 12, 13,
        12, 13, 14, 15, 16, 17,
        16, 17, 18, 19, 20, 21,
        20, 21, 22, 23, 24, 25,
        24, 25, 26, 27, 28, 29,
        28, 29, 30, 31, 32, 1
    )
    _s1 = (
        (14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7),
        (0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8),
        (4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0),
        (15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13),
    )
    _s2 = (
        (15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10),
        (3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5),
        (0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15),
        (13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9),
    )
    _s3 = (
        (10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8),
        (13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1),
        (13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7),
        (1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12),
    )
    _s4 = (
        (7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15),
        (13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9),
        (10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4),
        (3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14),
    )
    _s5 = (
        (2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9),
        (14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6),
        (4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14),
        (11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3),
    )
    _s6 = (
        (12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11),
        (10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8),
        (9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6),
        (4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13),
    )
    _s7 = (
        (4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1),
        (13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6),
        (1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2),
        (6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12),
    )
    _s8 = (
        (13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7),
        (1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2),
        (7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8),
        (2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11),
    )
    s = (_s1, _s2, _s3, _s4, _s5, _s6, _s7, _s8)
    _p = (
        16, 7, 20, 21,
        29, 12, 28, 17,
        1, 15, 23, 26,
        5, 18, 31, 10,
        2, 8, 24, 14,
        32, 27, 3, 9,
        19, 13, 30, 6,
        22, 11, 4, 25
    )
    r_e = [r[i - 1] for i in _e]
    r_xor = [str(int(r_e[i]) ^ int(subkey_bin[i])) for i in range(len(r_e))]
    i = 0
    r_s = []
    #S盒代换
    while i < 8:
        r_xor_t = r_xor[(i * 6):((i + 1) * 6)]
        row_str = r_xor_t[0] + r_xor_t[5]
        col_str = r_xor_t[1] + r_xor_t[2] + r_xor_t[3] + r_xor_t[4]
        s_t = s[i][int(row_str, 2)][int(col_str, 2)]
        r_s += [j for j in bin(int('1' + hex(s_t)[2:], 16))[3:]]
        i += 1
    r_p = [r_s[i - 1] for i in _p]
    return r_p


# ip逆置换
def ip_1(text_bin_ip):
    _ip_1 = (
        40, 8, 48, 16, 56, 24, 64, 32,
        39, 7, 47, 15, 55, 23, 63, 31,
        38, 6, 46, 14, 54, 22, 62, 30,
        37, 5, 45, 13, 53, 21, 61, 29,
        36, 4, 44, 12, 52, 20, 60, 28,
        35, 3, 43, 11, 51, 19, 59, 27,
        34, 2, 42, 10, 50, 18, 58, 26,
        33, 1, 41, 9, 49, 17, 57, 25
    )
    text_bin_ip_1 = [text_bin_ip[i - 1] for i in _ip_1]
    return text_bin_ip_1


def encry(plaintext_bin, key_bin):
    # plaintext = 'abcdefgh'
    # key = '12345678'
    # plaintext_bin = get_bin(plaintext)
    # key_bin = get_bin(key)
    plaintext_bin_ip = ip(plaintext_bin)
    key_bin_pc1 = pc1(key_bin)
    l = plaintext_bin_ip[:32]
    r = plaintext_bin_ip[32:]
    count = 1
    while count <= 15:
        key_bin_pc1, subkey_bin = get_subkey_bin(key_bin_pc1, count)
        r_f = f(r, subkey_bin)
        r_f_xor = [str(int(l[i]) ^ int(r_f[i])) for i in range(len(r_f))]
        l, r = r, r_f_xor
        count += 1
    key_bin_pc1, subkey_bin = get_subkey_bin(key_bin_pc1, count)
    r_f = f(r, subkey_bin)
    r_f_xor = [str(int(l[i]) ^ int(r_f[i])) for i in range(len(r_f))]
    l, r = r_f_xor, r
    ciphertext_bin_t = l + r
    ciphertext_bin = ip_1(ciphertext_bin_t)
    return ciphertext_bin


# 打印明文二进制矩阵
def print_bin(text_bin):
    for i in range(len(text_bin)):
        sys.stdout.write(text_bin[i])
        if (i + 1) % 8 == 0:
            sys.stdout.write(' ')

def badkey():
    badkey_bin = [
        # 01 01 01 01 01 01 01 01
        [
            '0', '0', '0', '0', '0', '0', '0', '1',
            '0', '0', '0', '0', '0', '0', '0', '1',
            '0', '0', '0', '0', '0', '0', '0', '1',
            '0', '0', '0', '0', '0', '0', '0', '1',
            '0', '0', '0', '0', '0', '0', '0', '1',
            '0', '0', '0', '0', '0', '0', '0', '1',
            '0', '0', '0', '0', '0', '0', '0', '1',
            '0', '0', '0', '0', '0', '0', '0', '1'

        ],
        # 1F 1F 1F 1F 0E 0E 0E 0E
        [
            '0', '0', '0', '1', '1', '1', '1', '1',
            '0', '0', '0', '1', '1', '1', '1', '1',
            '0', '0', '0', '1', '1', '1', '1', '1',
            '0', '0', '0', '1', '1', '1', '1', '1',
            '0', '0', '0', '0', '1', '1', '1', '0',
            '0', '0', '0', '0', '1', '1', '1', '0',
            '0', '0', '0', '0', '1', '1', '1', '0',
            '0', '0', '0', '0', '1', '1', '1', '0'
        ],
        # E0 E0 E0 E0 F1 F1 F1 F1
        [
            '1', '1', '1', '0', '0', '0', '0', '0',
            '1', '1', '1', '0', '0', '0', '0', '0',
            '1', '1', '1', '0', '0', '0', '0', '0',
            '1', '1', '1', '0', '0', '0', '0', '0',
            '1', '1', '1', '1', '0', '0', '0', '1',
            '1', '1', '1', '1', '0', '0', '0', '1',
            '1', '1', '1', '1', '0', '0', '0', '1',
            '1', '1', '1', '1', '0', '0', '0', '1',
        ],
        # FE FE FE FE FE FE FE FE
        [
            '1', '1', '1', '1', '1', '1', '1', '0',
            '1', '1', '1', '1', '1', '1', '1', '0',
            '1', '1', '1', '1', '1', '1', '1', '0',
            '1', '1', '1', '1', '1', '1', '1', '0',
            '1', '1', '1', '1', '1', '1', '1', '0',
            '1', '1', '1', '1', '1', '1', '1', '0',
            '1', '1', '1', '1', '1', '1', '1', '0',
            '1', '1', '1', '1', '1', '1', '1', '0',
        ]
    ]
    badkey_bin_hex = [
        '01 01 01 01 01 01 01 01(Hex)',
        '1F 1F 1F 1F 0E 0E 0E 0E(Hex)',
        'E0 E0 E0 E0 F1 F1 F1 F1(Hex)',
        'FE FE FE FE FE FE FE FE(Hex)'
    ]
    print ' ' * 40 + '+' + '-' * 40 + '+'
    print ' ' * 40 + '|' + ' ' * ((40 - len('DES bad key show')) / 2) + 'DES bad key show' + ' ' * (
    (40 - len('DES bad key show')) / 2) + '|'
    print ' ' * 40 + '|' + ' ' * ((40 - len('1. 01 01 01 01 01 01 01 01')) / 2) + '1. 01 01 01 01 01 01 01 01' + ' ' * (
    (40 - len('1. 01 01 01 01 01 01 01 01')) / 2) + '|'
    print ' ' * 40 + '|' + ' ' * ((40 - len('2. 1F 1F 1F 1F 0E 0E 0E 0E')) / 2) + '2. 1F 1F 1F 1F 0E 0E 0E 0E' + ' ' * (
    (40 - len('2. 1F 1F 1F 1F 0E 0E 0E 0E')) / 2) + '|'
    print ' ' * 40 + '|' + ' ' * ((40 - len('3. E0 E0 E0 E0 F1 F1 F1 F1')) / 2) + '3. E0 E0 E0 E0 F1 F1 F1 F1' + ' ' * (
    (40 - len('3. E0 E0 E0 E0 F1 F1 F1 F1')) / 2) + '|'
    print ' ' * 40 + '|' + ' ' * ((40 - len('4. FE FE FE FE FE FE FE FE')) / 2) + '4. FE FE FE FE FE FE FE FE' + ' ' * (
    (40 - len('4. FE FE FE FE FE FE FE FE')) / 2) + '|'
    print ' ' * 40 + '+' + '-' * 40 + '+'
    select = raw_input('Please input key num: ')
    plaintext = 'abcdefgh'
    plaintext_bin = get_bin(plaintext)
    key_bin = badkey_bin[int(select) - 1]
    ciphertext_bin = encry(plaintext_bin, key_bin)
    ciphertext = ''
    ciphertext_bin2 = encry(ciphertext_bin, key_bin)
    ciphertext2 = ''
    num = 0
    while num * 8 < len(ciphertext_bin):
        byte_bin = ''.join(ciphertext_bin[num * 8:(num + 1) * 8])
        char = chr(int(byte_bin, 2))
        ciphertext += char
        num += 1
    num = 0
    while num * 8 < len(ciphertext_bin2):
        byte_bin = ''.join(ciphertext_bin2[num * 8:(num + 1) * 8])
        char = chr(int(byte_bin, 2))
        ciphertext2 += char
        num += 1
    print '明文: ' + plaintext
    print '弱密钥 :' + badkey_bin_hex[int(select) - 1]
    print 'E(M) :' + ciphertext
    print 'E(E(M)) :' + ciphertext2


def comple():
    plaintext = 'abcdefgh'
    key = '12345678'
    print '明文: ' + plaintext
    print '密钥: ' + key
    print
    plaintext_bin = get_bin(plaintext)
    print '明文(bin): ',
    print_bin(plaintext_bin)
    print
    key_bin = get_bin(key)
    print '密钥(bin): ',
    print_bin(key_bin)
    print
    print
    ciphertext_bin = encry(plaintext_bin, key_bin)
    print 'Ek(M)  (bin): ',
    print_bin(ciphertext_bin)
    print
    plaintext_bin = [str((int(i) + 1) % 2) for i in plaintext_bin]
    key_bin = [str((int(i) + 1) % 2) for i in key_bin]
    ciphertext_bin = encry(plaintext_bin, key_bin)
    print 'Ek`(M`)(bin): ',
    print_bin(ciphertext_bin)
    print

def main():
    while True:
        print ' ' * 40 + '+' + '-' * 40 + '+'
        print ' ' * 40 + '|' + ' ' * ((40 - len('DES show')) / 2) + 'DES show' + ' ' * (
            (40 - len('DES show')) / 2) + '|'
        print ' ' * 40 + '|' + ' ' * ((40 - len('1. bad key show')) / 2) + '1. bad key show' + ' ' * (
            (40 - len('1. bad key show')) / 2) + ' |'
        print ' ' * 40 + '|' + ' ' * ((40 - len('2. complementarity show')) / 2) + '2. complementarity show' + ' ' * (
            (40 - len('2. complementarity show')) / 2) + ' |'
        print ' ' * 40 + '|' + ' ' * ((40 - len('3. exit')) / 2) + '3. exit' + ' ' * (
            (40 - len('3. exit')) / 2) + ' |'
        print ' ' * 40 + '+' + '-' * 40 + '+'

        select = raw_input('Please input select: ')
        if int(select) == 1:
            badkey()
        elif int(select) == 2:
            comple()
        elif int(select) == 3:
            sys.exit(0)
        else:
            print 'Please input right selest.'

if __name__ == '__main__':
    main()