#! /usr/bin/env python
# coding:utf-8

charset = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
           'u', 'v', 'w', 'x', 'y', 'z']

#加密
def encry(path, key):
    key_set = []
    m_set = []
    c_set = []
    m = ''
    c = ''

    f = open(path, 'r')
    f_text = f.readlines()
    f.close()
    for i in f_text:
        m += i
    # print m
    m_tolower = m.lower()
    for i in key:#获取key密钥的字符编码集合
        for j in charset:
            if i == j:
                key_set.append(charset.index(j))
                break
    # print key_set

    for i in m_tolower:#获取m明文的字符编码集合
        for j in charset:
            if i == j:
                m_set.append(charset.index(j))
                break
    # print m_set

    for i in range(len(m_set) / len(key_set) + 1):#获取c_set密文的字符编码集合
        for j in range(len(key_set)):
            if i * len(key_set) + j > len(m_set) - 1:
                break
            c_ele = (m_set[i*len(key_set)+j] + key_set[j]) % 26
            c_set.append(c_ele)
    # print c_set

    for i in c_set:#生成密文c
        c += charset[i]
    # print c

    return c

#解密
def decry(path, key):
    key_set = []
    c_set = []
    m_set = []
    c = ''
    m = ''

    f = open(path, 'r')
    f_text = f.readlines()
    f.close()
    for i in f_text:
        c += i
    # print c

    for i in key:#获取key密钥的字符编码集合
        for j in charset:
            if i == j:
                key_set.append(charset.index(j))
                break
    # print key_set
    for i in c:#获取c密文的字符编码集合
        for j in charset:
            if i == j:
                c_set.append(charset.index(j))
                break
    # print c_set

    for i in range(len(c_set) / len(key_set) + 1):#获取m_set明文的字符编码集合
        for j in range(len(key_set)):
            if i * len(key_set) + j > len(c_set) - 1:
                break
            m_ele = (c_set[i*len(key_set)+j] - key_set[j]) % 26
            m_set.append(m_ele)
    # print m_set

    for i in m_set:#生成明文m
        m += charset[i]
    # print m
    return m

def main():
    print '''
        --------------------------
            <1> for encryption
            <2> for decryption
        --------------------------
         '''

    select = raw_input('Please input 1 or 2: ')
    if select == '1':
        path = raw_input('Please input text file path: ')
        key = raw_input('Plesee input key: ')
        c = encry(path, key)
        f = open(path[:-4] + '_ciphertext.txt', 'w')
        f.write(c)
        f.close()
        # print 'Ciphertext:', c
        print  'Ciphertext file path:', path[:-4] + '_ciphertext.txt'
    elif select == '2':
        path = raw_input('Please input ciphertext file path: ')
        key = raw_input('Please input key: ')
        m = decry(path, key)
        f = open(path[:-4] + '_text.txt', 'w')
        f.write(m)
        f.close()
        # print 'Text:', m
        print 'Text file path:', path[:-4] + '_text.txt'
    else:
        print 'Please input correct select.'

if __name__ == '__main__':
    main()